#include "save.h"
#include <QDebug>
#include <QSettings>
#include <QGraphicsItem>
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

}

void Save::getTextBoxItem(TextBoxItem *textBoxItem){

}

void Save::save()
{
    QSettings settings(current_filename,QSettings::IniFormat);
    settings.setValue("toto","Hello World");
    //qDebug()<<"taille liste"<<m_listItems.length();
    foreach(QGraphicsItem *item,m_listItems){
        int type=item->type();
        if(type==ImageGraphicsItem){
             getPicturesGraphicsItemData((PicturesGraphicsItem*)item);
             qDebug()<<"Graphique";
        }
        if(type==TextBoxGraphicsItem){
             getTextBoxItem((TextBoxItem*)item);
              qDebug()<<"Image";
        }
    }
}
