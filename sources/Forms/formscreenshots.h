/*
=================================================
* File:         formscreenshots.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage sceenshots capture
=================================================
*/

#ifndef FORMSCREENSHOOTS_H
#define FORMSCREENSHOOTS_H

// Includes
// --------

#include <QWidget>
#include<QPixmap>
#include<QGroupBox>
#include<QSpinBox>
#include<QRadioButton>
#include<QCheckBox>
#include<QString>
#include<QCursor>
#include<QLabel>
#include<QPointF>
#include<QGraphicsPixmapItem>
#include<QPainter>
#include<QGraphicsItem>
#include<exception>
#include<QMouseEvent>
#include <QGraphicsScene>
#include<QRect>

#include "baseform.h"


// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}


///
/// \brief The FormScreenshots class : his charge is to making a Screenshot
/// of two types: WholeScreenShot and region
///

class FormScreenshots :   public BaseForm
{
    Q_OBJECT

public:
///
/// \brief The TypeCapture enum : enum with the type of capture
///
    enum TypeCapture { Desktop, Area };

 ///
 /// \brief FormScreenshots : constructor
 /// \param parent
 ///
    // explicit FormScreenshots(QWidget* parent = 0, QGraphicsScene*);
    explicit FormScreenshots(QWidget* parent = 0) ;

   // virtual const char* what() const throw(bad_function_call);

        ~FormScreenshots();


    // Load data
    void loadFromItem(BaseGraphicItem* item) const;

protected:
    ///
    /// \brief mousePressEvent This event handler, for event event, can be reimplemented
    ///  in a subclass to receive mouse press events for the widget
    /// \param event
    ///
    void mousePressEvent(QMouseEvent *event);
    ///
    /// \brief mouseReleaseEvent This event handler, for event event, can be reimplemented
    /// in a subclass to receive mouse release events for the widget.
    /// \param event
    ///
    void mouseReleaseEvent(QMouseEvent *event);

public slots:

    void choose_screenshot();

private:
        // Ui
        Ui::FormScreenshots *ui;
        QGraphicsScene *m_scene;


        ///
        /// \brief m_typecapture Desktop and window.
        ///
        TypeCapture m_typecapture;
        ///
        /// \brief m_pixmap : the pixmap of the window screenshoted.
        ///
        QPixmap m_pix;
        ///
        /// \brief m_formscreenshot is used to display the rectangle region drawed on mouse clicked
        ///
        FormScreenshots *m_formScreenshots;
        ///
        /// \brief m_delayspinbox it gives the time for a user to rearrange this desktop.
        ///
        QSpinBox *m_delayspinbox;
        ///
        /// \brief m_hidewindow Hiding the application's window while the screenshot is taken.
        ///
        QCheckBox *m_hidewindow;
        ///
        /// \brief m_label label of our screen shot
        ///
        QLabel *m_label;
        ///
        /// \brief m_optionsGroupbox the QGroupBox widget provides a group box frame with a title.
        ///
        QGroupBox *m_optionsGroupbox;
        ///
        /// \brief m_savedcursor class provides a mouse cursor with an arbitrary shape.
        ///
        QCursor m_savedcursor;

        bool m_buttonpressed;
        ///
        /// \brief m_region The QRect class defines a rectangle
        ///  in the chosen region  in the plane using integer precision.
        ///
        QRectF m_area;
        ///
        /// \brief m_captureTimer is an instance of class provides repetitive and single-shot timers.
        ///
        QTimer  *m_captureTimer;

        ///
        /// \brief if m_point1 = point2 this mean the user has taken the whole screen.
        ///
        QPointF *m_point0;
        QPointF *m_point1;
        QPointF *m_point;
        qreal x,y,x1,y1;
        int m_width;
        int m_height;
        QPainter *m_painter;

     private slots:
        ///
        /// \brief snapshot : snapshot slot in Desktop and window
        ///
        void snapshot();
        ///
        /// \brief CaptureDesktop : this method take all Desktop
        ///
        void CaptureDesktop();
        void CaptureArea(bool val, QRectF a);
        void updatehide();

     signals:
        ///
        /// \brief setBackground : QPixmap class is an off-screen image representation
        /// that can be used as a paint device.
        /// \param pix
        ///
        void setBackground(QPixmap pix);
        ///
        /// \brief dimensionsMade signal
        ///
        void dimensionsMade( bool, QRect );
        void mousePressEvent();
        void mouseReleaseEvent();
};

#endif // FORMSCREENSHOOTS_H
