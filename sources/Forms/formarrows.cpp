/*
================================================
* File:         formarrows.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

// Includes
// --------

#include "formarrows.h"
#include "ui_formarrows.h"
#include <QDebug>

// Constructor, destructor
// -----------------------

FormArrows::FormArrows(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormArrows)
{
    ui->setupUi(this);
    //
    // Set Default values of FormArrows
    //
    ui->radioButtonWithoutAnchorPoint->setChecked(true);
    ui->spinBoxArrowWidthContents->setMinimum(20);
    ui->spinBoxArrowWidthContents->setMinimumWidth(20);
    ui->spinBoxArrowWidthContents->setMaximum(500);
    ui->spinBoxArrowHeightContents->setMinimum(20);
    ui->spinBoxArrowHeightContents->setMinimumHeight(20);
    ui->spinBoxArrowHeightContents->setMaximum(500);

    // Get start default color Qt::black on the Class ColorButton we use others Colors
    ui->toolButtonOutlineColorContents->setColor(Qt::darkCyan);
    ui->toolButtonFillColorContents->setColor(Qt::darkBlue);

    FormOutlineColorArrow = ui->toolButtonOutlineColorContents->getColor();
    FormFillColorArrow = ui->toolButtonFillColorContents->getColor();

    DefaultFormOutlineColorArrow = FormOutlineColorArrow;
    DefaultFormFillColorArrow = FormFillColorArrow;

    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    BeforeFormFillColorArrow = FormFillColorArrow;

    //ui->comboBoxThicknessOutlineLinesContents->;

    // End default values of FormArrows

    // Connects for change color of the FormArrow
    connect(ui->toolButtonOutlineColorContents, SIGNAL(colorChanged(QColor)), this, SLOT(outlineColorArrowChanged(QColor)));
    connect(ui->toolButtonFillColorContents, SIGNAL(colorChanged(QColor)), this, SLOT(fillColorArrowChanged(QColor)));
}

FormArrows::~FormArrows()
{
    delete ui;
}

// Method GetInfosArrows
void FormArrows::GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                                int ArrowWidth, int ArrowHeight,
                                QColor ArrowOutlineColor, QColor ArrowFillColor)
                                //To do
                                // comboBoxThicknessOutlineLinesContents
                                // comboBoxHeadTypeChoiceContents
{
   WithoutAnchorPoint = ui->radioButtonWithoutAnchorPoint->isChecked();
   OneAnchorPoint = ui->radioButton1AnchorPoints->isChecked();
   TwoAnchorPoints = ui->radioButton2AnchorPoints->isChecked();

   ArrowWidth = ui->spinBoxArrowWidthContents->value();
   ArrowHeight = ui->spinBoxArrowHeightContents->value();

   ArrowOutlineColor = ui->toolButtonOutlineColorContents->getColor();
   ArrowFillColor = ui->toolButtonFillColorContents->getColor();

   //To do
   // comboBoxThicknessOutlineLinesContents
   // comboBoxHeadTypeChoiceContents

}

void FormArrows::fillColorArrowChanged(const QColor& color)
{
    BeforeFormFillColorArrow = FormFillColorArrow;
    FormFillColorArrow = color;
    emit FormFillColorArrowChanged(FormFillColorArrow);
}

void FormArrows::outlineColorArrowChanged(const QColor& color)
{
    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    FormOutlineColorArrow = color;
    emit FormOutlineColorArrowChanged(FormOutlineColorArrow);
}

