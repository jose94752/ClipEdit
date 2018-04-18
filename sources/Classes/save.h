#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>

class Save
{
public:
    Save();
    Save(QString);
    //QDomElement setLayer()
    static QString verifyExtension(QString);
    static QString current_filename;
};

#endif // SAVE_H
