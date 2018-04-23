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
#include<QButtonGroup>
#include<QSpinBox>
#include<QRadioButton>
#include<QCheckBox>
#include<QGraphicsScene>
#include<QString>

// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}


///
/// \brief The FormScreenshots class : his charge is to making a Screenshot
/// of two types: WholeScreenShot and window
///

class FormScreenshots
    :   public QWidget
{
    Q_OBJECT

    public:
///
/// \brief The TypeCapture enum : enum with the type of capture
///
    enum TypeCapture {WholeScreen};

 ///
 /// \brief FormScreenshots : constructor
 /// \param parent
 ///
        explicit FormScreenshots(QWidget* parent = 0);

        ~FormScreenshots();

//protected:
//    ///
//    /// \brief resizeEvent this method function is reimplemented to receive
//    /// the resize events dispatched to the widget.
//    /// \param event
//    ///
//    void resizeEvent(QResizeEvent *event) override;


    private:

        // Ui
        Ui::FormScreenshots *ui;
        ///
        /// \brief m_typecapture WholeScreen and window.
        ///
        TypeCapture m_typecapture;
        ///
        /// \brief m_pixmap : the pixmap of the window screenshoted.
        ///
        QPixmap m_pixmap;
        ///
        /// \brief m_buttongroup we group the radio button who are included in different frames.
       // QButtonGroup m_buttongroup;
        ///
        /// \brief m_delayspinbox it gives the time for a user to rearrange this desktop.
        ///
        QSpinBox *m_delayspinbox;
        ///
        /// \brief m_hidewindow Hiding the application's window while the screenshot is taken.
        ///
        QCheckBox *m_hidewindow;

        int m_width;
        int m_height;

        void mousePressEvent(QMouseEvent *ev);
        void mouseMoveEvent(QMouseEvent *ev);
        void mouseReleaseEvent(QMouseEvent *ev);

        bool m_buttonpressed;

        ///
        /// \brief if m_point0 = point1 this mean the user has
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
        void hide();
        ///
        /// \brief ChangeHeight
        ///
        void ChangeHeight(int);
        ///
        /// \brief ChangeWidth
        ///
        void ChangeWidth(int);

     signals:
        ///
        /// \brief InsertImageText signal sent when text is to be inserted in TextEdit.
        ///
        void InsertImageText(QString);




};

#endif // FORMSCREENSHOOTS_H
