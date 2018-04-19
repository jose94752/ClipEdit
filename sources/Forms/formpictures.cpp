/*
================================================
* File:         formpictures.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formpictures.h"
#include "formpictures.h"
#include "ui_formpictures.h"
#include <QFont>
#include <QColor>
#include <QString>

// Constructor, destructor
// -----------------------

FormPictures::FormPictures(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormPictures)
{
    ui->setupUi(this);

    ui->comboBox_lg_pos->addItem("Above Right");
    ui->comboBox_lg_pos->addItem("Above Middle");
    ui->comboBox_lg_pos->addItem("Above Left");

    ui->comboBox_lg_pos->addItem("Below Right");
    ui->comboBox_lg_pos->addItem("Below Middle");
    ui->comboBox_lg_pos->addItem("Below Left");

    ui->comboBox_lg_pos->addItem("Left High");
    ui->comboBox_lg_pos->addItem("Left Center");
    ui->comboBox_lg_pos->addItem("Left Down");

    ui->comboBox_lg_pos->addItem("Right High");
    ui->comboBox_lg_pos->addItem("Right Center");
    ui->comboBox_lg_pos->addItem("Right Down");

    //ui->lineEdit_age->setText();


}


FormPictures::~FormPictures()
{
    delete ui;
}


void FormPictures::getPictureValues(int &heigh, int &width, int &shade_grey, int &trans, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos){
     heigh      = ui->spinBox_pic_h->value();
     width      = ui->spinBox_pic_w->value();
     shade_grey = ui->spinBox_pic_sh->value();
     trans      = ui->spinBox_pic_t->value();
     lg_txt     = ui->lineEdit_lg_txt->text();
     lg_font    = ui->fontComboBox_lg_font->font();
     lg_size    = ui->spinBox_lg_size->value();
     lg_color   = ui->toolButton_color->getColor();
     lg_pos     = ui->comboBox_lg_pos->currentText();




}
