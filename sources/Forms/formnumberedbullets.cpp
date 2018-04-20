/*
================================================
* File:         formnumberedbullets.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#include "formnumberedbullets.h"
#include "ui_formnumberedbullets.h"

FormNumberedBullets::FormNumberedBullets(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormNumberedBullets)
{
    ui->setupUi(this);
}

FormNumberedBullets::~FormNumberedBullets()
{
    delete ui;
}

//for now shape : 0-> circle
//                1-> rectangle
//                2-> rounded rectangle
//TBD enum in NumberedBulletGraphicItem
void FormNumberedBullets::get_info (int& from, int& to, int& taille, int& shape, QColor& bulletcolor, QColor& numbercolor, QFont& font) {
    from = ui->spinBox_From->value();
    to = ui->spinBox_To->value ();
    taille = ui->spinBox_Size->value();
    //QString shape_str;
    shape = ui->comboBox_Shape->currentIndex();
    bulletcolor = ui->ColorButton_NumberColor->getColor();
    numbercolor = ui->ColorButton_NumberColor->getColor();
    font = ui->fontComboBox->font ();

}

QPushButton *FormNumberedBullets::getGoPushButton()
{
    return ui->pushButtonCreateBullet;
}

