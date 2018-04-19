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

    // Set Default values of FormArrows
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
    DefaultFormOutlineColorArrow = FormFillColorArrow;
    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    BeforeFormFillColorArrow = FormFillColorArrow;

    // Connects for change color of the FormArrow
    connect(ui->toolButtonOutlineColorContents, SIGNAL(colorChanged()),this,SLOT(OutlineColorArrowChange()));
    connect(ui->toolButtonFillColorContents, SIGNAL(colorChanged()),this,SLOT(FillColorArrowChange()));

    //
}

FormArrows::~FormArrows()
{
    delete ui;
}

void FormArrows::FillColorArrowChanged()
{
    BeforeFormFillColorArrow = FormFillColorArrow;
    FormFillColorArrow = ui->toolButtonFillColorContents->getColor();
    emit FormFillColorArrowChanged(FormFillColorArrow);
}

void FormArrows::OutlineColorArrowChanged()
{
    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    FormOutlineColorArrow = ui->toolButtonOutlineColorContents->getColor();
    emit FormOutlineColorArrowChanged(FormOutlineColorArrow);
}
