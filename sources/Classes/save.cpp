#include "save.h"
#include <QDebug>
#include <QSettings>
#include <QGraphicsItem>
#include <QRectF>
#include <mainwindow.h>
#include "picturesgraphicsitem.h"
#include "textboxitem.h"

#define ImageGraphicsItem 65536
#define TextBoxGraphicsItem 65537

QString Save::current_filename="";

Save::Save(QList<QGraphicsItem *> v_listItems){
    m_listItems=v_listItems;
    save();
}

Save::Save(QList<QGraphicsItem* > v_listItems,QString filename)
{
    current_filename=filename;
    m_listItems=v_listItems;
    save();
}

QString Save::verifyExtension(QString fileName)
{
    QStringList strlist=fileName.split(".");
    if(strlist[strlist.size()-1]!="ini"){
        if(fileName[fileName.size()-1]!='.'){
            fileName=fileName.append(".");
        }
        fileName=fileName.append("ini");
    }
    return fileName;
}

void Save::getPicturesGraphicsItemData(PicturesGraphicsItem *pictureGraphicsItem){
    //qDebug()<<"picture graphique item";
}

void Save::getTextBoxItem(TextBoxItem *textBoxItem){
    //qDebug()<<"text boxes";
}

void Save::save()
{
    QSettings settings(current_filename,QSettings::IniFormat);
    countItems=0;
    foreach(QGraphicsItem *item,m_listItems){
        int type=item->type();
        QRectF rect=item->boundingRect();
        double x,y,width,height;
        rect.getRect(&x,&y,&width,&height);
        if((type==ImageGraphicsItem || type==TextBoxGraphicsItem) && (x!=0 || y!=0 || width!=0 || height!=0)){
            settings.setValue(QString("item").append(QString::number(countItems)).append("/type"),QString::number(type));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/x"),QString::number(x));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/y"),QString::number(y));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/width"),QString::number(width));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/height"),QString::number(height));
        }

        if(type==ImageGraphicsItem  && (x!=0 || y!=0 || width!=0 || height!=0)){
             getPicturesGraphicsItemData((PicturesGraphicsItem*)item);
        }
        if(type==TextBoxGraphicsItem  && (x!=0 || y!=0 || width!=0 || height!=0)){
             getTextBoxItem((TextBoxItem*)item);
        }
        if((type==ImageGraphicsItem || type==TextBoxGraphicsItem) && (x!=0 || y!=0 || width!=0 || height!=0)){
            countItems++;
        }
    }
}
