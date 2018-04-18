#include <QWidget>
#include <QToolButton>
#include "colorbutton.h"
#include <QDebug>
#include <QColorDialog>
#include <QPaintEvent>

ColorButton::ColorButton(QWidget* widget):QToolButton(widget)
{
   color=Qt::black;
   connect(this,SIGNAL(clicked(bool)),this,SLOT(slotChoiseColor(bool)));
   //QPaintEvent pe;
   //this->paintEvent(pe);
}

QColor ColorButton::getColor()
{
    return color;
}

void ColorButton::setColor(QColor vcolor)
{
    color=vcolor;
}

void ColorButton::slotChoiseColor(bool)
{
    qDebug()<<"cliqué";
    color = QColorDialog::getColor(color, this );
}

void ColorButton::paintEvent( QPaintEvent *event )
{
qDebug()<<this->width()<<this->height();
}
