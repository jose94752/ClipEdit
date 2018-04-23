#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "Items/picturesgraphicsitem.h"
#include "Items/textboxitem.h"
#include "Items/arrowsgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/picturesgraphicsitem.h"
#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"
#define ImageGraphicsItem 65536
#define TextBoxGraphicsItem 65537
#define EdgeItem 65539
#define BulletsItem 65542
#define PicturesItems 65538

class Save
{
public:
    Save(QGraphicsScene*,QString);
    Save(QList<QGraphicsItem *>);
    Save(QList<QGraphicsItem *>,QString);
    //QDomElement setLayer()
    static QString verifyExtension(QString);
    static QString current_filename;
    static bool fileNameExists();
    void getPicturesGraphicsItemData(PicturesGraphicsItem*);
    void getTextBoxItem(TextBoxItem*);
    void getArrowGraphicsItem(ArrowsGraphicsItem*);
    void getBulletsGraphicsItems(NumberedBulletGraphicItem*);
    void getPicturesGraphicsItems(PicturesGraphicsItem*);
    void setFormsPoints(FormArrows*,FormCharts*,FormCliparts*,FormLayers*,FormNumberedBullets *,FormPictures*,FormScreenshots*,FormTextBoxes*);
    void save();
    void open();
private:
    QList<QGraphicsItem *> m_listItems;
    QGraphicsScene *m_scene;
    int countItems;
    FormArrows *m_formArrows;
    FormCharts *m_formCharts;
    FormCliparts *m_formCliparts;
    FormLayers *m_formLayers;
    FormNumberedBullets *m_formBullets;
    FormPictures *m_formPicture;
    FormScreenshots *m_formScreenshots;
    FormTextBoxes *m_formTextBoxes;
};

#endif // SAVE_H
