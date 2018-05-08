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

#include "baseformitem.h"

// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}

class FormScreenshots
    :   public BaseFormItem
{
    Q_OBJECT

    public:

        explicit FormScreenshots(QWidget* parent = 0) ;
        ~FormScreenshots();

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

        // Getters
        const QPixmap& getScreenshot() const;
        const QPushButton* getAddButton() const;

    protected:

        // Events
        void resizeEvent(QResizeEvent* event);

     private slots:

        void startCountdown();
        void takeScreenshot();

        // Screenshot received from the mainwindow
        void screenshotReceived(const QPixmap& screenshot);

    signals:

        // Window visibility
        void adjustWindowVisibility(bool visible);

        // Request a screenshot from the main window
        void requestScreenshot(bool wholeScreen);

    private:

        // Update
        void updatePreviewLabel();

        // Ui
        Ui::FormScreenshots* ui;

        // Image
        QPixmap m_screenshot;
};

#endif
