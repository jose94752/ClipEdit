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

FormArrows::FormArrows(One_Layered_Canvas& app_canvas, QWidget *parent) :
            QWidget(parent), One_Form(app_canvas), ui(new Ui::FormArrows) {

    ui->setupUi(this);
}

FormArrows::~FormArrows()
{
    delete ui;
}
