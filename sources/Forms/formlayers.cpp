/*
================================================
* File:         formlayers.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create Layers
================================================
*/

// Includes
// --------

#include <QDebug>

#include "formlayers.h"
#include "ui_formlayers.h"
#include "Items/basegraphicitem.h"

// Constructor, destructor
// -----------------------

FormLayers::FormLayers(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormLayers)
{
    ui->setupUi(this);

    m_scene = NULL;


    initForm();
    ShowLayers();
}

FormLayers::~FormLayers()
{
    delete ui;
}

void FormLayers::initForm()
{
    ui->tableWidgetLayers->clear();
    ui->tableWidgetLayers->setRowCount(0);
    ui->tableWidgetLayers->setColumnCount(4);
    ui->tableWidgetLayers->setColumnWidth(0,30);
    ui->tableWidgetLayers->setColumnWidth(1,30);
    ui->tableWidgetLayers->setColumnWidth(2,60);
    ui->tableWidgetLayers->setColumnWidth(3,60);

    ui->tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << tr("Filename") << tr("Size");
    ui->tableWidgetLayers->setHorizontalHeaderLabels(labels);
    ui->tableWidgetLayers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidgetLayers->verticalHeader()->hide();
    ui->tableWidgetLayers->setShowGrid(false);

    ui->tableWidgetLayers->setContextMenuPolicy(Qt::CustomContextMenu);

    // connect
    connect(ui->tableWidgetLayers, &QTableWidget::cellActivated, this, &FormLayers::cellActivated);
    connect(ui->tableWidgetLayers, &QTableWidget::customContextMenuRequested, this, &FormLayers::contextMenu);

}

void FormLayers::ShowLayers()
{
    qDebug() << "FormLayers::ShowLayers()";

    if (!m_scene)
        return;

    foreach (QGraphicsItem *it, m_scene->items(Qt::AscendingOrder))
    {
        BaseGraphicItem *item = dynamic_cast<BaseGraphicItem*>(it);
        if ( item )
        {
            int row=ui->tableWidgetLayers->rowCount()+1;
            ui->tableWidgetLayers->setRowCount(row);

            // 1ere colonne
            ui->tableWidgetLayers->setCellWidget(row - 1, 0, Icon(QIcon(":/icons/icons/eye.png")));

            // 2eme colonne
            switch (item->type())
            {
                case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/textbox-icon.png")));
                } break;
            case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/arrow-icon-2.png")));
            } break;
            case BaseGraphicItem::CustomTypes::ChartGraphicsItem:
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/chart-icon-2.png")));
            } break;
            case BaseGraphicItem::CustomTypes::ImageGraphicsItem:
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/clipart-icon.png")));
            } break;
            case BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem:
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/numbered-bullet-icon.png")));
            } break;
            case BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem:
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 1, Icon(QIcon(":/icons/icons/screenshot-icon.png")));
            } break;
                default:
                {
                    // Default
                } break;
            }

            // switch type: icon qui va bien
            // ui->tableWidgetLayers->setCellWidget(row-1,1,Icon(item->icon()));

//            ui->tableWidgetLayers->setCellWidget(row-1,1,Icon(item->icon()));
//            ui->tableWidgetLayers->setCellWidget(row-1,2,IconReduced(item->getImage(m_scene,item)));

            ui->tableWidgetLayers->setCellWidget(row-1,3,new QLabel(QString::number(item->zValue())));
            ui->tableWidgetLayers->setCellWidget(row-1,4,new QLabel("Label itemx")); // item->getName()));
        }
    }
}

void FormLayers::updateLayers()
{
    m_zvalue++;
    ShowLayers();
}

// Getters
// -------

// Setters
// -------

void FormLayers::setScene(QGraphicsScene& scene)
{
    m_scene = &scene;
    ShowLayers();
}

QLabel *FormLayers::Icon(QIcon icon)
{
    QLabel * label = new QLabel(this);
    label->setPixmap(icon.pixmap(QSize(24,24)));
    return label;
}


void FormLayers::cellActivated(int row, int /* column */)
{
//    const QTableWidgetItem *item = filesTable->item(row, 0);
//    openFile(fileNameOfItem(item));
}

void FormLayers::contextMenu(const QPoint &pos)
{
//    const QTableWidgetItem *item = filesTable->itemAt(pos);
//    if (!item)
//        return;
//    QMenu menu;
//#ifndef QT_NO_CLIPBOARD
//    QAction *copyAction = menu.addAction("Copy Name");
//#endif
//    QAction *openAction = menu.addAction("Open");
//    QAction *action = menu.exec(filesTable->mapToGlobal(pos));
//    if (!action)
//        return;
//    const QString fileName = fileNameOfItem(item);
//    if (action == openAction)
//        openFile(fileName);
//#ifndef QT_NO_CLIPBOARD
//    else if (action == copyAction)
//        QGuiApplication::clipboard()->setText(QDir::toNativeSeparators(fileName));
//#endif
}

void FormLayers::on_buttonUp_clicked()
{
    qDebug() << "FormLayers::on_buttonUp_clicked()";

    if (m_scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
    if (!selectedItem)
        return;

    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue && item->type() >= BaseGraphicItem::CustomTypes::TextBoxGraphicsItem)
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}

void FormLayers::on_pushDown_clicked()
{
    if (m_scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
    if (!selectedItem)
        return;

    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue && item->type() >= BaseGraphicItem::CustomTypes::TextBoxGraphicsItem)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}

