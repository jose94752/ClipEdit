#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>
#include "mainwindow.h"
#include "../Items/picturesgraphicsitem.h"
#include "../Items/textboxitem.h"

class Save
{
public:
    Save(QList<QGraphicsItem *>);
    Save(QList<QGraphicsItem *>,QString);
    //QDomElement setLayer()
    static QString verifyExtension(QString);
    static QString current_filename;
    static bool fileNameExists();

    void getPicturesGraphicsItemData(PicturesGraphicsItem *pictureGraphicsItem);
    void getTextBoxItem(TextBoxItem *textBoxItem);
private:
    QList<QGraphicsItem *> m_listItems;
    int countItems;
    void save();
};

#endif // SAVE_H
