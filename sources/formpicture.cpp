#include "formpicture.h"
#include "ui_formpicture.h"
#include <QString>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QFileDialog>

FormPicture::FormPicture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPicture)
{
    ui->setupUi(this);

    connect (ui->pushButton_pic_ch, SIGNAL(clicked(bool)), this, SLOT(recup_image()));

}

FormPicture::~FormPicture()
{
    delete ui;
}

void FormPicture::recup_image(){

  qDebug() << "Debut 1 ";

  QString fileName = QFileDialog::getOpenFileName(
              this,  tr("Ouvrir une image"), "/home/formation/Images", tr("image (*.*)")
          );

   qDebug () << "file name : "  <<fileName;

  QFile file(fileName);
  qDebug () << "file name : "  <<fileName;

/*
   QFile file(fileName);
   qDebug () << "file name : "  <<fileName;

   if (!file.open(QIODevice::ReadWrite))
   //if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QString string(file.readAll());
   file.close();
*/
  //  ui->textEdit->setText(string);
}
