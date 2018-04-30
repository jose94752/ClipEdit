/*
==================================================
* File:         resizescenedialog.cpp
* Project:      ClipEdit
* Creation:     24/04/2018
* Brief:        Dialog to edit the scene dimension
==================================================
*/

// Includes
// --------

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStringList>
#include <QApplication>
#include <QDesktopWidget>
#include <QBrush>
#include "resizescenedialog.h"
#include "ui_resizescenedialog.h"

// Constructor, destructor
// -----------------------

QString ResizeSceneDialog::m_format="A4";

ResizeSceneDialog::ResizeSceneDialog(QGraphicsScene* vscene, QGraphicsRectItem** v_borderSceneItem, const QColor& v_backgroundColor,bool isNew, QWidget* parent)
    :   QDialog(parent),
        ui(new Ui::ResizeSceneDialog)
{
    if (!vscene)
        close();

    ui->setupUi(this);

    m_scene = vscene;

    m_borderSceneItem=v_borderSceneItem;

    m_backGroundColor=v_backgroundColor;

    m_format_changed=false;

    //button color size
    int buttonwidth=ui->doubleSpinBoxWidth->width();
    ui->colorButton->setMinimumWidth(buttonwidth);

    // Get monitor dpi
    QDesktopWidget* desktop = QApplication::desktop();

    if (desktop)
    {
        m_dpix = desktop->logicalDpiX();
        m_dpiy = desktop->logicalDpiY();
    }
    else
    {
        m_dpix = 72;
        m_dpiy = 72;
    }

    // Units list
    QStringList formatNames;
    formatNames <<"None"<<"A0"<<"A1"<<"A2"<<"A3"<<"A4"<<"A5"<<"A6"<<"A7"<<"A8";
    ui->comboBox_format->addItems(formatNames);
    ui->comboBox_format->setCurrentText(m_format);


    QStringList unitNames;
    unitNames << "mm" << "cm" << "inch" << "px";
    ui->comboBoxUnit->addItems(unitNames);

    // Init from scene (size in pixels)
    m_width=m_scene->width();
    m_height=m_scene->height();
    ui->doubleSpinBoxWidth->setValue(m_width);
    ui->doubleSpinBoxHeight->setValue(m_height);
    ui->comboBoxUnit->setCurrentText("px");
    ui->doubleSpinBoxWidth->setDecimals(0);
    ui->doubleSpinBoxHeight->setDecimals(0);
    //unitChanged("px");

    // Connects
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(sizeChanged()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->comboBoxUnit, SIGNAL(currentTextChanged(QString)), this, SLOT(unitChanged(QString)));
    connect(ui->comboBox_format, SIGNAL(currentTextChanged(QString)),this,SLOT(formatChanged(QString)));
    connect(ui->doubleSpinBoxWidth,SIGNAL(valueChanged(double)),this,SLOT(valuesChanged()));
    connect(ui->doubleSpinBoxHeight,SIGNAL(valueChanged(double)),this,SLOT(valuesChanged()));

    // Hide color button if not New page
    m_isNew = isNew;

    if (isNew){
        ui->colorButton->setColor(Qt::white);
    }else{
        ui->label_color->hide();
        ui->colorButton->hide();
    }
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}

void ResizeSceneDialog::detectFormat()
{
    QString detectedFormat = "None";
    int Ax, Ay;
    Ax = 841 * m_dpix/25.4;
    Ay = 1189 * m_dpiy/25.4;

    //if(m_width >= Ax-3 && m_width <= Ax+3 && m_height >= Ay-3 && m_height <= Ay+3){
    if (m_width == Ax && m_height == Ay){
        detectedFormat="A0";
    }
    Ax = 594 * m_dpix/25.4;
    Ay = 841 * m_dpiy/25.4;
    if(m_width == Ax && m_height == Ay){
        detectedFormat = "A1";
    }
    Ax = 420 * m_dpix/25.4;
    Ay = 594 * m_dpiy/25.4;
    if (m_width == Ax && m_height == Ay){
        detectedFormat = "A2";
    }
    Ax = 297 * m_dpix/25.4;
    Ay = 420 * m_dpiy/25.4;
    if (m_width == Ax && m_height == Ay){
        detectedFormat = "A3";
    }
    Ax = 210 * m_dpix/25.4;
    Ay = 297 * m_dpiy/25.4;
    if(m_width == Ax && m_height == Ay){
        detectedFormat = "A4";
    }
    Ax = 148 * m_dpix/25.4;
    Ay = 210 * m_dpiy/25.4;
    if(m_width == Ax && m_height == Ay){
        detectedFormat = "A5";
    }
    Ax = 105 * m_dpix/25.4;
    Ay = 148 * m_dpiy/25.4;
    if (m_width == Ax && m_height == Ay){
        detectedFormat = "A6";
    }
    Ax = 74 * m_dpix/25.4;
    Ay = 105 * m_dpiy/25.4;
    if (m_width == Ax && m_height == Ay){
        detectedFormat = "A7";
    }
    Ax = 52 * m_dpix/25.4;
    Ay = 74 * m_dpiy/25.4;
    if (m_width == Ax && m_height == Ay){
        detectedFormat="A8";
    }
    if (m_format == "None"){
        m_format = detectedFormat;
    }
}

// Slots
// -----

void ResizeSceneDialog::sizeChanged()
{
    if (!m_scene)
        return;

    QString name = ui->comboBoxUnit->currentText();

    if (name == "mm"){
        m_width = (int)ui->doubleSpinBoxWidth->value() * m_dpix/25.4;
        m_height = (int)ui->doubleSpinBoxHeight->value() * m_dpiy/25.4;
    }
    if (name == "cm"){
        m_width = (int)ui->doubleSpinBoxWidth->value() * m_dpix/2.54;
        m_height = (int)ui->doubleSpinBoxHeight->value() * m_dpiy/2.54;
    }
    if (name == "inch"){
        m_width = (int)ui->doubleSpinBoxWidth->value() * m_dpix;
        m_height = (int)ui->doubleSpinBoxHeight->value() * m_dpiy;
    }
    if (name == "px"){
        m_width = (int)ui->doubleSpinBoxWidth->value();
        m_height = (int)ui->doubleSpinBoxHeight->value();
    }
    m_scene->removeItem(*m_borderSceneItem);
    QGraphicsScene scene2;
    QList<QGraphicsItem *> items = m_scene->items();
    foreach(QGraphicsItem* item, items){
        scene2.addItem(item);
    }

    m_scene->setSceneRect(QRectF(0,0,m_width+2,m_height+2));
    *m_borderSceneItem=m_scene->addRect(QRectF(0,0,m_width,m_height));

    if (m_isNew){
        QColor l_color = ui->colorButton->getColor();
        if(l_color.isValid()){
            m_backGroundColor = l_color;
        }
    }

    (*m_borderSceneItem)->setBrush(QBrush(m_backGroundColor));
    items = scene2.items();
    foreach (QGraphicsItem* item,items){
        m_scene->addItem(item);
    }
}

void ResizeSceneDialog::valuesChanged()
{
    if (!m_format_changed)
    {
        QString unit=ui->comboBoxUnit->currentText();
        if (unit == "mm"){
            m_width=(int)(ui->doubleSpinBoxWidth->value()*m_dpix/25.4);
            m_height=(int)(ui->doubleSpinBoxHeight->value()*m_dpiy/25.4);
        }
        if (unit == "cm"){
            m_width=(int)(ui->doubleSpinBoxWidth->value()*m_dpix/2.54);
            m_height=(int)(ui->doubleSpinBoxHeight->value()*m_dpiy/2.54);
        }
        if (unit == "inch"){
            m_width=(int)ui->doubleSpinBoxWidth->value()*m_dpix;
            m_height=(int)ui->doubleSpinBoxHeight->value()*m_dpiy;
        }
        if (unit == "px"){
            m_width=(int)ui->doubleSpinBoxWidth->value();
            m_height=(int)ui->doubleSpinBoxHeight->value();
        }

        m_format = "None";
        ui->comboBox_format->setCurrentText("None");
        detectFormat();
        if (m_format != "None"){
            ui->comboBox_format->setCurrentText(m_format);
        }
    }
}

void ResizeSceneDialog::unitChanged(const QString& unit)
{
    int width = m_width;
    int height = m_height;

    if (unit.isEmpty() || !m_scene)
        return;

    if (unit == "mm"){
        ui->doubleSpinBoxWidth->setValue(width * 25.4/m_dpix);
        ui->doubleSpinBoxHeight->setValue(height * 25.4/m_dpiy);
        ui->doubleSpinBoxWidth->setDecimals(0);
        ui->doubleSpinBoxHeight->setDecimals(0);
    }
    if (unit == "cm"){
        ui->doubleSpinBoxWidth->setValue(width * 2.54/m_dpix);
        ui->doubleSpinBoxHeight->setValue(height * 2.54/m_dpiy);
        ui->doubleSpinBoxWidth->setDecimals(1);
        ui->doubleSpinBoxHeight->setDecimals(1);
    }
    if (unit == "inch"){
        ui->doubleSpinBoxWidth->setValue(width/m_dpix);
        ui->doubleSpinBoxHeight->setValue(height/m_dpiy);
        ui->doubleSpinBoxWidth->setDecimals(1);
        ui->doubleSpinBoxHeight->setDecimals(1);
    }
    if (unit == "px"){
        ui->doubleSpinBoxWidth->setValue(width);
        ui->doubleSpinBoxHeight->setValue(height);
        ui->doubleSpinBoxWidth->setDecimals(0);
        ui->doubleSpinBoxHeight->setDecimals(0);
    }
}

void ResizeSceneDialog::formatChanged(const QString& format)
{
    m_format_changed = true;
    QString unit = ui->comboBoxUnit->currentText();
    m_format = format;
    QString v_unit = ui->comboBoxUnit->currentText();

    if(format != "None"){
        if(format == "A0"){
            m_width = 841 * m_dpix/25.4;
            m_height = 1189 * m_dpiy/25.4;
        }
        if(format == "A1"){
            m_width = 594 * m_dpix/25.4;
            m_height = 841 * m_dpiy/25.4;
        }
        if(format == "A2"){
            m_width = 420 * m_dpix/25.4;
            m_height = 594 * m_dpiy/25.4;
        }
        if(format == "A3"){
            m_width = 297 * m_dpix/25.4;
            m_height = 420 * m_dpiy/25.4;
        }
        if(format == "A4"){
            m_width = 210 * m_dpix/25.4;
            m_height = 297 * m_dpiy/25.4;
        }
        if(format == "A5"){
            m_width = 148 * m_dpix/25.4;
            m_height = 210 * m_dpiy/25.4;
        }
        if(format == "A6"){
            m_width = 105 * m_dpix/25.4;
            m_height = 148 * m_dpiy/25.4;
        }
        if(format == "A7"){
            m_width = 74 * m_dpix/25.4;
            m_height = 105 * m_dpiy/25.4;
        }
        if(format == "A8"){
            m_width = 52 * m_dpix/25.4;
            m_height = 74 * m_dpiy/25.4;
        }
        unitChanged(unit);
    }

    m_format_changed = false;
}

void ResizeSceneDialog::resizeEvent(QResizeEvent* event)
{
    int buttonwidth = ui->doubleSpinBoxWidth->width();
    ui->colorButton->setMinimumWidth(buttonwidth);
}
