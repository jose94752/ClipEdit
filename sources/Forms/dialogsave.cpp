/*
================================================
* File:         dialogsave.cpp
* Project:      ClipEdit
* Creation:     26/04/2018
* Brief:        Simple dialog for project saving
================================================
*/


// Includes
// --------

#include <QFileDialog>
#include <QMessageBox>

#include "dialogsave.h"
#include "ui_dialogsave.h"
#include "Classes/save.h"

DialogSave::DialogSave(QList<QGraphicsItem*> v_items,QGraphicsRectItem *v_rectItem,QWidget* parent)
    :   QDialog(parent),
        ui(new Ui::DialogSave)
{
    ui->setupUi(this);

    m_items = v_items;
    connect(ui->pushButton_yes, SIGNAL(clicked(bool)), this, SLOT(slotSaveApproved()));
    connect(ui->pushButton_no, SIGNAL(clicked(bool)), this, SLOT(close()));
    m_rectItem=v_rectItem;
}

DialogSave::~DialogSave()
{
    delete ui;
}

// Slots
// -----

void DialogSave::slotSaveApproved()
{
    if (Save::fileNameExists())
    {
        Save save(m_items,m_rectItem->rect(),m_rectItem->brush().color());
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "project.cle", tr("ClipEdit File (*.cle)"));

        if (fileName != "")
        {
            QString extfilename = Save::verifyExtension(fileName, "cle");
            QFile fileToSave(extfilename);

            if (fileName!=extfilename && fileToSave.exists())
            {
                QMessageBox::warning(this, tr("Warning"), tr("File %1 already exists").arg(fileToSave.fileName()));
            }
            else
            {
                Save save(m_items,m_rectItem->rect(),extfilename);
                //save.save();
            }
        }
    }

    close();
}
