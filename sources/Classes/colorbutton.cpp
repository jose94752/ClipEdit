/*
================================================
* File:         colorbutton.cpp
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        Custom color picker
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QToolButton>
#include "colorbutton.h"

// Constructor
// -----------

ColorButton::ColorButton(QWidget* parent)
    :   QToolButton(parent), m_color(Qt::black)
{
   connect(this, SIGNAL(clicked(bool)), this, SLOT(pickColor(bool)));
   setText("");
}

// Events
// ------

void ColorButton::paintEvent(QPaintEvent* event)
{
    QToolButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QBrush brush(m_color);
    QPen pen(m_color);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(width()/6.0f, height()/8.0f, width() - 2*(width()/6.0f), height()- 2*(height()/8.0f));
}

// Getters and setters
// -------------------

QColor ColorButton::getColor() const
{
    return m_color;
}

void ColorButton::setColor(const QColor& vcolor)
{
      m_color=vcolor;
}

// Slots
// -----

void ColorButton::pickColor(bool)
{
    m_color = QColorDialog::getColor(m_color, this);
    emit colorChanged(m_color);
    update();
}

