#include "save.h"
#include <QDebug>
#include <QSettings>
#include <QGraphicsItem>
#include <QRectF>
#include <mainwindow.h>
#include <QGraphicsPixmapItem>
#include "../Items/basegraphicitem.h"
#include "../Items/picturesgraphicsitem.h"
#include "../Items/textboxitem.h"
#include "../Items/numberedbulletgraphicitem.h"
#include "../Items/arrowsgraphicsitem.h"
#include "../Forms/formarrows.h"
#include "../Items/graphsgraphicsitem.h"

///class to save user projects to a file and to open a project from a file

QString Save::current_filename="";///static variable to store the current store file path and name

///constructor to open a project
Save::Save(QGraphicsScene* v_scene,QString v_filename)
{
    current_filename=v_filename;
    QList<QGraphicsItem *> l_list;
    m_listItems=l_list;
    m_scene=v_scene;
}

///constructor to save a project when filename is known
Save::Save(QList<QGraphicsItem *> v_listItems){
    m_listItems=v_listItems;
    m_scene=0;
}

///constructor to save a file when filename is unknown (save as)
Save::Save(QList<QGraphicsItem* > v_listItems,QString filename)
{
    current_filename=filename;
    m_listItems=v_listItems;
    m_scene=0;
}

///complete file extension .cle if extension is not present in the file name
QString Save::verifyExtension(QString fileName,QString ext)
{
    QStringList strlist=fileName.split(".");
    if(strlist[strlist.size()-1]!=ext){
        if(fileName[fileName.size()-1]!='.'){
            fileName=fileName.append(".");
        }
        fileName=fileName.append(ext);
    }
    return fileName;
}

///test if a filename is known by the software
bool Save::fileNameExists()
{
    if(current_filename==""){
        return false;
    }else{
        return true;
    }
}

///save function
void Save::save()
{
    QSettings settings(current_filename,QSettings::IniFormat);
    settings.clear();
    countItems=0;
    foreach(QGraphicsItem *item,m_listItems){
        int type=item->type();
        if(type>65535){
            settings.setValue(QString("item").append(QString::number(countItems)).append("/type"),QString::number(type));
        }
        QRectF rect=item->boundingRect();
        double x,y,width,height;
        rect.getRect(&x,&y,&width,&height);
        QPoint pos=item->pos().toPoint();
        x=pos.x();
        y=pos.y();
        if(type>65535){
            settings.setValue(QString("item").append(QString::number(countItems)).append("/baseGraphicItemType"),QString::number(type));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/x"),QString::number(x));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/y"),QString::number(y));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/width"),QString::number(width));
            settings.setValue(QString("item").append(QString::number(countItems)).append("/rectF/height"),QString::number(height));
        }
        ArrowsGraphicsItem *arrow;
        TextBoxItem *texteBox;
        NumberedBulletGraphicItem *bullet;
        PicturesGraphicsItem *picturesItem;
        GraphsGraphicsItem *graphsItem;
        switch(type)
        {
            case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                //code
            break;
            case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
                arrow=(ArrowsGraphicsItem*)item;
                arrow->getParameters(&settings,countItems);
            break;
            case BaseGraphicItem::NumberedBulletGraphicsItem:
                bullet=(NumberedBulletGraphicItem*)item;
                bullet->getParameters(&settings,countItems);
            break;
            case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
                //code
            break;
            case BaseGraphicItem::ChartGraphicsItem:
                graphsItem=(GraphsGraphicsItem*)item;
                graphsItem->getParameters(&settings,countItems);
        break;
        }

        if(type>65535){
            countItems++;
        }
    }
    settings.setValue("nbItems",countItems);
}

//open project function
void Save::open()
{
    int i;
    QSettings settings(current_filename,QSettings::IniFormat);
    countItems=settings.value("nbItems").toInt();
    for(i=0;i<countItems;i++){
        QVariant varType=settings.value(QString("item").append(QString::number(i)).append("/baseGraphicItemType"));
        QVariant varX=settings.value(QString("item").append(QString::number(i)).append("/rectF/x"));
        QVariant varY=settings.value(QString("item").append(QString::number(i)).append("/rectF/y"));
        QVariant varWidth=settings.value(QString("item").append(QString::number(i)).append("/rectF/width"));
        QVariant varHeight=settings.value(QString("item").append(QString::number(i)).append("/rectF/height"));
        int type=varType.toInt();
        double x=varX.toDouble();
        double y=varY.toDouble();
        double width=varWidth.toDouble();
        double height=varHeight.toDouble();
        QPointF pointf(QPoint(x,y));
        QRectF rect(x,y,width,height);
        ArrowsGraphicsItem *arrow;
        TextBoxItem *texteBox;
        NumberedBulletGraphicItem *bullet;
        PicturesGraphicsItem *picturesItem;
        GraphsGraphicsItem *graphsItem;
        switch(type)
        {
            case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                //texteBox=setTextBoxItem(&settings,i);
                //m_scene->addItem(texteBox);
            break;
            case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
                arrow=new ArrowsGraphicsItem(new FormArrows());
                arrow->setParameters(&settings,i);
                arrow->setPos(pointf);
                arrow->setRect(QRectF(0,0,width,height));
                m_scene->addItem(arrow);
            break;
            case BaseGraphicItem::NumberedBulletGraphicsItem:
                //bullet=setNumberedBulletGraphicItem();
                bullet=new NumberedBulletGraphicItem();
                bullet->setParameters(&settings,i);
                bullet->setPos(pointf);
                m_scene->addItem(bullet);
            break;
            case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
                //picturesItem=setPicturesGraphicsItems(&settings,i);
                //m_scene->addItem(picturesItem);
            break;
            case BaseGraphicItem::ChartGraphicsItem:
                graphsItem=new GraphsGraphicsItem();
                graphsItem->setParameters(&settings,i);
                graphsItem->setPos(pointf);
                m_scene->addItem(graphsItem);
            break;
        }
    }
}

