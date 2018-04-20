/*
================================================
* File:         formarrows.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef FORMARROWS_H
#define FORMARROWS_H

// Includes
// --------

#include <QWidget>
#include <QColor>
#include <QPolygonF>

// Forward Declaration
namespace Ui
{
    class FormArrows;
}

// Class
// -----

class FormArrows
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructors, destructor
        explicit FormArrows(QWidget* parent = 0);
        ~FormArrows();

        // Method GetInfosArrows
        void GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                            int ArrowWidth, int ArrowHeight,
                            QColor ArrowOutlineColor, QColor ArrowFillColor);
                            //To do
                            // comboBoxThicknessOutlineLinesContents
                            // comboBoxHeadTypeChoiceContents
    private:

        // UI
        Ui::FormArrows *ui;

        // Colors
        QColor FormOutlineColorArrow;
        QColor FormFillColorArrow;

        QColor BeforeFormOutlineColorArrow;
        QColor BeforeFormFillColorArrow;

        QColor DefaultFormOutlineColorArrow;
        QColor DefaultFormFillColorArrow;

        // Arrow settings
        int FormArrowWidth;
        int FormArrowHeight;
        QPolygonF FormArrowHeadType;

        int BeforeFormArrowWidth;
        int BeforeFormArrowHeight;
        QPolygonF BeforeFormArrowHeadType;

        int DefaultFormArrowWidth;
        int DefaultFormArrowHeight;
        QPolygonF DefaultFormArrowHeadType;

        //To do
        // comboBoxThicknessOutlineLinesContents
        // comboBoxHeadTypeChoiceContents

    private slots:
        void FillColorArrowChanged();
        void OutlineColorArrowChanged();
        void ClickOnpushButtonChangeOutlineColor(bool);
        void ClickOnpushButtonChangeFillColor(bool);

    signals:
        void FormFillColorArrowChanged(QColor newFormFillColorArrow);
        void FormOutlineColorArrowChanged(QColor newFormOutlineColorArrow);

};

#endif
