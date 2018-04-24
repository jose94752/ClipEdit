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

///transform TextBoxItem for saving
/*void Save::getTextBoxItem(TextBoxItem *textBoxItem,QSettings* settings){
    qDebug()<<"text boxes";
}

///transform ArrowsGraphicsItem for saving
void Save::getArrowGraphicsItem(ArrowsGraphicsItem *arrow,QSettings* settings)
{
    qDebug()<< "arrows graphics items";
    bool WithoutAnchorPoint;
    bool OneAnchorPoint;
    bool TwoAnchorPoints;
    int ArrowWidth;
    int ArrowHeight;
    int r,g,b,a;
    int LineThickness, SizeHeadTypeChoice;
    QColor ArrowOutlineColor;
    QColor ArrowFillColor;
    FormArrows *formArrows=arrow->getFormArrow();
    formArrows->GetInfosArrows(WithoutAnchorPoint,OneAnchorPoint,TwoAnchorPoints,ArrowWidth,ArrowHeight,ArrowOutlineColor,ArrowFillColor,LineThickness,SizeHeadTypeChoice);
    settings->setValue(QString("item").append(QString::number(countItems)).append("/WithoutAnchorPoint"),QString::number(WithoutAnchorPoint));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/OneAnchorPoint"),QString::number(OneAnchorPoint));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/TwoAnchorPoints"),QString::number(TwoAnchorPoints));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowWidth"),QString::number(ArrowWidth));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowHeight"),QString::number(ArrowHeight));
    ArrowOutlineColor.getRgb(&r,&g,&b,&a);
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/r"),QString::number(r));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/g"),QString::number(g));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/b"),QString::number(b));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/a"),QString::number(a));
    ArrowFillColor.getRgb(&r,&g,&b,&a);
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowFillColor/r"),QString::number(r));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowFillColor/g"),QString::number(g));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowFillColor/b"),QString::number(b));
    settings->setValue(QString("item").append(QString::number(countItems)).append("/ArrowFillColor/a"),QString::number(a));
    settings->setValue(QString("item").append(QString::number(countItems)).append("LineThickness"),QString::number(LineThickness));
    settings->setValue(QString("item").append(QString::number(countItems)).append("SizeHeadTypeChoice"),QString::number(SizeHeadTypeChoice));
}

///transform NumberedBulletGraphicItem for saving
void Save::getBulletsGraphicsItems(NumberedBulletGraphicItem *,QSettings* settings)
{
    qDebug()<<"NumberedBulletGraphicItem ";
}

///transform PicturesGraphicsItem for saving
void Save::getPicturesGraphicsItems(PicturesGraphicsItem *,QSettings* settings)
{
    qDebug()<<"PicturesGraphicsItem";
}

///set data for differents forms
void Save::setFormsPoints(FormArrows *f1, FormCharts *f2, FormCliparts *f3, FormLayers *f4, FormNumberedBullets *f5, FormPictures *f6, FormScreenshots *f7, FormTextBoxes *f8)
{
    m_formArrows=f1;
    m_formCharts=f2;
    m_formCliparts=f3;
    m_formLayers=f4;
    m_formBullets=f5;
    m_formPicture=f6;
    m_formScreenshots=f7;
    m_formTextBoxes=f8;
}

TextBoxItem* Save::setTextBoxItem(QSettings *settings,int i)
{
    QMap<QString, QVariant> data = m_formTextBoxes->getInfos();
    return new TextBoxItem(data);
    //m_scene.addItem(new TextBoxItem(data));
}

ArrowsGraphicsItem* Save::setArrowGraphicsItem(QSettings *settings,int i)
{
    bool WithoutAnchorPoint;
    bool OneAnchorPoint;
    bool TwoAnchorPoints;
    int ArrowWidth;
    int ArrowHeight;
    int r,g,b,a;
    int LineThickness, SizeHeadTypeChoice;
    WithoutAnchorPoint=settings->value(QString("item").append(QString::number(countItems)).append("/WithoutAnchorPoint")).toBool();
    OneAnchorPoint=settings->value(QString("item").append(QString::number(countItems)).append("/OneAnchorPoint")).toBool();
    TwoAnchorPoints=settings->value(QString("item").append(QString::number(countItems)).append("/TwoAnchorPoints")).toBool();
    ArrowWidth=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowWidth")).toInt();
    ArrowHeight=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowHeight")).toInt();
    QColor ArrowOutlineColor(r,g,b,a);
    r=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/r")).toInt();
    g=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/g")).toInt();
    b=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/b")).toInt();
    a=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/a")).toInt();
    r=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/r")).toInt();
    g=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/g")).toInt();
    b=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/b")).toInt();
    a=settings->value(QString("item").append(QString::number(countItems)).append("/ArrowOutlineColor/a")).toInt();
    QColor ArrowFillColor(r,g,b,a);
    LineThickness=settings->value(QString("item").append(QString::number(countItems)).append("LineThickness")).toInt();
    SizeHeadTypeChoice=settings->value(QString("item").append(QString::number(countItems)).append("SizeHeadTypeChoice")).toInt();
    FormArrows formArrows();
    //formArrows.fillColorArrowChanged(ArrowFillColo);
    //formArrows.outlineColorArrowChanged(ArrowOutlineColor);
    //ArrowsGraphicsItem *ArrowsGraphicsItem=new ArrowsGraphicsItem(formArrows());
    return new ArrowsGraphicsItem(new FormArrows());
}

NumberedBulletGraphicItem* Save::setBulletsGraphicsItems(QSettings *settings,int i)
{
    int from (0), to (0), taille (0);
    int shape (0);
    QColor bulletcolor, numbercolor;
    QFont qfont;
    //m_formBullets.get_info(from, to, taille,  shape, bulletcolor, numbercolor, qfont);
    NumberedBulletGraphicItem * numberedBulletGraphicItem (NULL);
    qDebug () << "\tfrom == " << from << "\n";
    qDebug () << "\tto == " << to << "\n";
    int numbullet (from);
    qreal posx (0), posy (50), delta (100);
    for (; numbullet != to+1; ++numbullet) {
      numberedBulletGraphicItem = new NumberedBulletGraphicItem (numbullet, (NumberedBulletGraphicItem::shape_e)shape, bulletcolor, numbercolor, qfont, taille);
      numberedBulletGraphicItem->setPos(posx, posy);
      return numberedBulletGraphicItem;
    }
}

PicturesGraphicsItem* Save::setPicturesGraphicsItems(QSettings *settings,int i)
{
    return new PicturesGraphicsItem (m_formPicture);
}

GraphsGraphicsItem* Save::setCharts(QSettings *, int)
{
    GraphsInfo newGraphsInfo;
    GraphsGraphicsItem *g = new GraphsGraphicsItem();
    g->setInfos(newGraphsInfo);
    return g;
}

///save function
void Save::save()
{
    QSettings settings(current_filename,QSettings::IniFormat);
    settings.clear();
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

        switch(type)
        {
            case BaseGraphicItem::Type::TextBoxGraphicsItem:
                getTextBoxItem((TextBoxItem*)item,&settings);
            break;
            case BaseGraphicItem::Type::ArrowGraphicsItem:
                getArrowGraphicsItem((ArrowsGraphicsItem*)item,&settings);
            break;
            case BaseGraphicItem::NumberedBulletGraphicsItem:
                getBulletsGraphicsItems((NumberedBulletGraphicItem *)item, &settings);
            break;
            case BaseGraphicItem::Type::ImageGraphicsItem:
                getPicturesGraphicsItems((PicturesGraphicsItem *)item, &settings);
            break;
        }

        if(type>65535 && (x!=0 || y!=0 || width!=0 || height!=0)){
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
    qDebug()<<QString::number(countItems);
    for(i=0;i<countItems;i++){
        QVariant varType=settings.value(QString("item").append(QString::number(i)).append("/type"));
        QVariant varX=settings.value(QString("item").append(QString::number(i)).append("/rectF/x"));
        QVariant varY=settings.value(QString("item").append(QString::number(i)).append("/rectF/y"));
        QVariant varWidth=settings.value(QString("item").append(QString::number(i)).append("/rectF/width"));
        QVariant varHeight=settings.value(QString("item").append(QString::number(i)).append("/rectF/height"));
        int type=varType.toInt();
        double x=varX.toDouble();
        double y=varY.toDouble();
        double width=varWidth.toDouble();
        double height=varHeight.toDouble();
        QRectF rect(x,y,width,height);
        ArrowsGraphicsItem *arrow;
        TextBoxItem *texteBox;
        NumberedBulletGraphicItem *bullet;
        PicturesGraphicsItem *picturesItem;
        GraphsGraphicsItem *graphsItem;
        switch(type)
        {
            case BaseGraphicItem::Type::TextBoxGraphicsItem:
                texteBox=setTextBoxItem(&settings,i);
                m_scene->addItem(texteBox);
            break;
            case BaseGraphicItem::Type::ArrowGraphicsItem:
                arrow=setArrowGraphicsItem(&settings,i);
                m_scene->addItem(arrow);
            break;
            case BaseGraphicItem::NumberedBulletGraphicsItem:
                bullet=setBulletsGraphicsItems(&settings,i);
                m_scene->addItem(bullet);
            break;
            case BaseGraphicItem::Type::ImageGraphicsItem:
                picturesItem=setPicturesGraphicsItems(&settings,i);
                m_scene->addItem(picturesItem);
            break;
            case BaseGraphicItem::ChartGraphicsItem:
                graphsItem=setCharts(&settings,i);
                m_scene->addItem(graphsItem);
            break;
        }
    }*/
//}

