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
    ui->tableWidgetLayers->setColumnWidth(0,40);
    ui->tableWidgetLayers->setColumnWidth(1,40);
    ui->tableWidgetLayers->setColumnWidth(2,300);
    ui->tableWidgetLayers->setColumnWidth(3,30);

    ui->tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);

//    QStringList labels;
//    labels << tr("Filename") << tr("Size");
//    ui->tableWidgetLayers->setHorizontalHeaderLabels(labels);
//    ui->tableWidgetLayers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//    ui->tableWidgetLayers->verticalHeader()->hide();
//    ui->tableWidgetLayers->setShowGrid(false);

    ui->tableWidgetLayers->setContextMenuPolicy(Qt::CustomContextMenu);

    // connect
    connect(ui->tableWidgetLayers, &QTableWidget::cellActivated, this, &FormLayers::cellActivated);
    connect(ui->tableWidgetLayers, &QTableWidget::customContextMenuRequested, this, &FormLayers::contextMenu);

    connect (ui->tableWidgetLayers, SIGNAL(cellClicked(int,int)), this, SLOT(ActionClicked(int ,int)));

    connect (ui->buttonUp, SIGNAL(clicked(bool)), this, SLOT(ActionUp()));
    connect (ui->buttonDown, SIGNAL(clicked(bool)), this, SLOT(ActionDown()));
    connect (ui->buttonAdd, SIGNAL(clicked(bool)), this, SLOT(ActionAdd()));
    connect (ui->buttonSupp, SIGNAL(clicked(bool)), this, SLOT(ActionSupp()));

}

void FormLayers::ActionClicked( int line , int col )
{
    qDebug() << "FormLayers::ActionClicked()" << line << col;

    m_lineselected=line;
    m_columnselected= col;

}

void FormLayers::ActionUp()
{
    qDebug() << "FormLayers::ActionUp()";

    if (!m_scene)
        return;

    qreal zValue = m_scene->items(Qt::AscendingOrder)[m_lineselected]->zValue() + 0.1;
    m_scene->items(Qt::AscendingOrder)[m_lineselected]->setZValue(zValue);

    ShowLayers();
}

void FormLayers::ActionDown()
{
    qDebug() << "FormLayers::ActionDown()";

    if (!m_scene)
        return;

    qreal zValue = m_scene->items(Qt::AscendingOrder)[m_lineselected]->zValue() - 0.1;
    m_scene->items(Qt::AscendingOrder)[m_lineselected]->setZValue(zValue);

    ShowLayers();
}

void FormLayers::ActionAdd()
{
    qDebug() << "FormLayers::ActionAdd()";

    if (!m_scene)
        return;

//    m_scene->addItem(new BaseGraphicItem(m_scene->items(Qt::AscendingOrder)[m_lineselected]));
//    m_scene->addItem(new QGraphicsItem(m_scene->items(Qt::AscendingOrder)[m_lineselected]));

    ShowLayers();
}

void FormLayers::ActionSupp()
{
    qDebug() << "FormLayers::ActionSupp()";

    if (!m_scene)
        return;

    m_scene->removeItem(m_scene->items(Qt::AscendingOrder)[m_lineselected]);
    ui->tableWidgetLayers->removeRow(m_lineselected);

    ShowLayers();
}

void FormLayers::ShowLayers()
{
    qDebug() << "FormLayers::ShowLayers()";

    if (!m_scene)
        return;

//    ui->tableWidgetLayers->clear();
    ui->tableWidgetLayers->setRowCount(0);

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
                case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
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

            ui->tableWidgetLayers->setCellWidget(row-1,2,new QLabel("Label itemx")); // item->getName()));
            ui->tableWidgetLayers->setCellWidget(row-1,3,new QLabel(QString::number(item->zValue())));
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

QLabel *FormLayers::Icon(QString filename)
{
    QLabel * label = new QLabel(this);
    QIcon *icon = new QIcon(filename);
    label->setPixmap(icon->pixmap(QSize(24,24)));
    return label;
}


void FormLayers::cellActivated(int row, int column)
{
    qDebug() << "FormLayers::cellActivated()" << row << column;

//    const QTableWidgetItem *item = filesTable->item(row, 0);
//    openFile(fileNameOfItem(item));
}

void FormLayers::contextMenu(const QPoint &pos)
{
    qDebug() << "FormLayers::contextMenu()" << pos;

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

//void FormLayers::on_buttonUp_clicked()
//{
//    qDebug() << "FormLayers::on_buttonUp_clicked()";

//    if (m_scene->selectedItems().isEmpty())
//        return;

//    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
//    if (!selectedItem)
//        return;

//    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

//    qreal zValue = 0;
//    foreach (QGraphicsItem *item, overlapItems) {
//        if (item->zValue() >= zValue && item->type() >= BaseGraphicItem::CustomTypes::TextBoxGraphicsItem)
//            zValue = item->zValue() + 0.1;
//    }
//    selectedItem->setZValue(zValue);

//    ShowLayers();
//}

//void FormLayers::on_pushDown_clicked()
//{
//    if (m_scene->selectedItems().isEmpty())
//        return;

//    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
//    if (!selectedItem)
//        return;

//    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

//    qreal zValue = 0;
//    foreach (QGraphicsItem *item, overlapItems) {
//        if (item->zValue() <= zValue && item->type() >= BaseGraphicItem::CustomTypes::TextBoxGraphicsItem)
//            zValue = item->zValue() - 0.1;
//    }
//    selectedItem->setZValue(zValue);

//    ShowLayers();
//}

//void FormLayers::on_pushSupp_clicked()
//{
//    if (m_scene->selectedItems().isEmpty())
//        return;

//    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
//    if (!selectedItem)
//        return;

//    // selectedItem->setVisible(false);

//    m_scene->removeItem(selectedItem);

//    ShowLayers();
//}

//void FormLayers::on_pushAdd_clicked()
//{
//    if (m_scene->selectedItems().isEmpty())
//        return;

//    QGraphicsItem *selectedItem = m_scene->selectedItems().first();
//    if (!selectedItem)
//        return;

//    m_scene->addItem(selectedItem);

//    ShowLayers();
//}
