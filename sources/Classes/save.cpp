#include "save.h"
#include <QDebug>
#include <QSettings>
#include <QGraphicsItem>
#include <QRectF>
#include <mainwindow.h>
#include <QGraphicsPixmapItem>
#include "../Items/picturesgraphicsitem.h"
#include "../Items/textboxitem.h"
#include "../Items/numberedbulletgraphicitem.h"
#include "../Items/arrowsgraphicsitem.h"
#define ImageGraphicsItem 65536
#define TextBoxGraphicsItem 65537
#define EdgeItem 65539
#define BulletsItem 65542
#define PicturesItems 65538

QString Save::current_filename="";

Save::Save(QGraphicsScene* v_scene,QString v_filename)
{
    current_filename=v_filename;
    QList<QGraphicsItem *> l_list;
    m_listItems=l_list;
    m_scene=v_scene;
}

Save::Save(QList<QGraphicsItem *> v_listItems){
    m_listItems=v_listItems;
    m_scene=0;
}

Save::Save(QList<QGraphicsItem* > v_listItems,QString filename)
{
    current_filename=filename;
    m_listItems=v_listItems;
    m_scene=0;
}

QString Save::verifyExtension(QString fileName)
{
    QStringList strlist=fileName.split(".");
    if(strlist[strlist.size()-1]!="cle"){
        if(fileName[fileName.size()-1]!='.'){
            fileName=fileName.append(".");
        }
        fileName=fileName.append("cle");
    }
    return fileName;
}

bool Save::fileNameExists()
{
    if(current_filename==""){
        return false;
    }else{
        return true;
    }
}

void Save::getPicturesGraphicsItemData(PicturesGraphicsItem *pictureGraphicsItem){
    //qDebug()<<"picture graphique item";
}

void Save::getTextBoxItem(TextBoxItem *textBoxItem){
    //qDebug()<<"text boxes";
}

void Save::getArrowGraphicsItem(ArrowsGraphicsItem *)
{
    //qDebug() arrows graphics items
}

void Save::getBulletsGraphicsItems(NumberedBulletGraphicItem *)
{
    //code
}

void Save::getPicturesGraphicsItems(PicturesGraphicsItem *)
{
    //code
}

int isValidIndex(int type){
    int res=0;
    if(type==ImageGraphicsItem){
        res=1;
    }
    if(type==TextBoxGraphicsItem){
        res=1;
    }
    if(type==EdgeItem){
        res=1;
    }
    if(type==BulletsItem){
        res=1;
    }
    if(type==PicturesItems){
        res=1;
    }
    return res;
}

void Save::save()
{
    QSettings settings(current_filename,QSettings::IniFormat);
    countItems=0;
    foreach(QGraphicsItem *item,m_listItems){
        int type=item->type();
        qDebug()<<type;
        QRectF rect=item->boundingRect();
        double x,y,width,height;
        rect.getRect(&x,&y,&width,&height);
        if(type>65535 && (x!=0 || y!=0 || width!=0 || height!=0)){
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

        if(type==EdgeItem  && (x!=0 || y!=0 || width!=0 || height!=0)){
             getArrowGraphicsItem((ArrowsGraphicsItem*)item);
        }

        if(type==BulletsItem  && (x!=0 || y!=0 || width!=0 || height!=0)){
            getBulletsGraphicsItems((NumberedBulletGraphicItem *)item);
        }

        if(type==PicturesItems  && (x!=0 || y!=0 || width!=0 || height!=0)){
            getPicturesGraphicsItems((PicturesGraphicsItem *)item);
        }

        if(type>65535 && (x!=0 || y!=0 || width!=0 || height!=0)){
            countItems++;
        }
    }
    settings.setValue("nbItems",QString::number(countItems));
}
