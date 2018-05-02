#ifndef __DIALOGPREERENCES_H
#define __DIALOGPREFERENCES_H
#include "dialogpreferences.h"
#include "ui_dialogpreferences.h"
#include <qdebug.h>
#include <qsettings.h>

DialogPreferences::DialogPreferences(QWidget *parent, QString lang) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{
    ui->setupUi(this);
    ui->comboBox_language->addItem("English","en");
    ui->comboBox_language->addItem("Français","fr");
    ui->comboBox_language->addItem("Japanese","jap");
    ui->comboBox_language->addItem("Oriental Bedloujikistanese","ob");
    ui->comboBox_language->addItem("Russian","ru");
    ui->comboBox_language->setCurrentText (lang);
    //ui->comboBox_language->setCurrentIndex("en");
}

DialogPreferences::~DialogPreferences()
{
    delete ui;
}

void DialogPreferences::accept () {
    //QString lang =  ui->comboBox_language->currentData().toString();
    QString lang =  ui->comboBox_language->currentText();
    emit signal_language (lang);
    QDialog::accept ();
}

void DialogPreferences::reject () {
    qDebug () << "DialogPreference : reject\n";
    QDialog::reject();
}

#endif
