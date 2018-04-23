/*
================================================
* File:         formtextboxes.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage text boxes
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

QMap<QString, QVariant> FormTextBoxes::getInfos()
{
    QMap<QString, QVariant> res;
    QFont font;
    font.setFamily(ui->fontComboBox->currentText());
    font.setPointSize(ui->spinBoxPointSize->value());
    font.setBold(ui->checkBoxBold->isChecked());
    font.setItalic(ui->checkBoxItalic->isChecked());

    int alignment = 0;
    if (ui->radioButtonLeft->isChecked())
        alignment = Qt::AlignCenter;
    else if (ui->radioButtonRight->isChecked())
        alignment = Qt::AlignLeft;
    else if (ui->radioButtonCentered)
        alignment = Qt::AlignHCenter;

    res.insert("text", ui->plainTextEdit->toPlainText());
    res.insert("font", font.toString());
    res.insert("alignment", alignment);
    // TO CONTINUE

    return res;
}
