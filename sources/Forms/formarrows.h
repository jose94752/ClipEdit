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

#include <QColor>
#include <QPolygonF>
#include <QPushButton>

#include "baseform.h"

// Forward Declaration
namespace Ui
{
    class FormArrows;
}

// Class
// -----

class FormArrows
    :   public BaseForm
{
     // Essential macro needed for signals-slots
    Q_OBJECT

    public:

        // Constructors, destructor
        explicit FormArrows(QWidget* parent = 0);
        ~FormArrows();

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Method GetInfosArrows
        void GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                            int &ArrowWidth, int &ArrowHeight,
                            QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                            int &LineThickness, int &SizeHeadTypeChoice);
                            //To do others HeadTypeChoiceContents
                            // comboBoxHeadTypeChoiceContents

        // Method SetInfosArrows are now set in private section ( it will be move to protected or public if needed
        // to connect other object if node /= item )
        /*void SetInfosArrows(bool WithoutAnchorPoint, bool OneAnchorPoint, bool TwoAnchorPoints,
                            int ArrowWidth, int ArrowHeight,
                            QColor ArrowOutlineColor, QColor ArrowFillColor,
                            int LineThickness, int SizeHeadTypeChoice);*/

        //return the Form Fill Color Arrow
        QColor getFormFillColorArrow();

        //return the Form Fill Color Arrow with QColor object
        QColor getFormFillColorArrow(QColor  &newFormFillColorArrow);

        //return the Form Outline Color Arrow
        QColor getFormOutlineColorArrow();

        // QPushButton method To Add Arrows from FormArrows to connect use these get on the MainWindows
        QPushButton* getAddPushButtonArrow();

        // temp for test
        QColor FormFillColorArrow;

private:

        // UI
        Ui::FormArrows *ui;

        // Colors
        QColor FormOutlineColorArrow;
        //QColor FormFillColorArrow;

        QColor BeforeFormOutlineColorArrow;
        QColor BeforeFormFillColorArrow;

        QColor DefaultFormOutlineColorArrow;
        QColor DefaultFormFillColorArrow;

        // Arrow settings
        int FormArrowHeadSize; // <- FormArrowHeadSize is First issue of Form Arrow Head Size and is a temporary solution
        int FormArrowWidth;
        int FormArrowHeight;
        QPolygonF FormArrowHeadType;

        int BeforeFormArrowHeadSize; // cf. FormArrowHeadSize
        int BeforeFormArrowWidth;
        int BeforeFormArrowHeight;
        QPolygonF BeforeFormArrowHeadType;

        int DefaultFormArrowHeadSize; // cf. FormArrowHeadSize
        int DefaultFormArrowWidth;
        int DefaultFormArrowHeight;
        QPolygonF DefaultFormArrowHeadType;

        //To do others HeadTypeChoiceContents
        // comboBoxHeadTypeChoiceContents
        int SizeHeadTypeChoiceContents; // First simple type of ArrowHead from comboBoxHeadTypeChoiceContents

        // Line Thickness settings
        int FormLineThickness;

        int BeforeLineThickness;

        int DefaultLineThickness;

        int LineThicknessContents;

        // Method SetInfosArrows
        void SetInfosArrows(bool WithoutAnchorPoint, bool OneAnchorPoint, bool TwoAnchorPoints, int ArrowWidth,
                            int ArrowHeight, QColor ArrowOutlineColor, QColor ArrowFillColor, int LineThickness,
                            int SizeHeadTypeChoice);

    public slots:
        void fillColorArrowChanged();
        void fillColorArrowChanged(const QColor& color);
        void outlineColorArrowChanged(const QColor& color);
        void radioButtonWithoutAnchorPointMethod(bool);

    signals:

        void FormFillColorArrowChanged();
        void FormFillColorArrowChanged(QColor newFormFillColorArrow);
        void FormOutlineColorArrowChanged(QColor newFormOutlineColorArrow);

};

#endif
