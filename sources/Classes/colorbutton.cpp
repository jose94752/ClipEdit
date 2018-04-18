#include <QWidget>
#include <QToolButton>
#include "colorbutton.h"
#include <QDebug>
#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>

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
      color = QColorDialog::getColor(color, this );
}

void ColorButton::paintEvent( QPaintEvent *event )
{
QToolButton::paintEvent(event) ;
    QPainter painter(this);
    QBrush  b(color);
    QPen p(color);
    painter.setPen(p);
    painter.setBrush(b);
    painter.drawEllipse(this->width()/2,this->height()/2,this->width()/3,this->height()/3);

}
