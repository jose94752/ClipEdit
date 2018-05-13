#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QGraphicsScene>

class Save
{
public:
    Save(QGraphicsScene*,QString);
    Save(QList<QGraphicsItem *>,QRectF,QRectF,QColor,bool);
    Save(QList<QGraphicsItem *>,QString,QRectF,QRectF, QColor,bool);

    static QString verifyExtension(QString,QString);
    static QString current_filename;
    static bool fileNameExists();

    void save();
    QGraphicsRectItem* open();

private:
    QList<QGraphicsItem *> m_listItems;
    QGraphicsScene *m_scene;
    int countItems;

    QColor m_backgroundColor;
    QRectF m_globalRectF;
    QRectF m_sceneRectF;
    bool m_resized;
};

#endif // SAVE_H
