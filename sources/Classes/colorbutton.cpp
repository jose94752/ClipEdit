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
   this->setText("");
   //this->resize(150,45);
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
      emit colorChanged(color);
      update();
}

void ColorButton::paintEvent( QPaintEvent *event )
{
QToolButton::paintEvent(event) ;
    QPainter painter(this);
    QBrush  b(color);
    QPen p(color);
    painter.setPen(p);
    painter.setBrush(b);
    painter.drawEllipse(this->width()/8,this->height()/8,3*this->width()/4,3*this->height()/4);

}
