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

#include "baseformitem.h"
//#include "../Items/arrowsgraphicsitem.h"

class ArrowsGraphicsItem;

// Forward Declaration
namespace Ui
{
    class FormArrows;
}

// Class
// -----

class FormArrows
    :   public BaseFormItem
{
     // Essential macro needed for signals-slots
    Q_OBJECT

    public:

        // Constructors, destructor
        explicit FormArrows(QWidget* parent = 0);
        ~FormArrows();

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

        // Getter add button
        const QPushButton* getAddButton() const;

        //--------------------------------------------------
        // Methods get the values for Arrows
        //--------------------------------------------------

        // Method GetInfosArrows
       void GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                            int &ArrowWidth, int &ArrowHeight,
                            QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                            int &LineThickness, int &SizeHeadTypeChoice);
                            //To do others HeadTypeChoiceContents
                            // comboBoxHeadTypeChoiceContents


        //return the Form Fill Color Arrow
        QColor getFormFillColorArrow();

        //return the Form Fill Color Arrow with QColor object
        QColor getFormFillColorArrow(QColor  &newFormFillColorArrow);

        //return the Form Outline Color Arrow
        QColor getFormOutlineColorArrow();
        //--------------------------------------------------

        //--------------------------------------------------
        // Methods return the Defaults values for Arrows
        //--------------------------------------------------

        //return the Default Form Outline Color Arrow
        QColor getDefaultFormOutlineColorArrow();

        //return the Default Form Fill Color Arrow
        QColor getDefaultFormFillColorArrow();

        //return the Default Form Arrow Head Size
        int getDefaultFormArrowHeadSize ();

        //return the Default Form Arrow Width
        int getDefaultFormArrowWidth();

        //return the Default Form Arrow Height
        int getDefaultFormArrowHeight();

        //return the Default Form Arrow Head Type
        QPolygonF getDefaultFormArrowHeadType();

        //return the Default Line Thickness
        int getDefaultLineThickness();

        //--------------------------------------------------

        //--------------------------------------------------
        // Methods set the values for Arrows
        //--------------------------------------------------

        // Method SetInfosArrows
        void SetInfosArrows(bool WithoutAnchorPoint, bool OneAnchorPoint, bool TwoAnchorPoints,
                            int ArrowWidth, int ArrowHeight,
                            QColor ArrowOutlineColor, QColor ArrowFillColor,
                            int LineThickness, int SizeHeadTypeChoice);
                            //To do others HeadTypeChoiceContents
                            // comboBoxHeadTypeChoiceContents

        //set the BeforeFormArrowWidth
        void setBeforeFormArrowWidth(int newBeforeFormArrowWidth);

        //set the FormArrowWidth
        void setFormArrowWidth(int newFormArrowWidth);

        //set the BeforeFormArrowHeight
        void setBeforeFormArrowHeight(int newBeforeFormArrowHeight);

        //set the FormArrowHeight
        void setFormArrowHeight(int newFormArrowHeight);


        //--------------------------------------------------

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

    public slots:
        void fillColorArrowChanged();
        void fillColorArrowChanged(const QColor& color);
        void outlineColorArrowChanged(const QColor& color);
        void radioButtonWithoutAnchorPointMethod(bool);
        void ArrowWidthUpdated(const int newArrowWidth);

    signals:

        void FormFillColorArrowChanged();
        void FormFillColorArrowChanged(QColor newFormFillColorArrow);
        void FormOutlineColorArrowChanged(QColor newFormOutlineColorArrow);

};

#endif
