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

#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QSettings>

#include "formtextboxes.h"
#include "ui_formtextboxes.h"
#include "Classes/colorbutton.h"
#include "../Items/textboxitem.h"

// Constructor, destructor
// -----------------------

FormTextBoxes::FormTextBoxes(QWidget *parent)
    :   BaseForm(parent), ui(new Ui::FormTextBoxes)
{
    ui->setupUi(this);

    // Build alignment comboboxes
    ui->comboBoxHorizontalAlignment->addItem(QIcon(":/icons/icons/align-left-icon.png"), tr("Left"), Qt::AlignLeft);
    ui->comboBoxHorizontalAlignment->addItem(QIcon(":/icons/icons/align-right-icon.png"), tr("Right"), Qt::AlignRight);
    ui->comboBoxHorizontalAlignment->addItem(QIcon(":/icons/icons/align-hcentered-icon.png"), tr("Centered"), Qt::AlignHCenter);

    ui->comboBoxVerticalAlignment->addItem(QIcon(":/icons/icons/align-top-icon.png"), tr("Top"), Qt::AlignTop);
    ui->comboBoxVerticalAlignment->addItem(QIcon(":/icons/icons/align-bottom-icon.png"), tr("Bottom"), Qt::AlignBottom);
    ui->comboBoxVerticalAlignment->addItem(QIcon(":/icons/icons/align-vcentered-icon.png"), tr("Centered"), Qt::AlignVCenter);

    // Load default theme
    loadDefaultTheme();

    // Connect
    connect(ui->pushButtonSaveTheme, SIGNAL(clicked(bool)), this, SLOT(saveDefaultTheme()));
    connect(ui->pushButtonApplyTheme, SIGNAL(clicked(bool)), this, SLOT(loadDefaultTheme()));
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

    s.setValue("FormTextBoxes/font", font.toString());
    s.setValue("FormTextBoxes/margin", ui->spinBoxMargin->value());
    s.setValue("FormTextBoxes/alignment", ui->comboBoxHorizontalAlignment->currentData().toInt() | ui->comboBoxVerticalAlignment->currentData().toInt());
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
    f.fromString(s.value("FormTextBoxes/font", QFont().toString()).toString());

    ui->fontComboBox->setCurrentText(f.family());
    ui->spinBoxPointSize->setValue(f.pointSize());
    ui->checkBoxBold->setChecked(f.bold());
    ui->checkBoxItalic->setChecked(f.italic());

    ui->spinBoxMargin->setValue(s.value("FormTextBoxes/margin", 5).toInt());

    int horizontalFlag = s.value("FormTextBoxes/alignment", Qt::AlignLeft).toInt() & Qt::AlignHorizontal_Mask;
    int verticalFlag = s.value("FormTextBoxes/alignment", Qt::AlignTop).toInt() & Qt::AlignVertical_Mask;

    int idxHorizontal = ui->comboBoxHorizontalAlignment->findData(horizontalFlag);
    int idxVertical = ui->comboBoxVerticalAlignment->findData(verticalFlag);
    ui->comboBoxHorizontalAlignment->setCurrentIndex(idxHorizontal);
    ui->comboBoxVerticalAlignment->setCurrentIndex(idxVertical);

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
    data["margin"] = ui->spinBoxMargin->value();
    data["alignment"] = ui->comboBoxHorizontalAlignment->currentData().toInt() | ui->comboBoxVerticalAlignment->currentData().toInt();
    data["background-color"] = ui->pushButtonBackgroundColor->getColor().name();
    data["text-color"] = ui->pushButtonTextColor->getColor().name();
    data["border-color"] = ui->pushButtonBorderColor->getColor().name();
    data["border-visible"] = ui->checkBoxHasBorders->isChecked();
    data["border-width"] = ui->spinBoxBorderWidth->value();
    data["border-radius"] = ui->spinBoxBorderRadius->value();

    return data;
}

//void FormTextBoxes::setItemData(const QVariant& data)
//{
//    // Set the field from the stored data
//    QVariantHash vh = data.toHash();

//    QFont f;
//    f.fromString(vh["font"].toString());

//    ui->plainTextEdit->setPlainText(vh["text"].toString());
//    ui->fontComboBox->setCurrentText(f.family());
//    ui->spinBoxPointSize->setValue(f.pointSize());
//    ui->checkBoxBold->setChecked(f.bold());
//    ui->checkBoxItalic->setChecked(f.italic());

//    int idx = ui->comboBoxHorizontalAlignment->findData(vh["alignment"].toInt());
//    ui->comboBoxHorizontalAlignment->setCurrentIndex(idx);

//    ui->pushButtonBackgroundColor->setColor(QColor(vh["background-color"].toString()));
//    ui->pushButtonTextColor->setColor(QColor(vh["text-color"].toString()));
//    ui->pushButtonBorderColor->setColor(QColor(vh["border-color"].toString()));

//    ui->checkBoxHasBorders->setChecked(vh["border-visible"].toBool());
//    ui->spinBoxBorderWidth->setValue(vh["border-width"].toInt());
//    ui->spinBoxBorderRadius->setValue(vh["border-radius"].toInt());
//}

// Load data
// ---------

void FormTextBoxes::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<TextBoxItem*>(item))
    {
        TextBoxItem* castedItem = qgraphicsitem_cast<TextBoxItem*>(item);

        // Load data into the form
        QFont f = castedItem->font();

        ui->plainTextEdit->setPlainText(castedItem->text());
        ui->fontComboBox->setCurrentText(f.family());
        ui->spinBoxPointSize->setValue(f.pointSize());
        ui->checkBoxBold->setChecked(f.bold());
        ui->checkBoxItalic->setChecked(f.italic());

        ui->spinBoxMargin->setValue(castedItem->margin());

        int idxHorizontal = ui->comboBoxHorizontalAlignment->findData(castedItem->alignment() & Qt::AlignHorizontal_Mask);
        int idxVertical = ui->comboBoxVerticalAlignment->findData(castedItem->alignment() & Qt::AlignVertical_Mask);
        ui->comboBoxHorizontalAlignment->setCurrentIndex(idxHorizontal);
        ui->comboBoxVerticalAlignment->setCurrentIndex(idxVertical);

        ui->pushButtonBackgroundColor->setColor(castedItem->backgroundColor());
        ui->pushButtonTextColor->setColor(castedItem->textColor());
        ui->pushButtonBorderColor->setColor(castedItem->borderColor());

        ui->checkBoxHasBorders->setChecked(castedItem->hasBorders());
        ui->spinBoxBorderWidth->setValue(castedItem->borderWidth());
        ui->spinBoxBorderRadius->setValue(castedItem->borderRadius());
    }
}
