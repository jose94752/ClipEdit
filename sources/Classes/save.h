#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>
#include "mainwindow.h"
#include "picturesgraphicsitem.h"
#include "textboxitem.h"

class Save
{
public:
    Save(QList<QGraphicsItem *>);
    Save(QList<QGraphicsItem *>,QString);
    //QDomElement setLayer()
    static QString verifyExtension(QString);
    static QString current_filename;

    void getPicturesGraphicsItemData(PicturesGraphicsItem *pictureGraphicsItem);
    void getTextBoxItem(TextBoxItem *textBoxItem);
private:
    QList<QGraphicsItem *> m_listItems;
    void save();
};

#endif // SAVE_H
