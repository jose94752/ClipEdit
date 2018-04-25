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

    ui->pushButtonBackgroundColor->setColor(Qt::white);
    ui->pushButtonTextColor->setColor(Qt::black);

    // Build alignment combobox
    ui->comboBoxAlignment->addItem(QIcon(":/icons/icons/icon-align-left.png"), tr("Left"), Qt::AlignLeft);
    ui->comboBoxAlignment->addItem(QIcon(":/icons/icons/icon-align-right.png"), tr("Right"), Qt::AlignRight);
    ui->comboBoxAlignment->addItem(QIcon(":/icons/icons/icon-align-centered.png"), tr("Centered"), Qt::AlignHCenter);
}

FormTextBoxes::~FormTextBoxes()
{
    delete ui;
}

// Getters
// -------

const QPushButton* FormTextBoxes::getAddButton()
{
    return ui->pushButtonAdd;
}

QMap<QString, QVariant> FormTextBoxes::getInfos()
{
    QMap<QString, QVariant> res;
    QFont font;
    font.setFamily(ui->fontComboBox->currentText());
    font.setPointSize(ui->spinBoxPointSize->value());
    font.setBold(ui->checkBoxBold->isChecked());
    font.setItalic(ui->checkBoxItalic->isChecked());

    res.insert("text", ui->plainTextEdit->toPlainText());
    res.insert("font", font.toString());
    res.insert("alignment", ui->comboBoxAlignment->currentData());
    res.insert("background-color", ui->pushButtonBackgroundColor->getColor().name());
    res.insert("font-color", ui->pushButtonTextColor->getColor().name());
    res.insert("border-color", ui->pushButtonBorderColor->getColor().name());
    res.insert("border-visible", ui->checkBoxHasBorders->isChecked());
    res.insert("border-width", ui->spinBoxBorderWidth->value());
    res.insert("border-radius", ui->spinBoxBorderRadius->value());

    return res;
}

QVariant FormTextBoxes::getItemData()
{
    QVariant data;

    return data;
}

void FormTextBoxes::setItemData(const QVariant& data)
{
    // Set the field from the stored data
    QVariantHash vh = data.toHash();

    QFont f;
    f.fromString(vh["font"].toString());

    ui->plainTextEdit->setPlainText(vh["text"].toString());
    ui->fontComboBox->setCurrentFont(f);
    ui->spinBoxPointSize->setValue(f.pointSize());
    ui->checkBoxBold->setChecked(f.bold());
    ui->checkBoxItalic->setChecked(f.italic());

    int idx = ui->comboBoxAlignment->findData(vh["alignment"].toInt());
    ui->comboBoxAlignment->setCurrentIndex(idx);

    ui->pushButtonBackgroundColor->setColor(QColor(vh["background-color"].toString()));
    ui->pushButtonTextColor->setColor(QColor(vh["text-color"].toString()));
    ui->pushButtonBorderColor->setColor(QColor(vh["border-color"].toString()));

    ui->checkBoxHasBorders->setChecked(vh["border-visible"].toBool());
    ui->spinBoxBorderWidth->setValue(vh["border-width"].toInt());
    ui->spinBoxBorderRadius->setValue(vh["border-radius"].toInt());
}
