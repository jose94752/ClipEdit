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
#include <QStringList>
#include <QApplication>
#include <QDesktopWidget>

#include "resizescenedialog.h"
#include "ui_resizescenedialog.h"

// Constructor, destructor
// -----------------------

ResizeSceneDialog::ResizeSceneDialog(QGraphicsScene* vscene, int* v_width, int* v_height, QWidget* parent)
    :   QDialog(parent),
        ui(new Ui::ResizeSceneDialog)
{
    ui->setupUi(this);

    m_scene = vscene;

    // Store size
    m_width = v_width;
    m_height = v_height;

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
    QStringList unitNames;
    unitNames << "mm" << "cm" << "inch" << "px";
    ui->comboBoxUnit->addItems(unitNames);

    // Connects
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(sizeChanged()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->comboBoxUnit, SIGNAL(currentTextChanged(QString)), this, SLOT(unitChanged(QString)));

    unitChanged("mm");
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}

// Slots
// -----

void ResizeSceneDialog::sizeChanged()
{
    int width=0;
    int height=0;

    QString name = ui->comboBoxUnit->currentText();

    if (name == "mm"){
        width = ui->doubleSpinBoxWidth->value() * m_dpix/25.4;
        height = ui->doubleSpinBoxHeight->value() * m_dpiy/25.4;
    }
    if (name == "cm"){
        width = ui->doubleSpinBoxWidth->value() * m_dpix/2.54;
        height = ui->doubleSpinBoxHeight->value() * m_dpiy/2.54;
    }
    if (name == "inch"){
        width = ui->doubleSpinBoxWidth->value() * m_dpix;
        height = ui->doubleSpinBoxHeight->value() * m_dpiy;
    }
    if (name == "px"){
        width = ui->doubleSpinBoxWidth->value();
        height = ui->doubleSpinBoxHeight->value();
    }

    int x = -width/2;
    int y = -height/2;

    m_scene->setSceneRect(x, y, width, height);
    *m_width = width;
    *m_height = height;
}

void ResizeSceneDialog::unitChanged(const QString& unit)
{
    if (unit.isEmpty())
        return;

    int width = *m_width;
    int height = *m_height;

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
