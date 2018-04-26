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
        char w_h1;
        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

        void getPictureValues(QString &path, int &height, int &width, bool &w_h_fixed, char &w_h, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos);

    public slots:

        void chose_picture();
        void legend_ok(bool);
        void picture_modification();
        void picture_modification_w();
        void picture_modification_h();


    private:

        // Ui
        Ui::FormPictures *ui;

    signals:

        void picture_changed();
        void picture_changed_w_h(char w_h1);

};

#endif
