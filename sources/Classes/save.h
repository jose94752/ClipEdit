#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>
#include "mainwindow.h"

class Save
{
public:
    Save(QList<QGraphicsItem *>);
    Save(QList<QGraphicsItem *>,QString);
    //QDomElement setLayer()
    static QString verifyExtension(QString);
    static QString current_filename;

private:
    QList<QGraphicsItem *> m_listItems;
    void save();
};

#endif // SAVE_H
