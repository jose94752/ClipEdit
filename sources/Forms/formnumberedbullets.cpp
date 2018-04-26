/*
================================================
* File:         formnumberedbullets.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#include "formnumberedbullets.h"
#include "ui_formnumberedbullets.h"
#include "../Items/numberedbulletgraphicitem.h"

#include <qdebug.h>
#include <qsettings.h>
#include <qcolor.h>


FormNumberedBullets::FormNumberedBullets(QWidget *parent)
    :   BaseForm(parent), ui(new Ui::FormNumberedBullets)
{
    ui->setupUi(this);
    load_config ();
}

FormNumberedBullets::~FormNumberedBullets()
{
    delete ui;
}

//for now shape : 0-> circle
//                1-> rectangle
//                2-> rounded rectangle
//TBD enum in NumberedBulletGraphicItem
void FormNumberedBullets::get_info (int& from, int& to, int& taille, int& shape, QColor& bulletcolor, QColor& numbercolor, QFont& font) const {
    from = ui->spinBox_From->value();
    to = ui->spinBox_To->value ();
    taille = ui->spinBox_Size->value();
    //QString shape_str;
    shape = ui->comboBox_Shape->currentIndex();
    bulletcolor = ui->ColorButton_BulletColor->getColor();
    numbercolor = ui->ColorBullet_NumberColor->getColor();

    font = ui->fontComboBox->currentFont();
}

QPushButton *FormNumberedBullets::getGoPushButton()
{
    return ui->pushButtonCreateBullet;
}

QToolButton *FormNumberedBullets::getToolButton_saveBulletConfig () {
     return ui->toolButton_saveBulletConfig;
}

void FormNumberedBullets::save_config () const {
    QSettings s;
    int from(0), to(0), taille (0);
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

void FormNumberedBullets::load_config() {
    QSettings q;
    int from (1), to (1), taille (1);
    from = q.value ("FormNumberedBullets/from", from).toInt();
    to = q.value ("FormNumberedBullets/to", to).toInt ();
    taille = q.value ("FormNumberedBullets/size", taille).toInt ();
    ui->spinBox_From->setValue(from);
    ui->spinBox_To->setValue (to);
    ui->spinBox_Size->setValue (taille);
    QColor bulletcolor (0,0, 255), //blue
           numbercolor (255, 0, 0);
    QString str_bulletcolor (bulletcolor.name ()), str_numbercolor (numbercolor.name ());
    str_bulletcolor = q.value ("FormNumberedBullets/bulletcolor", str_bulletcolor).toString();
    str_numbercolor = q.value ("FormNumberedBullets/numbercolor", str_numbercolor).toString ();
    bulletcolor.setNamedColor(str_bulletcolor);
    numbercolor.setNamedColor(str_numbercolor);

    ui->ColorButton_BulletColor->setColor(bulletcolor);
    ui->ColorBullet_NumberColor->setColor(numbercolor);
    int qfont_index (0);
    qfont_index = q.value ("FormNumberedBullets/font", qfont_index).toInt ();
    ui->fontComboBox->setCurrentIndex(qfont_index);
    int index_shape (0);
    index_shape = q.value ("FormNumberedBullets/shape", index_shape).toInt();
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
    }
}
