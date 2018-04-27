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
#include <QSettings>

#include "baseform.h"


// Forward Declaration
namespace Ui
{
    class FormPictures;
}


// Class
// -----

class FormPictures
    :   public BaseForm
{
    Q_OBJECT

    public:
        char w_h1;
        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

        void getPictureValues(QString &path, int &height, int &width, bool &w_h_fixed, char &w_h, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

    public slots:

        void chose_picture();
        void legend_ok(bool);
        void picture_modification();
        void picture_modification_w();
        void picture_modification_h();


        void save_settings(bool);
        void restore_settings(bool);
private:

        // Ui
        Ui::FormPictures *ui;

        QSettings setting;
        bool      s_black_white;
        QString     s_lg_font;
        int       s_lg_size;
        QColor    s_lg_color;
        QString   s_lg_pos;


    signals:

        void picture_changed();
        void picture_changed_w_h(char w_h1);

};

#endif
