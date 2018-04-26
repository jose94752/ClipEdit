#ifndef COMPONENT_IMG_BUTTON_H
#define COMPONENT_IMG_BUTTON_H

#include <QtWidgets/QWidget>

#include <QImage>
#include <QSize>


// Forward Declarations
class QMouseEvent;
class QPaintEvent;


class My_Img_Button: public QWidget {
    Q_OBJECT


// Constructor
public:

    explicit My_Img_Button(QWidget* /*parent*/ = 0);


public:

    typedef enum e_IMG : unsigned char {
        IMG_NONE = 0,
        IMG_ERASER
    } t_Img;


// Interface
public:

    void set_image(t_Img);


signals:

    void on_click();


// QWidget
protected:

    QSize minimumSizeHint() const { return QSize((int) img_width, (int) img_height); }

    void mouseReleaseEvent(QMouseEvent*);

    void paintEvent(QPaintEvent*);

    QSize sizeHint() const { return QSize((int) img_width, (int) img_height); }


// Data Members
private:

    QImage image;

    t_Img  current_image;

    size_t img_height, img_width;
};


#endif // COMPONENT_IMG_BUTTON_H
