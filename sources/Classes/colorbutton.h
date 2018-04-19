/*
================================================
* File:         colorbutton.h
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        Custom color picker
================================================
*/

#ifndef COLORBUTTON_H
#define COLORBUTTON_H

// Includes
// --------

#include <QToolButton>
#include <QWidget>
#include <QColor>

// Class
// -----

class ColorButton
    :   public QToolButton
{
    Q_OBJECT

    public:

        // Constructor
        ColorButton(QWidget* parent = 0);

        // Getter and setters
        QColor getColor() const;
        void setColor(const QColor& color);

        // Event
        void paintEvent(QPaintEvent*);

    protected:

        // Selected color
        QColor m_color;

    signals:

        void colorChanged(QColor);

    private slots:

        void pickColor(bool);
};

#endif
