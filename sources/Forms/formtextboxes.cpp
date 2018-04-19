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
#include "Classes/colorbutton.h"

// Constructor, destructor
// -----------------------

FormTextBoxes::FormTextBoxes(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormTextBoxes)
{
    ui->setupUi(this);

    ui->toolButtonBackgroundColor->setColor(Qt::white);
    ui->toolButtonTextColor->setColor(Qt::black);
}

FormTextBoxes::~FormTextBoxes()
{
    delete ui;
}

// Getters
// -------

QString FormTextBoxes::getText() const
{
    return ui->plainTextEdit->toPlainText();
}

QString FormTextBoxes::getFontFamily() const
{
    return ui->fontComboBox->currentText();
}

int FormTextBoxes::getFontPointSize() const
{
    return ui->spinBoxPointSize->value();
}
