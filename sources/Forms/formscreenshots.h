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
#include<QMap>
#include<QPainter>
#include<QGraphicsItem>
#include<exception>
#include<QMouseEvent>
#include <QGraphicsScene>


// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}


///
/// \brief The FormScreenshots class : his charge is to making a Screenshot
/// of two types: WholeScreenShot and region
///

class FormScreenshots :   public QWidget
{
    Q_OBJECT

public:
///
/// \brief The TypeCapture enum : enum with the type of capture
///
    enum TypeCapture { WholeScreen, Region };

 ///
 /// \brief FormScreenshots : constructor
 /// \param parent
 ///
    // explicit FormScreenshots(QWidget* parent = 0, QGraphicsScene*);
    explicit FormScreenshots(QWidget* parent = 0);

   // virtual const char* what() const throw(bad_function_call);

        ~FormScreenshots();

protected:
//    ///
//    /// \brief resizeEvent this method function is reimplemented to receive
//    /// the resize events dispatched to the widget.
//    /// \param event
//    ///
//    void resizeEvent(QResizeEvent *event) override;
    ///
    /// \brief mousePressEvent
    /// \param event
    ///
    void mousePressEvent(QMouseEvent *event) override;
    ///
    /// \brief mouseMoveEvent
    /// \param event
    ///
    void mouseMoveEvent(QMouseEvent *event) override;
    ///
    /// \brief mouseReleaseEvent
    /// \param event
    ///
    void mouseReleaseEvent(QMouseEvent *event) override;


private:
        // Ui
        Ui::FormScreenshots *ui;
        //QGraphicsScene *scene;
        ///
        /// \brief onMouseEvent: method indicating the event involved.
        ///
        //void onMouseEvent();
        int x;
        int y;
        ///
        /// \brief m_typecapture WholeScreen and window.
        ///
        TypeCapture m_typecapture;
        ///
        /// \brief m_pixmap : the pixmap of the window screenshoted.
        ///
        QPixmap m_pixmap;
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
        QRect m_region;

        ///
        /// \brief if m_point1 = point2 this mean the user has taken the whole screen.
        ///
        QPoint m_point0;
        QPoint m_point1;

     private slots:
        ///
        /// \brief Capture : capture slot in WholeScreen and window
        ///
        void Capture();
        ///
        /// \brief CaptureWholeScreen : this method take all Desktop
        ///
        void CaptureWholeScreen();
        ///
        /// \brief hide enables or disables the Hide The Window option.
        ///
        void CaptureRegion(bool ok, QRect region);
        void hide();

        ///
        /// \brief updateLabel this slot is called whenever the user changes the delay
        /// using the Screenshot Delay second option
        ///

     signals:
        ///
        /// \brief InsertImageText signal sent when text is to be inserted in TextEdit.
        ///
        void InsertImageText(QString);
        void dimensionsMade( bool, QRect );
        void mouseMoveEvent();
        void mousePressEvent();
        void mouseReleaseEvent();
};

#endif // FORMSCREENSHOOTS_H
