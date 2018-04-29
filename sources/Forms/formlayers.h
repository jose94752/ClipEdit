/*
================================================
* File:         formlayers.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage Layers
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
class BaseGraphicItem;

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

        void actionClicked(int line, int col);
        void actionUp();
        void actionDown();
        void actionAdd();
        void actionSupp();

    private:

        // Ui
        Ui::FormLayers* ui;
        QGraphicsScene* m_scene;

        qreal m_zvalue;

        QLabel* cellIcon(const QIcon& icon);
        QLabel* cellIcon(const QString& filename);

        void initForm();
        void updateLayers();

        int m_lineSelected;
        int m_columnSelected;

        BaseGraphicItem * m_itemSelected;
};

#endif
