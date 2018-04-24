/*
================================================
* File:         formlayers.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create Layers
================================================
*/

#ifndef FORMSLAYERS_H
#define FORMSLAYERS_H

// Includes
// --------


#include <QWidget>
#include <QGraphicsScene>

class QLabel;
class QPushButton;

//#include <QLabel>
//#include <QWidget>
//#include <QGraphicsScene>

// Forward Declaration
namespace Ui
{
    class FormLayers;
}

// Class
// -----

class FormLayers: public QWidget
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormLayers(QWidget* parent = 0);

        ~FormLayers();

        void setScene(QGraphicsScene & scene);
        const QPushButton* getUpButton();

    private:

        // Ui
        Ui::FormLayers *ui;

        ///
        /// \brief m_zvalue for each GraphicsItem
        ///
        qreal m_zvalue;

        QLabel *Icon(QIcon icon);
        ///
        /// \brief ShowLayers : show the layers in layers stacked
        ///
        void ShowLayers();
        ///
        /// \brief updateLayers increment m_zvalue and update list of layerswidget
        ///
        void updateLayers();

private:

    QGraphicsScene * m_scene;

};

#endif
