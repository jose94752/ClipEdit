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
    void save();
    void open();
private:
    QList<QGraphicsItem *> m_listItems;
    QGraphicsScene *m_scene;
    int countItems;
};

#endif // SAVE_H
