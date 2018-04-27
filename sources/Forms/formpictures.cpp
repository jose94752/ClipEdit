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



      connect (ui->pushButton_lg_ok,  SIGNAL(clicked(bool)), this, SLOT(legend_ok(bool)));

      connect (ui->toolButton_path,   SIGNAL(pressed()),     this, SLOT(chose_picture()));

      connect (ui->checkBox_pic_black_white, SIGNAL(released()), this, SLOT(picture_modification()));


      connect (ui->spinBox_pic_w, SIGNAL(editingFinished())  , this, SLOT(picture_modification_w()));
      connect (ui->spinBox_pic_h, SIGNAL(editingFinished())  , this, SLOT(picture_modification_h()));

    ui->comboBox_lg_pos->addItem(tr("Left"));
    ui->comboBox_lg_pos->addItem(tr("Right"));
    ui->comboBox_lg_pos->addItem(tr("HCenter"));
    ui->comboBox_lg_pos->addItem(tr("Justify"));
    ui->comboBox_lg_pos->addItem(tr("Top"));
    ui->comboBox_lg_pos->addItem(tr("Bottom"));
    ui->comboBox_lg_pos->addItem(tr("VCenter"));
    ui->comboBox_lg_pos->addItem(tr("Center"));

}


FormPictures::~FormPictures()
{
    delete ui;
}


void FormPictures::getPictureValues(QString &path, int &height, int &width, bool &w_h_fixed, char &w_h, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos)
{
    path        = ui->lineEdit_pic_path->text();
    height      = ui->spinBox_pic_h->value();
    width       = ui->spinBox_pic_w->value();
    w_h_fixed   = ui->checkBox_pic_fx->isChecked();
    w_h         = w_h1;
    black_white = ui->checkBox_pic_black_white->isChecked();
    opacity     = ui->horizontalSlider_pic_opacity->value();
    lg_txt      = ui->lineEdit_lg_txt->text();
    lg_font     = ui->fontComboBox_lg_font->currentFont();
    lg_size     = ui->spinBox_lg_size->value();
    lg_color    = ui->toolButton_color->getColor();
    lg_pos      = ui->comboBox_lg_pos->currentText();

}

void FormPictures::chose_picture()
{
    QString grp     = "m2i_patrol";
    QString prj     = "clipart_picture";
    QString grp_prj = grp + "/" + prj;

    QSettings setting;

    QString s_path = setting.value(grp_prj).toString();

    //QSettings(const QString &fileName, Format format, QObject *parent = Q_NULLPTR)
    //QColor color = settings.value("DataPump/bgcolor").value<QColor>();

    QString home_path = QDir::homePath();

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

  qDebug()<<"FORM: picture  changed";
     emit picture_changed();
  //    ui->lineEdit_pic_path->setText(" ");
}


void FormPictures::picture_modification()
{
     emit picture_changed();
}

void FormPictures::picture_modification_w()
{
    emit picture_changed();
    w_h1 = 'w';
    emit picture_changed_w_h(w_h1);

     qDebug() <<"form  W : w_h:"  <<w_h1  ;
}

void FormPictures::picture_modification_h()
{
    emit picture_changed();
    w_h1 = 'h';
    emit picture_changed_w_h(w_h1);

    qDebug() <<" form H : w_h:"  <<w_h1 ;
}


void FormPictures::legend_ok(bool)
{
    emit picture_changed();
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
        ui->checkBox_pic_fx->setChecked(castedItem->hasFixedRatio());
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
