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

// Constructor, destructor
// -----------------------

FormArrows::FormArrows(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormArrows)
{
    ui->setupUi(this);
}

FormArrows::~FormArrows()
{
    delete ui;
}
