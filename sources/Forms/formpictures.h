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
        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

        void getPictureValues(QString &path, int &height, int &width, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos, QString &lg_or);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

    public slots:

        void chose_picture();

        void validation_ok(bool);

        void save_settings(bool);
        void restore_settings(bool);
private:

        // Ui
        Ui::FormPictures *ui;

        QSettings setting;
        bool      s_black_white;
        QString   s_lg_txt;
        int       s_lg_size;
        QString   s_lg_font;
        QColor    s_lg_color;
        QString   s_lg_pos;
        QString   s_lg_or;


    signals:

        void picture_changed();

};

#endif
