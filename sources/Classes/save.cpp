#include "save.h"
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>

QString Save::current_filename="";

Save::Save(){
    QDomDocument domDoc;
    QDomElement project=domDoc.createElement("clipEditProject");
    domDoc.appendChild(project);
    QString strdom=domDoc.toString();
    QFile file(current_filename);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << strdom;
    file.close();

}

Save::Save(QString filename)
{
    current_filename=filename;
    Save();
}

QString Save::verifyExtension(QString fileName)
{
    QStringList strlist=fileName.split(".");
    if(strlist[strlist.size()-1]!="clipEdit"){
        if(fileName[fileName.size()-1]!='.'){
            fileName=fileName.append(".");
        }
        fileName=fileName.append("clipEdit");
    }
    return fileName;
}
