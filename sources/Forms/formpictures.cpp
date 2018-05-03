/*
====================================================
* File:         formpictures.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create PicturesGraphicsItem
====================================================
*/

// Includes
// --------

#include <QFont>
#include <QColor>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QSettings>

#include "formpictures.h"
#include "formpictures.h"
#include "ui_formpictures.h"
#include "../Items/picturesgraphicsitem.h"

// Constructor, destructor
// -----------------------

FormPictures::FormPictures(QWidget *parent)
    :   BaseForm(parent), ui(new Ui::FormPictures)
{
    ui->setupUi(this);

    connect (ui->pushButton_ok,         SIGNAL(clicked(bool)), this, SLOT(validation_ok(bool)));
    connect (ui->toolButton_path,       SIGNAL(pressed()),     this, SLOT(chose_picture()));
    connect (ui->pushButton_save,       SIGNAL(clicked(bool)), this, SLOT(save_settings(bool)));
    connect (ui->pushButton_restore,    SIGNAL(clicked(bool)), this, SLOT(restore_settings(bool)));

    connect (ui->comboBox_lg_or, SIGNAL(currentTextChanged(QString)), this, SLOT(load_position(QString)));


    ui->comboBox_lg_or->addItem(tr("Horizontal"));
    ui->comboBox_lg_or->addItem(tr("Vertical"));
}


FormPictures::~FormPictures()
{
    delete ui;
}


void FormPictures::getPictureValues(QString &path, int &height, int &width,  bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos, QString &lg_or,QPixmap &pixmap)
{
    path        = ui->lineEdit_pic_path->text();
    height      = ui->spinBox_pic_h->value();
    width       = ui->spinBox_pic_w->value();
    black_white = ui->checkBox_pic_black_white->isChecked();
    opacity     = ui->horizontalSlider_pic_opacity->value();
    lg_txt      = ui->lineEdit_lg_txt->text();
    lg_font     = ui->fontComboBox_lg_font->currentFont();
    lg_size     = ui->spinBox_lg_size->value();
    lg_color    = ui->toolButton_color->getColor();
    lg_pos      = ui->comboBox_lg_pos->currentText();
    lg_or       = ui->comboBox_lg_or->currentText();
    pixmap=s_file;

}

void FormPictures::chose_picture()
{

    QString home_path = QDir::homePath();

    QString s_path = setting.value("path_name").toString();
    if (s_path != "")  home_path = s_path;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open image"), home_path, tr("Image files (*.bmp, *.jpg, *.gif, *.png)"));

    QPixmap file_image (fileName);

    int h;
    int w;
    QString s;
     h = file_image.height();
     w = file_image.width();

     s = fileName;

     ui->spinBox_pic_h->setValue(h);
     ui->spinBox_pic_w->setValue(w);

     ui->lineEdit_pic_path->setText(s);

     setting.setValue("path_name", s);

  qDebug()<<"FORM: picture  changed, path ="  <<s;

}


void FormPictures::validation_ok(bool) {
    emit picture_changed();
}



void FormPictures::save_settings(bool)
{
    s_black_white = ui->checkBox_pic_black_white->isChecked();
    setting.setValue("FormPictures/black_white", s_black_white);



    s_lg_font     = ui->fontComboBox_lg_font->currentFont().family();
    setting.setValue("FormPictures/font", s_lg_font);

    s_lg_txt      = ui->lineEdit_lg_txt->text();
    setting.setValue("FormPictures/text", s_lg_txt);

    s_lg_size     = ui->spinBox_lg_size->value();
    setting.setValue("FormPictures/size", s_lg_size);

    s_lg_color    = ui->toolButton_color->getColor();
    setting.setValue("FormPictures/color", s_lg_color);

    s_lg_pos      = ui->comboBox_lg_pos->currentText();
    setting.setValue("FormPictures/position", s_lg_pos);

    s_lg_or       = ui->comboBox_lg_or->currentText();
    setting.setValue("FormPictures/orientation", s_lg_or);

}

void FormPictures::restore_settings(bool)
{


    s_black_white = setting.value("FormPictures/black_white").toBool();
    ui->checkBox_pic_black_white->setChecked(s_black_white);


    s_lg_font  =  setting.value("FormPictures/font").toString() ;
    ui->fontComboBox_lg_font->setCurrentText(s_lg_font);

    s_lg_txt   = setting.value("FormPictures/text").toString() ;
    ui->lineEdit_lg_txt->setText(s_lg_txt);

    s_lg_size  = setting.value("FormPictures/size").toInt() ;
    ui->spinBox_lg_size->setValue(s_lg_size);


    s_lg_color =   setting.value("FormPictures/color").toString() ;
    ui->toolButton_color->setColor(s_lg_color);


    s_lg_pos   =  setting.value("FormPictures/position").toString() ;
    ui->comboBox_lg_pos->setCurrentText(s_lg_pos);

    s_lg_or   =  setting.value("FormPictures/orientation").toString() ;
    ui->comboBox_lg_or->setCurrentText(s_lg_or);


}



// Load data
// ---------

void FormPictures::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<PicturesGraphicsItem*>(item))
    {
        PicturesGraphicsItem* castedItem = qgraphicsitem_cast<PicturesGraphicsItem*>(item);

        // Load data into the form
        QFont f = castedItem->getFont();

        ui->lineEdit_pic_path->setText(castedItem->getPath());
        ui->spinBox_pic_w->setValue(castedItem->getWidth());
        ui->spinBox_pic_h->setValue(castedItem->getHeight());
        ui->checkBox_pic_black_white->setChecked(castedItem->isGrayscale());
        ui->horizontalSlider_pic_opacity->setValue(castedItem->getOpacity());
        ui->lineEdit_lg_txt->setText(castedItem->getLegend());
        ui->fontComboBox_lg_font->setCurrentText(f.family());
        ui->spinBox_lg_size->setValue(f.pointSize());
        ui->toolButton_color->setColor(castedItem->getFontColor());

        QString pos = castedItem->getPosition();
        if (pos == "Left") {
            ui->comboBox_lg_pos->setCurrentIndex(0);
        }
        else if (pos == "Right")   {
            ui->comboBox_lg_pos->setCurrentIndex(1);
        }
        else if (pos == "HCenter") {
            ui->comboBox_lg_pos->setCurrentIndex(2);
        }
        else if (pos == "Justify") {
             ui->comboBox_lg_pos->setCurrentIndex(3);
        }
        else if (pos == "Top")     {
            ui->comboBox_lg_pos->setCurrentIndex(4);
        }
        else if (pos == "Bottom")  {
            ui->comboBox_lg_pos->setCurrentIndex(5);
        }
        else if (pos == "VCenter") {
            ui->comboBox_lg_pos->setCurrentIndex(6);
        }
        else if (pos == "Center")  {
            ui->comboBox_lg_pos->setCurrentIndex(7);
        }

    }
}


void FormPictures::load_position(QString s){

ui->comboBox_lg_pos->clear();

if (s == "Horizontal") {
    ui->comboBox_lg_pos->addItem(tr("Left"));
    ui->comboBox_lg_pos->addItem(tr("Right"));
    ui->comboBox_lg_pos->addItem(tr("HCenter"));
    ui->comboBox_lg_pos->addItem(tr("Justify"));
    ui->comboBox_lg_pos->addItem(tr("Top"));
    ui->comboBox_lg_pos->addItem(tr("Bottom"));
    ui->comboBox_lg_pos->addItem(tr("VCenter"));
    ui->comboBox_lg_pos->addItem(tr("Center"));
}
else if (s == "Vertical") {
    ui->comboBox_lg_pos->addItem(tr("Top Left"));
    ui->comboBox_lg_pos->addItem(tr("Top Right"));
    ui->comboBox_lg_pos->addItem(tr("Center Left"));
    ui->comboBox_lg_pos->addItem(tr("Center Right"));
    ui->comboBox_lg_pos->addItem(tr("Bottom Left"));
    ui->comboBox_lg_pos->addItem(tr("Bottom Right"));
     }
}


// Translation
// -----------

void FormPictures::retranslate()
{
    ui->retranslateUi(this);
}

void FormPictures::initWithImage(QPixmap file_image)
{
    /*QString fileName = v_path;

    /*QPixmap file_image (fileName);*/

    int h;
    int w;
    QString s;
     h = file_image.height();
     w = file_image.width();

     ui->spinBox_pic_h->setValue(h);
     ui->spinBox_pic_w->setValue(w);
     s_file=file_image;
}
