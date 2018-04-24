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
    ShowLayers();
}

FormLayers::~FormLayers()
{
    delete ui;
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

void FormLayers::ShowLayers()
{
    qDebug() << "FormLayers::ShowLayers()";

    ui->tableWidgetLayers->clear();
    ui->tableWidgetLayers->setRowCount(0);
    ui->tableWidgetLayers->setColumnCount(5);
    ui->tableWidgetLayers->setColumnWidth(0,30);
    ui->tableWidgetLayers->setColumnWidth(1,30);
    ui->tableWidgetLayers->setColumnWidth(2,60);
    ui->tableWidgetLayers->setColumnWidth(3,60);
    ui->tableWidgetLayers->setColumnWidth(4,200);

    if (!m_scene)
        return;

    foreach (QGraphicsItem *it, m_scene->items(Qt::AscendingOrder))
    {
        BaseGraphicItem *item = dynamic_cast<BaseGraphicItem*>(it);
        if ( item )
        {
            int row=ui->tableWidgetLayers->rowCount()+1;
            ui->tableWidgetLayers->setRowCount(row);
//            ui->tableWidgetLayers->setCellWidget(row-1, 0, Icon(":/Icons/about-icon.png"));
//            ui->tableWidgetLayers->setCellWidget(row-1, 0, Icon(":/Icons/eye.png"));
//            ui->tableWidgetLayers->setCellWidget(row-1,1,Icon(item->icon()));
//            ui->tableWidgetLayers->setCellWidget(row-1,1,Icon(item->icon()));
//            ui->tableWidgetLayers->setCellWidget(row-1,2,IconReduced(item->getImage(m_scene,item)));
            ui->tableWidgetLayers->setCellWidget(row-1,3,new QLabel(QString::number(item->zValue())));
            ui->tableWidgetLayers->setCellWidget(row-1,4,new QLabel("Label itemx")); // item->getName()));
        }
    }

    qDebug() << "FormLayers::ShowLayers()";
}

void FormLayers::updateLayers()
{
    m_zvalue++;
    ShowLayers();
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
        if (item->zValue() >= zValue && item->type() >= BaseGraphicItem::Type::TextBoxGraphicsItem)
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
        if (item->zValue() <= zValue && item->type() >= BaseGraphicItem::Type::TextBoxGraphicsItem)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}
