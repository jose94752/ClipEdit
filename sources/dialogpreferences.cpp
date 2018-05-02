/*
================================================
* File:         dialogpreferences.cpp
* Project:      ClipEdit
* Creation:     30/04/2018
* Brief:        Settings dialog
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QSettings>

#include "dialogpreferences.h"
#include "ui_dialogpreferences.h"

// Constructor, destructor
// -----------------------

DialogPreferences::DialogPreferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem(QIcon(":/icons/icons/lang-en-icon.png"), "English", "en");
    ui->comboBoxLanguage->addItem(QIcon(":/icons/icons/lang-fr-icon.png"), "Français", "fr");
    ui->comboBoxLanguage->addItem(QIcon(":/icons/icons/lang-de-icon.png"), "Deutsch", "de");

    // Load from settings
    QSettings s;
    QString lang = s.value("Settings/lang", "en").toString();
    int idx = ui->comboBoxLanguage->findData(lang);
    ui->comboBoxLanguage->setCurrentIndex(idx);
}

DialogPreferences::~DialogPreferences()
{
    delete ui;
}

// Slots
// -----

void DialogPreferences::accept ()
{
    QString lang = ui->comboBoxLanguage->currentData().toString();

    // Save in settings
    QSettings s;
    s.setValue("Settings/lang", lang);
    qDebug () << "lang == " << lang << "\n";
    emit preferencesChanged(lang);
    QDialog::accept();
}

void DialogPreferences::reject()
{
    QDialog::reject();
}
