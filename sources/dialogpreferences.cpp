#ifndef __DIALOGPREERENCES_H
#define __DIALOGPREFERENCES_H
#include "dialogpreferences.h"
#include "ui_dialogpreferences.h"
#include <qdebug.h>

DialogPreferences::DialogPreferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{
    ui->setupUi(this);
    //connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    //connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

DialogPreferences::~DialogPreferences()
{
    delete ui;
}

void DialogPreferences::accept () {
    qDebug () << "DialogPreference : accept\n";
    //lang = ui->comboBox_language->currentData();
    lang_e lang;
    lang = (lang_e) ui->comboBox_language->currentIndex();
    qDebug () << "\tlangue choisie :" << lang << "\n";
    emit(language (lang));
    QDialog::accept ();
}

void DialogPreferences::reject () {
    qDebug () << "DialogPreference : reject\n";
    QDialog::reject();
}

#endif
