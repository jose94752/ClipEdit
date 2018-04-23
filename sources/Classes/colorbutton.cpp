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
    :   QPushButton(parent), m_color(Qt::black)
{
   connect(this, SIGNAL(clicked(bool)), this, SLOT(pickColor(bool)));
   setText(" ");
   setFixedWidth(50);
}

// Events
// ------

void ColorButton::paintEvent(QPaintEvent* event)
{
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QBrush brush(m_color);
    QPen pen(m_color);
    painter.setPen(pen);
    painter.setBrush(brush);

    QRect box = rect();
    box.adjust(5, 5, -5, -5);
    painter.fillRect(box, m_color);
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

