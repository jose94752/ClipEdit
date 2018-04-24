/*
====================================================
* File:         formpictures.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create PicturesGraphicsItem
====================================================
*/

#ifndef FORMPICTURES_H
#define FORMPICTURES_H

// Includes
// --------

#include <QWidget>


// Forward Declaration
namespace Ui
{
    class FormPictures;
}


// Class
// -----

class FormPictures
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

        void getPictureValues(QString &path, int &height, int &width, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos);

    public slots:

        void chose_picture();
        void picture_modification();
        void picture_modification_w(int w);
        void picture_modification_h(int h);

    private:

        // Ui
        Ui::FormPictures *ui;

    signals:

        void picture_changed();



};

#endif
