/*
================================================
* File:         formcliparts.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formcliparts.h"
#include "ui_formcliparts.h"

#include <QtWidgets/QFileDialog>


// Constructor, destructor
// -----------------------

FormCliparts::FormCliparts(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormCliparts)
{

    ui->setupUi(this);

    ui->button_action->setEnabled(false);
    ui->button_clear->setVisible(false);

    connect(ui->button_browse, SIGNAL( clicked(bool) ), this, SLOT( event_on_click_browse(bool) ));
    connect(ui->button_clear,  SIGNAL( clicked(bool) ), this, SLOT( event_on_click_clear(bool) ));
}


FormCliparts::~FormCliparts()
{
    delete ui;
}


void FormCliparts::event_on_click_browse(bool) {
    QString file_name = QFileDialog::getOpenFileName(this,
                                                     QStringLiteral("Sélectionner une bibliothèque"),
                                                     NULL,
                                                     QStringLiteral("Images (*.png *.jpg)"));

    if (!file_name.isEmpty()) {
        ui->edit_path->setText(file_name);

        ui->button_action->setEnabled(true);
        ui->button_clear->setVisible(true);
    }
}


void FormCliparts::event_on_click_clear(bool) {
    ui->edit_path->clear();

    ui->button_action->setEnabled(false);
    ui->button_clear->setVisible(false);
}
