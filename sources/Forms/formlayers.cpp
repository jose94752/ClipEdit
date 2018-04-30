/*
================================================
* File:         formlayers.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage Layers
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QtMath>
#include <QMenu>

#include "formlayers.h"
#include "ui_formlayers.h"
#include "Items/basegraphicitem.h"
#include "Classes/layeritemdelegate.h"
#include "Classes/layeritemmodel.h"

#define Z_DEFAULT       (0.0)
#define Z_INIT          (1.0)
#define Z_INCREMENT     (1.0)

// Constructor, destructor
// -----------------------

FormLayers::FormLayers(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormLayers)
{
    ui->setupUi(this);

    m_zvalue = Z_INIT;
    m_lineSelected = -1;
    m_columnSelected = -1;
    m_scene = NULL;
    m_itemSelected = NULL;

    initForm();
}

FormLayers::~FormLayers()
{
    delete ui;
}

// Init
// ----

void FormLayers::initForm()
{
    // Nil -> @David : Voir pour passer en QTableView afin de définir le model pour avoir les items centrés au milieu ?
    // Par ailleurs j'ai modifié l'appel dans la mainwindow, au lieu de refaire un setScene() sur le clic du bouton je renseigne la scène
    // dans l'initialisation de la mainwindow et j'appelle juste updateLayers() dans le slot associé à ton bouton.
    // J'ai ajouté des headers avec des tailles auto et refait les boutons aussi, tu me diras ce que tu en penses

    // Table properties
    ui->tableWidgetLayers->clear();
    ui->tableWidgetLayers->setRowCount(0);
    ui->tableWidgetLayers->setColumnCount(4);
    ui->tableWidgetLayers->showGrid();
    ui->tableWidgetLayers->setAlternatingRowColors(true);
    ui->tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);

    //ui->tableWidgetLayers->setItemDelegate(new LayerItemDelegate());
    //ui->tableWidgetLayers->setModel(new LayerItemModel());


    // Headers
    QStringList headers;
    headers << tr("Visibility") << tr("Type") << tr("Name") << tr("Z-Value");
    ui->tableWidgetLayers->setHorizontalHeaderLabels(headers);
    ui->tableWidgetLayers->horizontalHeader()->show();
    ui->tableWidgetLayers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connects
    connect (ui->tableWidgetLayers, SIGNAL(cellClicked(int,int)), this, SLOT(actionClicked(int ,int)));
    connect (ui->buttonUp, SIGNAL(clicked(bool)), this, SLOT(actionUp()));
    connect (ui->buttonDown, SIGNAL(clicked(bool)), this, SLOT(actionDown()));
    connect (ui->buttonCopy, SIGNAL(clicked(bool)), this, SLOT(actionCopy()));
    connect (ui->buttonDelete, SIGNAL(clicked(bool)), this, SLOT(actionDelete()));
}

// Slots
// -----

void FormLayers::actionClicked(int line , int col)
{
    qDebug() << "FormLayers::ActionClicked()" << line << col;

    if (!m_scene)
        return;

    m_lineSelected = line;
    m_columnSelected = col;

    m_itemSelected = dynamic_cast<BaseGraphicItem*>(m_scene->items(Qt::AscendingOrder)[m_lineSelected + 1]);

    if (!m_itemSelected)
        return;

    m_scene->clearSelection();
    m_itemSelected->setSelected(true);

    qDebug() << "FormLayers::ActionClicked()" << m_itemSelected;

    // Visibility
    if (m_columnSelected == 0)
    {
        m_itemSelected->setVisible(!m_itemSelected->isVisible());

        updateLayers();
    }
}

void FormLayers::actionUp()
{
    qDebug() << "FormLayers::ActionUp()";

    if (!m_itemSelected)
        return;

    qreal zValue = m_itemSelected->zValue() + Z_INCREMENT;
    m_itemSelected->setZValue(zValue);
    if (zValue > m_zvalue) m_zvalue = zValue;

    updateLayers();
}

void FormLayers::actionDown()
{
    qDebug() << "FormLayers::ActionDown()";

    if (!m_itemSelected)
        return;

    qreal zValue = m_itemSelected->zValue() - Z_INCREMENT;

    if (qFabs(zValue) < Z_INCREMENT) zValue--;

    m_itemSelected->setZValue(zValue);

    updateLayers();
}

void FormLayers::actionCopy()
{
    qDebug() << "FormLayers::ActionAdd()";

    if (!m_itemSelected)
        return;

    // TODO
//    m_scene->addItem(new BaseGraphicItem(m_itemSelected));
//    m_scene->addItem(new QGraphicsItem(m_itemSelected));

    updateLayers();
}

void FormLayers::actionDelete()
{
//    qDebug() << "FormLayers::ActionSupp()";

    if (!m_itemSelected)
        return;

    m_scene->removeItem(m_itemSelected);
    ui->tableWidgetLayers->removeRow(m_lineSelected);

    updateLayers();
}

// Update
// ------

void FormLayers::updateLayers()
{
//    qDebug() << "FormLayers::updateLayers()";

    if (!m_scene)
        return;

    ui->tableWidgetLayers->setRowCount(0);

    foreach (QGraphicsItem* it, m_scene->items(Qt::AscendingOrder))
    {
        BaseGraphicItem* item = dynamic_cast<BaseGraphicItem*>(it);

        if (item)
        {
            int row = ui->tableWidgetLayers->rowCount()+1;
            ui->tableWidgetLayers->setRowCount(row);

            // ZValue
            if (qFabs(item->zValue()) < Z_INCREMENT)
            {
                item->setZValue(m_zvalue++);

                qDebug() << "FormLayers::ShowLayers(): force ZValue\n\t" << item->zValue() << item;
            }

            // 1ere colonne
            if (item->isVisible())
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 0, cellIcon(QIcon(":/icons/icons/eye-icon.png")));
            }
            else
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 0, cellIcon(QIcon(":/icons/icons/eye-transparent-icon.png")));
            }

            // 2eme colonne
            switch (item->type())
            {
                case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/textbox-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/arrow-icon-2.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ChartGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/chart-icon-2.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ClipartGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/clipart-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/picture-icon.png")));
                } break;
               case BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/numbered-bullet-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/screenshot-icon.png")));
                } break;
                default:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/eye-icon.png")));
                } break;
            }

            // 3eme colonne
            static const int nuData = 0;
            if (item->data(nuData).toString().isEmpty())
            {
                QString labelItem;

                switch (item->type())
                {
                    case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                    {
                        labelItem = "TextBox";
                    } break;
                    case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
                    {
                        labelItem = "Arrow";
                    } break;
                    case BaseGraphicItem::CustomTypes::ChartGraphicsItem:
                    {
                        labelItem = "Chart";
                    } break;
                    case BaseGraphicItem::CustomTypes::ClipartGraphicsItem:
                    {
                        labelItem = "Clipart";
                    } break;
                    case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
                    {
                        labelItem = "Picture";
                    } break;
                   case BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem:
                    {
                        labelItem = "NumberedBullet";
                    } break;
                    case BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem:
                    {
                        labelItem = "Screenshot";
                    } break;
                    default:
                    {
                        labelItem = "Other";
                    } break;
                }
                item->setData(nuData, labelItem+" #"+QString::number(row));
            }

            // item->getName())); ???
            ui->tableWidgetLayers->setCellWidget(row-1,2, new QLabel(item->data(nuData).toString()));

            // 4eme colonne
            ui->tableWidgetLayers->setCellWidget(row-1,3,new QLabel(QString::number(item->zValue())));
        }
    }

    // Init select
    m_lineSelected = -1;
    m_columnSelected = -1;

    m_scene->clearSelection();
    //m_itemSelected = NULL;

}

// Getters
// -------

// Setters
// -------

void FormLayers::setScene(QGraphicsScene& scene)
{
    m_scene = &scene;
    updateLayers();
}

QLabel* FormLayers::cellIcon(const QIcon& icon)
{
    QLabel* label = new QLabel(this);
    label->setPixmap(icon.pixmap(QSize(24,24)));
    return label;
}

QLabel* FormLayers::cellIcon(const QString& filename)
{
    QLabel* label = new QLabel(this);
    QIcon*icon = new QIcon(filename);
    label->setPixmap(icon->pixmap(QSize(24,24)));
    return label;
}

