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
#include <QSettings>

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

    // Load default theme
    loadDefaultTheme();

    // Connect
    connect(ui->pushButtonSaveTheme, SIGNAL(clicked(bool)), this, SLOT(saveDefaultTheme()));
}

FormTextBoxes::~FormTextBoxes()
{
    delete ui;
}

// Slots
// -----

void FormTextBoxes::saveDefaultTheme()
{
    QSettings s;

    QFont font;
    font.setFamily(ui->fontComboBox->currentText());
    font.setPointSize(ui->spinBoxPointSize->value());
    font.setBold(ui->checkBoxBold->isChecked());
    font.setItalic(ui->checkBoxItalic->isChecked());

    s.setValue("FormTextBoxes/font", font);
    s.setValue("FormTextBoxes/alignment", ui->comboBoxAlignment->currentData());
    s.setValue("FormTextBoxes/background-color", ui->pushButtonBackgroundColor->getColor().name());
    s.setValue("FormTextBoxes/text-color", ui->pushButtonTextColor->getColor().name());
    s.setValue("FormTextBoxes/border-color", ui->pushButtonBorderColor->getColor().name());
    s.setValue("FormTextBoxes/border-visible", ui->checkBoxHasBorders->isChecked());
    s.setValue("FormTextBoxes/border-width", ui->spinBoxBorderWidth->value());
    s.setValue("FormTextBoxes/border-radius", ui->spinBoxBorderRadius->value());
}

void FormTextBoxes::loadDefaultTheme()
{
    QSettings s;

    QFont f;
    f.fromString(s.value("FormTextBoxes/font").toString());

    ui->plainTextEdit->setPlainText(s.value("FormTextBoxes/text").toString());
    ui->fontComboBox->setCurrentFont(f);
    ui->spinBoxPointSize->setValue(f.pointSize());
    ui->checkBoxBold->setChecked(f.bold());
    ui->checkBoxItalic->setChecked(f.italic());

    int idx = ui->comboBoxAlignment->findData(s.value("FormTextBoxes/alignment", Qt::AlignLeft).toInt());
    ui->comboBoxAlignment->setCurrentIndex(idx);

    ui->pushButtonBackgroundColor->setColor(QColor(s.value("FormTextBoxes/background-color", QColor(Qt::white).name()).toString()));
    ui->pushButtonTextColor->setColor(QColor(s.value("FormTextBoxes/text-color", QColor(Qt::black).name()).toString()));
    ui->pushButtonBorderColor->setColor(QColor(s.value("FormTextBoxes/border-color", QColor(Qt::black).name()).toString()));

    ui->checkBoxHasBorders->setChecked(s.value("FormTextBoxes/border-visible", true).toBool());
    ui->spinBoxBorderWidth->setValue(s.value("FormTextBoxes/border-width", 1).toInt());
    ui->spinBoxBorderRadius->setValue(s.value("FormTextBoxes/border-radius", 0).toInt());
}

// Getters and setters
// -------------------

const QPushButton* FormTextBoxes::getAddButton()
{
    return ui->pushButtonAdd;
}

QVariant FormTextBoxes::getItemData() const
{
    QVariantHash data;

    QFont font;
    font.setFamily(ui->fontComboBox->currentText());
    font.setPointSize(ui->spinBoxPointSize->value());
    font.setBold(ui->checkBoxBold->isChecked());
    font.setItalic(ui->checkBoxItalic->isChecked());

    data["text"] = ui->plainTextEdit->toPlainText();
    data["font"] = font.toString();
    data["alignment"] = ui->comboBoxAlignment->currentData();
    data["background-color"] = ui->pushButtonBackgroundColor->getColor().name();
    data["text-color"] = ui->pushButtonTextColor->getColor().name();
    data["border-color"] = ui->pushButtonBorderColor->getColor().name();
    data["border-visible"] = ui->checkBoxHasBorders->isChecked();
    data["border-width"] = ui->spinBoxBorderWidth->value();
    data["border-radius"] = ui->spinBoxBorderRadius->value();

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

