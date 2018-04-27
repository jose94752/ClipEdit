/*
=========================================================
* File:         formnumberedbullets.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create NumberedBulletGraphicItem
=========================================================
*/

// Includes
// --------

#include <QDebug>
#include <QSettings>
#include <QColor>

#include "formnumberedbullets.h"
#include "ui_formnumberedbullets.h"
#include "../Items/numberedbulletgraphicitem.h"

// Constructor, destructor
// -----------------------

FormNumberedBullets::FormNumberedBullets(QWidget *parent)
    :   BaseForm(parent), ui(new Ui::FormNumberedBullets)
{
    ui->setupUi(this);
    loadDefaultTheme();

    connect(ui->pushButton_saveBulletTheme, SIGNAL(clicked(bool)), this, SLOT(saveDefaultTheme()));
    connect(ui->pushButton_loadBulletTheme, SIGNAL(clicked(bool)), this, SLOT(loadDefaultTheme()));
}

FormNumberedBullets::~FormNumberedBullets()
{
    delete ui;
}

// Getters
// -------

//for now shape : 0-> circle
//                1-> rectangle
//                2-> rounded rectangle
void FormNumberedBullets::get_info (int& from, int& to, int& taille, int& shape, QColor& bulletcolor, QColor& numbercolor, QFont& font) const
{
    from = ui->spinBox_From->value();
    to = ui->spinBox_To->value ();
    taille = ui->spinBox_Size->value();
    shape = ui->comboBox_Shape->currentIndex();
    bulletcolor = ui->ColorButton_BulletColor->getColor();
    numbercolor = ui->ColorBullet_NumberColor->getColor();
    font = ui->fontComboBox->currentFont();
}

QPushButton *FormNumberedBullets::getGoPushButton()
{
    return ui->pushButtonCreateBullet;
}

// Slots
// -----

void FormNumberedBullets::saveDefaultTheme () const
{
    QSettings s;
    int from(0), to(0), taille(0);
    int shape;
    QFont qf;
    QColor numbercolor, bulletcolor;

    get_info(from, to, taille,  shape, bulletcolor, numbercolor, qf);
    s.setValue("FormNumberedBullets/from", from);
    s.setValue("FormNumberedBullets/to", to);
    s.setValue("FormNumberedBullets/size",taille );
    s.setValue("FormNumberedBullets/bulletcolor",bulletcolor.name ());
    s.setValue("FormNumberedBullets/numbercolor",numbercolor.name ());
    s.setValue("FormNumberedBullets/font",ui->fontComboBox->currentIndex());
    s.setValue("FormNumberedBullets/shape", (int) shape);
}

void FormNumberedBullets::loadDefaultTheme()
{
    QSettings q;
    int from(1), to(1), taille(1);
    from = q.value("FormNumberedBullets/from", from).toInt();
    to = q.value("FormNumberedBullets/to", to).toInt ();
    taille = q.value("FormNumberedBullets/size", taille).toInt ();

    QColor bulletcolor(Qt::blue), numbercolor(Qt::red);
    QString str_bulletcolor (bulletcolor.name()), str_numbercolor (numbercolor.name());
    str_bulletcolor = q.value("FormNumberedBullets/bulletcolor", str_bulletcolor).toString();
    str_numbercolor = q.value("FormNumberedBullets/numbercolor", str_numbercolor).toString ();
    bulletcolor.setNamedColor(str_bulletcolor);
    numbercolor.setNamedColor(str_numbercolor);

    int qfont_index(0);
    qfont_index = q.value("FormNumberedBullets/font", qfont_index).toInt();

    int index_shape(0);
    index_shape = q.value("FormNumberedBullets/shape", index_shape).toInt();

    ui->spinBox_From->setValue(from);
    ui->spinBox_To->setValue(to);
    ui->spinBox_Size->setValue (taille);
    ui->ColorButton_BulletColor->setColor(bulletcolor);
    ui->ColorBullet_NumberColor->setColor(numbercolor);
    ui->fontComboBox->setCurrentIndex(qfont_index);
    ui->comboBox_Shape->setCurrentIndex(index_shape);
}

// Load data
// ---------

void FormNumberedBullets::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<NumberedBulletGraphicItem*>(item))
    {
        NumberedBulletGraphicItem* castedItem = qgraphicsitem_cast<NumberedBulletGraphicItem*>(item);

        // Load data into the form
        ui->spinBox_Size->setValue(castedItem->getSize());

        NumberedBulletGraphicItem::shape_e shape = castedItem->getShape();

        switch (shape)
        {
        case NumberedBulletGraphicItem::shape_e::NB_CIRCLE:
            ui->comboBox_Shape->setCurrentIndex(0);
        break;
        case NumberedBulletGraphicItem::shape_e::NB_RECTANGLE:
            ui->comboBox_Shape->setCurrentIndex(1);
        break;
        case NumberedBulletGraphicItem::shape_e::NB_ROUNDEDRECTANGLE:
            ui->comboBox_Shape->setCurrentIndex(2);
        break;
        }

        ui->ColorButton_BulletColor->setColor(castedItem->getBulletColor());
        ui->ColorBullet_NumberColor->setColor(castedItem->getNumberColor());
        ui->fontComboBox->setCurrentText(castedItem->getFont().family());
    }
}
