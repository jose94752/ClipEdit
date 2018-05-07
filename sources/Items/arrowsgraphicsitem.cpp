/*
================================================
* File:         arrowsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Arrows GraphicsItem
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#include <QDebug>
#include <QGraphicsItem>
#include <QRect>
#include <QPen>
//#include <QPainter>
#include <QColor>
#include <QString>

//#include <QObject> // <- For the tests disable if it is not needed at least
//#include <QColorDialog>

#include <QtMath>

#include "itemhandler.h"
#include "arrowsgraphicsitem.h"
#include "../Forms/formarrows.h"
#include "ui_mainwindow.h"

// Zone de travaux
ArrowsGraphicsItem::ArrowsGraphicsItem(FormArrows *ptrFormArrows, QGraphicsItem *parent)
    :   BaseGraphicItem(parent)

{

    m_formArrows = ptrFormArrows;
    // Temp dud BaseGraphicItem::paintEvent()
    //ArrowsGraphicsItem->setHasHandler(false);
    // End Temp


/* Test
    //FormArrowsGetInfosArrows();
    // Control of the size of scene vs size of the arrows
    // with default sizes set for:
    // ArrowWidth = 50, ArrowHeight = 50
    // LineThickness = 1, SizeHeadTypeChoice 10
    // To Do after correcting arrows bugs size use QColor::QColor() to set invalid color
    // for ArrowOutlineColor, ArrowFillColor
    bool WithoutAnchorPoint(true), OneAnchorPoint(false), TwoAnchorPoints(false);
    int ArrowWidth(50), ArrowHeight(50);
    QColor ArrowOutlineColor, ArrowFillColor;
    int LineThickness(1), SizeHeadTypeChoice(10);

    m_formArrows->GetInfosArrows(WithoutAnchorPoint, OneAnchorPoint, TwoAnchorPoints,
                                 ArrowWidth, ArrowHeight,
                                 ArrowOutlineColor, ArrowFillColor,
                                 LineThickness, SizeHeadTypeChoice);
                                //To do others HeadTypeChoiceContents
                                // comboBoxHeadTypeChoiceContents

*/ //End Test


    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scTesene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene


    //m_StartItem = startItem;
    //m_EndItem = endItem;
    //m_StartPositionItem = startItem.{à définir}scenePos();
    //m_EndPositionItem =  endItem.{à définir}scenePos();

    m_StartPositionItem = new QPointF(-50, -50);
    m_EndPositionItem = new QPointF(100, 100);



    m_Color = Qt::black; // Temp for test
    arrowHeadSize = 35; // Temp for tests intial 10


    qDebug() << "Constructor receive for m_LineThickness =" << m_LineThickness;
    // To Do Set the new Line Thickness
    //m_LineThickness = 4; // Temp for tests intial 1
    if(m_LineThickness > 4) m_LineThickness = 4;
    if(m_LineThickness < 1) m_LineThickness = 3;
    //if (m_LineThickness > 4) m_LineThickness = m_formArrows->getDefaultLineThickness(); // <- Don't use bug with values send by FormArrows
    qDebug() << "Constructor Debug for m_LineThickness =" << m_LineThickness;



    // For test you must use a color because the default new QColor();
    // constructor Constructs an invalid color with the RGB value (0, 0, 0).
    // We must use the default constructor when you want to implement isValid() function of QColor class
    // If you don't do you will have segmentation fault bug
    //ItemFillColorArrow = new QColor(); // for tests and the use isValid() function of QColor class
    ItemFillColorArrow = new QColor(m_formArrows->getFormFillColorArrow());
    //qDebug() << "Item Fill Color Arrow  = " << *ItemFillColorArrow;
    //ItemOutlineColorArrow = new QColor(); // for tests and the use isValid() function of QColor class
    ItemOutlineColorArrow = new QColor();
    setColorOutline(m_formArrows->getFormOutlineColorArrow());

    TestFillColor = new QColor(m_formArrows->getFormFillColorArrow());
    nameTestFillColor = TestFillColor->name();

    //qDebug() << "Item Outline Color Arrow = " << *ItemOutlineColorArrow;


    //setRect(QRectF(-50, -50, 100, 100)); // Temp for test
    setRect(QRectF(*m_StartPositionItem, *m_EndPositionItem)); // Temp for test 2

    //setPos(0,0);

    //Test zone
    // Without connect for change *ItemFillColorArrow when signal FormFillColorArrowChanged is emit from FormArrows class
    //qDebug() << "Before setColorFill FormFillColorArrowChanged() the *ItemFillColorArrow = " << *ItemFillColorArrow;
    //m_formArrows->FormFillColorArrowChanged(*ItemFillColorArrow);

    // Signal recept
    m_formArrows->FormFillColorArrowChanged(*TestFillColor);

    nameTestFillColor = TestFillColor->name();
    qDebug() << "nameTestFillColor = " << nameTestFillColor;

    QString nameItemFillColorArrow = ItemFillColorArrow->name();
    qDebug() << "nameItemFillColorArrow =" << nameItemFillColorArrow;

    if (nameItemFillColorArrow != nameTestFillColor)
      {
        qDebug() << "Colors: nameItemFillColorArrow != nameTestFillColor";
        setColorFill(m_formArrows->getFormFillColorArrow());
      }
    else
      {
          qDebug() << "Colors *ItemFillColorArrow == *TestFillColor";
      }
    //qDebug() << "After setColorFill FormFillColorArrowChanged() the *ItemFillColorArrow = " << *ItemFillColorArrow;

    //End Test zone

}

/*
Beware we don't use QGraphicsLineItem Class which reimplement boundingRect()
[virtual] QRectF QGraphicsLineItem::boundingRect() const
from QGraphicsItem::boundingRect().
*************************************************************************************************
QGraphicsLineItem Class
The QGraphicsLineItem class provides a line item that you can add to a QGraphicsScene. More...

Header:
#include <QGraphicsLineItem>
qmake:
QT += widgets
Since:
Qt 4.2
Inherits:
QGraphicsItem
[..]
[virtual] QRectF QGraphicsLineItem::boundingRect() const
Reimplemented from QGraphicsItem::boundingRect().
**************************************************************************************************
*/

// Not the case here we inherints from BaseGraphicItem which is inherints QGraphicsItem
QRectF ArrowsGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void ArrowsGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // @José: Juste un exemple de dessin trouvé dans un exemple (elastic nodes)
    // Pour rappel ton rectangle de dessin est m_rect, si tu sors de ce rectangle tu auras des artefacts lors du déplacement de l'item
    // Par ailleurs le crash venait de ta méthode shape(), car tu avais tout commenté dedans et ça, ça lui plaisait pas... il lui faut un retour absolument
    // Je pense pas que tu en as besoin d'ailleurs, shape() ça sert surtout à redéfinir une forme plus précise pour ton item, notamment quand tu veux faire de la
    // détection de collision / click, la forme de base étant un rectangle. Après tu peux le faire si tu veux hein !

    // Example
    /*
    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();
    QPointF sourcePoint = m_rect.topLeft(); // Test
    QPointF destPoint = m_rect.bottomRight(); // Test
    QLineF line(sourcePoint, destPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
    double angle = qAtan2(-line.dy(), line.dx());
    QPointF sourceArrowP1 = sourcePoint + QPointF(qSin(angle + M_PI / 3) * 10, qCos(angle + M_PI / 3) * 10);
    QPointF sourceArrowP2 = sourcePoint + QPointF(qSin(angle + M_PI - M_PI / 3) * 10, qCos(angle + M_PI - M_PI / 3) * 10);
    QPointF destArrowP1 = destPoint + QPointF(qSin(angle - M_PI / 3) * 10, qCos(angle - M_PI / 3) * 10);
    QPointF destArrowP2 = destPoint + QPointF(qSin(angle - M_PI + M_PI / 3) * 10, qCos(angle - M_PI + M_PI / 3) * 10);
    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    painter->restore();
    */
    // End Example



    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();

    *m_StartPositionItem = m_rect.topLeft();
    *m_EndPositionItem = m_rect.bottomRight();

    // Testing if you have at least the StartPosition and EndPositionItem is one missing
    // we return and nothing is display.
    if (!m_StartPositionItem || !m_EndPositionItem)
        return;

    /* //These are no need since the BaseGraphicItem::boundingRect whas updated for 360° Items Arrows direction
    // Check if m_StartPostionItem >= m_EndPostionItem one for x and one for y
    if (m_StartPositionItem->x() >= m_EndPositionItem->x())
            m_EndPositionItem->setX(m_StartPositionItem->x());
    if (m_StartPositionItem->y() >= m_EndPositionItem->y())
            m_EndPositionItem->setY(m_StartPositionItem->y());
    */

    // Draw the line
    QLineF line(*m_StartPositionItem, *m_EndPositionItem);

    // Check the length line if is approximately 0 then we return and nothing is display.
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line (next step)
    //painter->setPen(QPen(m_Color, m_LineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //painter->setPen(QPen(*ItemFillColorArrow, m_LineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QPen pen(*ItemFillColorArrow, m_LineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawLine(line);

    // Draw the arrows
    double angle = qAtan2(-line.dy(), line.dx());



    QPointF sourceArrowP1 = *m_StartPositionItem + QPointF(qSin(angle + M_PI / 3) * arrowHeadSize,
                                                           qCos(angle + M_PI / 3) * arrowHeadSize);
    QPointF sourceArrowP2 = *m_StartPositionItem + QPointF(qSin(angle + M_PI - M_PI / 3) * arrowHeadSize,
                                                           qCos(angle + M_PI - M_PI / 3) * arrowHeadSize);
    QPointF destArrowP1 = *m_EndPositionItem + QPointF(qSin(angle - M_PI / 3) * arrowHeadSize,
                                                       qCos(angle - M_PI / 3) * arrowHeadSize);
    QPointF destArrowP2 = *m_EndPositionItem + QPointF(qSin(angle - M_PI + M_PI / 3) * arrowHeadSize,
                                                       qCos(angle - M_PI + M_PI / 3) * arrowHeadSize);

    //painter->setBrush(m_Color);
    painter->setBrush(*ItemFillColorArrow);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    painter->restore();

    BaseGraphicItem::paint(painter,option,widget);
}
// fin Zone de travaux

// Getters
// -------

void ArrowsGraphicsItem::GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                                        int &ArrowWidth, int &ArrowHeight,
                                        QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                                        int &LineThickness, int &SizeHeadTypeChoice)
                                        //To do others HeadTypeChoiceContents
                                        // comboBoxHeadTypeChoiceContents
{
    WithoutAnchorPoint = m_WithoutAnchorPoint;
    OneAnchorPoint = m_OneAnchorPoint;
    TwoAnchorPoints = m_TwoAnchorPoints;

    ArrowWidth = m_ArrowWidth;
    ArrowHeight = m_ArrowHeight;

    if (ItemOutlineColorArrow->isValid())
        {
            ArrowOutlineColor = *ItemOutlineColorArrow;
        }
    else
        {
            qDebug() << "Invalid Item Outline Color Arrow when you call GetInfosArrows Method,"
                     << " we have replaced it by standard color black.";
            ItemOutlineColorArrow = new QColor(Qt::black);
            ArrowOutlineColor = *ItemOutlineColorArrow;
        }

    if (ItemFillColorArrow->isValid())
        {
            ArrowFillColor = *ItemFillColorArrow;
        }
    else
        {
            qDebug() << "Invalid Item Fill Color Arrow when you call GetInfosArrows Method,"
                     <<  " we have replaced it by standard color black.";
            ItemFillColorArrow = new QColor(Qt::black);
            ArrowFillColor = *ItemFillColorArrow;
        }

    LineThickness = m_LineThickness;


    //To do others HeadTypeChoiceContents
    // comboBoxHeadTypeChoiceContents
    SizeHeadTypeChoice = m_SizeHeadTypeChoice;
}

void ArrowsGraphicsItem::updateArrowPosition()
{
    // Without anchor point method
    // To do

    // 1 anchor point method
    // To do

    //  2 anchors points method
    /* inactive no constructor for the moment
    QLineF line(mapFromItem(m_StartItem, 0, 0), mapFromItem(m_EndItem, 0, 0));
    setLine(line);
    */

    //Example
    //QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    //setLine(line);

    update();
}

FormArrows* ArrowsGraphicsItem::getFormArrow()
{
    return m_formArrows;
}

QPointF ArrowsGraphicsItem::getStartPosition()
{
    return *m_StartPositionItem;
}

QPointF ArrowsGraphicsItem::getEndPosition()
{
    return *m_EndPositionItem;
}

int ArrowsGraphicsItem::getArrowWidth()
{
    return m_ArrowWidth;
}

int ArrowsGraphicsItem::getArrowHeight()
{
    return m_ArrowHeight;
}


int ArrowsGraphicsItem::getArrowHeadSize()
{
    return arrowHeadSize;
}

int ArrowsGraphicsItem::getLineThicknessSize()
{
    return m_LineThickness;
}

QColor ArrowsGraphicsItem::getFillColor()
{
    return *ItemFillColorArrow;
}

//To do redefine virtual method inherit from BaseGraphicItem class
// Get parameters for an ArrowsGraphicsItem
void ArrowsGraphicsItem::getParameters(QSettings *settings, int itemIdex)
{
    QString path="item"+QString::number(itemIdex)+"/";
    settings->setValue(path+"WithoutAnchorPoint",m_WithoutAnchorPoint);
    settings->setValue(path+"OneAnchorPoint",m_OneAnchorPoint);
    settings->setValue(path+"TwoAnchorPointst",m_TwoAnchorPoints);
    settings->setValue(path+"arrowHeadSize",arrowHeadSize);
    settings->setValue(path+"ArrowWidth",m_ArrowWidth);
    settings->setValue(path+"ArrowHeight",m_ArrowHeight);
    settings->setValue(path+"LineThickness",m_LineThickness);
    settings->setValue(path+"SizeHeadTypeChoice",m_SizeHeadTypeChoice);
    /*QPointF *m_StartPositionItem;
    QPointF *m_EndPositionItem;*/
//    settings->setValue(path+"StartPositionItem",*m_StartPositionItem); // Cf. Bug of setParameters below
//    settings->setValue(path+"EndPositionItem",*m_EndPositionItem);
    settings->setValue(path+"Color",m_Color.name());
    settings->setValue(path+"ItemOutlineColorArrow",*ItemOutlineColorArrow);
    settings->setValue(path+"ItemFillColorArrow",*ItemFillColorArrow);
    //settings->setValue(path+"ArrowHeadStart",ArrowHeadStart);
    //settings->setValue(path+"ArrowHeadStart",ArrowHeadEnd);

    //FormArrows *m_formArrows;
}

void ArrowsGraphicsItem::setParameters(QSettings *settings, int itemIdex)
{
    QString path="item"+QString::number(itemIdex)+"/";
    m_WithoutAnchorPoint=settings->value(path+"WithoutAnchorPoint").toBool();
    m_OneAnchorPoint=settings->value(path+"OneAnchorPoint").toBool();
    m_TwoAnchorPoints=settings->value(path+"TwoAnchorPointst").toBool();
    arrowHeadSize=settings->value(path+"arrowHeadSize").toInt();
    m_ArrowWidth=settings->value(path+"ArrowWidth").toInt();
    m_ArrowHeight=settings->value(path+"ArrowHeight").toInt();
    m_LineThickness=settings->value(path+"LineThickness").toInt();
    // Don't delete these until the
    //Debug temp redefine here the default ligne m_LineThickness for incorrect values
    //if(m_LineThickness < 3) m_LineThickness = 3; // <- Bug the LineThinckness is between 1 and 4 (see FormArrows class you can search in code methods using: ui->comboBoxLineThicknessContents->currentIndex()) + 1; )
    if(m_LineThickness > 4) m_LineThickness = 2;
    if(m_LineThickness < 1) m_LineThickness = 3;
    //if(m_LineThickness > 4) m_LineThickness = m_formArrows->getDefaultLineThickness(); // <- Don't use bug with values send by FormArrows
    //end Debug temp
    m_SizeHeadTypeChoice=settings->value(path+"SizeHeadTypeChoice").toInt();
//    m_StartPositionItem=settings->value(path+"StartPositionItem").toPointF(); // Bug cannot convert QPointF* to
//    m_EndPositionItem=settings->value(path+"EndPositionItem").toPointF();     //  QPointF in assignement
    m_Color.setNamedColor(settings->value(path+"Color").toString());
    ItemOutlineColorArrow->setNamedColor(settings->value(path+"ItemOutlineColorArrow").toString());
    ItemFillColorArrow->setNamedColor(settings->value(path+"ItemFillColorArrow").toString());
}

