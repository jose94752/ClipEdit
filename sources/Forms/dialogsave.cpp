#include <QFileDialog>
#include "Forms/dialogfilealreadyexists.h"
#include "dialogsave.h"
#include "ui_dialogsave.h"
#include "Classes/save.h"

DialogSave::DialogSave(QWidget *parent,QList<QGraphicsItem *> v_items) :
    QDialog(parent),
    ui(new Ui::DialogSave)
{
    ui->setupUi(this);
    m_items=v_items;
    connect(ui->pushButton_yes,SIGNAL(clicked(bool)),this,SLOT(slotSaveApproved()));
    connect(ui->pushButton_no,SIGNAL(clicked(bool)),this,SLOT(close()));
}

DialogSave::~DialogSave()
{
    delete ui;
}

void DialogSave::slotSaveApproved()
{
    if(Save::fileNameExists()){
        Save save(m_items);
    }else{
        QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),"project.cle",tr("ClipEdit File (*.cle)"));
        if(fileName!=""){
            QString extfilename=Save::verifyExtension(fileName);
            QFile fileToSave(extfilename);
            if(fileName!=extfilename && fileToSave.exists()){
                DialogFileAlreadyExists dfae;
                dfae.exec();
            }else{
                Save save(m_items,extfilename);
            }
        }
    }
    close();
}
