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
class QTableWidgetItem;

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

private slots:

        void cellActivated(int row, int column);
        void contextMenu(const QPoint &pos);

        void on_buttonUp_clicked();
        void on_pushDown_clicked();

private:

        // Ui
        Ui::FormLayers *ui;
        QGraphicsScene * m_scene;

        qreal m_zvalue;

        QLabel *Icon(QIcon icon);

        void initForm();
        void ShowLayers();
        void updateLayers();

};

#endif
