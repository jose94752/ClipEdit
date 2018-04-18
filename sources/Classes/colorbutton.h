#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QToolButton>
#include <QWidget>
#include <QColor>

class ColorButton: public QToolButton
{
    Q_OBJECT
public:
    ColorButton(QWidget* widget);
    QColor getColor();
    void setColor(QColor);
    void paintEvent( QPaintEvent*);
protected:
    QColor color;
private slots:
    void slotChoiseColor(bool);
};

#endif // COLORBUTTON_H
