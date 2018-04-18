/*
================================================
* File:         formtextboxes.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include <QColorDialog>
#include <QColor>

#include "formtextboxes.h"
#include "ui_formtextboxes.h"

// Constructor, destructor
// -----------------------

FormTextBoxes::FormTextBoxes(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormTextBoxes)
{
    ui->setupUi(this);

    ui->pushButtonBackgroundColor->setAutoFillBackground(true);
    ui->pushButtonBackgroundColor->setAutoFillBackground(true);

    connect(ui->pushButtonBackgroundColor, SIGNAL(clicked(bool)), this, SLOT(pickColor(bool)));
    connect(ui->pushButtonTextColor, SIGNAL(clicked(bool)), this, SLOT(pickColor(bool)));
}

FormTextBoxes::~FormTextBoxes()
{
    delete ui;
}

// Slots
// -----

void FormTextBoxes::pickColor(bool)
{
    // !! Stylesheets

    QColor color = QColorDialog::getColor(Qt::white, this);

    if (sender() == ui->pushButtonBackgroundColor)
    {
        ui->pushButtonBackgroundColor->setStyleSheet("background-color:" + color.name(QColor::HexRgb));
    }
    else if (sender() == ui->pushButtonTextColor)
    {
        ui->pushButtonTextColor->setStyleSheet("background-color:" + color.name(QColor::HexRgb));
    }

    update();
}
