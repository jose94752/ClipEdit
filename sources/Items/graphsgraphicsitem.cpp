/*
====================================================
* File:         graphsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define charts and related properties
====================================================
*/

// Includes
// --------

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

#include <QPaintDevice>
#include <QApplication>

#include "graphsgraphicsitem.h"


// Constructor
// -----------

GraphsGraphicsItem::GraphsGraphicsItem(QGraphicsItem* parent) : BaseGraphicItem( parent )
{
    //m_infos.m_boundingRect = {-100,-100,200,200};

    // setRect( QRectF(-50, -50, 100, 100));

    //setRect( QRectF(m_infos.m_boundingRect));
}


// Pure virtual methods implementation
// -----------------------------------

QRectF GraphsGraphicsItem::boundingRect() const
{
    //m_infos.m_boundingRect = {-100,-100,200,200};
    //return QRectF(0,0,500,500);

    //return m_infos.m_boundingRect;

    return BaseGraphicItem::boundingRect();
}



void GraphsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    qDebug () << "paint GraphsGraphicsItem"  << endl;

    BaseGraphicItem::paint(painter, option, widget);

    if(m_infos.m_type == 0)
    {
        this->drawPie(painter, option, widget);
    }
    else
    if(m_infos.m_type == 1)
    {
       this->drawHisto(painter, option, widget);
    }
    else
    if(m_infos.m_type == 2)
    {
        this->drawLine(painter, option, widget);
    }
/*
    else
    if(m_infos.m_type == 3)
    {
        this->drawArea(painter, option, widget);
    }
*/
}


int GraphsGraphicsItem::type() const
{
    return BaseGraphicItem::ChartGraphicsItem;
}

// Getters and setters
// -------------------

void  GraphsGraphicsItem::setInfos(const GraphsInfo& infos)
{
    qDebug() << "Set Infos";

    m_infos = infos;
    m_rect = m_infos.m_boundingRect;
    setRect( QRectF(m_infos.m_boundingRect));
    qDebug() << "Set Infos title " << m_infos.m_title;
}

// Drawing
// -------

/*
void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Pie";

    QColor col[] = {Qt::red, Qt::darkRed, Qt::green, Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan,
            Qt::darkCyan, Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow,
            Qt::gray, Qt::darkGray };

    //m_infos.m_boundingRect = {-100,-100,200,200};

    QBrush brush( m_infos.m_backColor);     //Qt::yellow
    painter->setBackground(m_infos.m_backColor);
    painter->fillRect(m_infos.m_boundingRect, brush);

    double rat = 10.0;
    for(int i = 0; i < rat; i++)
    {
        //QPen pen(0x059605);
        QPen pen( col[i]);
        pen.setWidth(3);
        painter->setPen(pen);
        //QBrush brush(0x059605);
        QBrush brush( col[i]);

        painter->setBrush(brush);
        double startArc = (double)i*360.0/rat*16.0, endArc = 360.0/rat*16.0;
        painter->drawPie(m_infos.m_boundingRect, startArc, endArc);
    }

    //    painter->drawPie(m_infos.m_boundingRect, 0, 10);
    BaseGraphicItem::paint(painter, option, widget);
}
*/


void GraphsGraphicsItem::drawTitle(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen( m_infos.m_color);
    painter->setPen(pen);

    painter->setFont( m_infos.m_titleFont);

    //QPoint tp ( pictRect.x()+pictRect.width()/2 - fm.width( m_infos.m_title)/2, pictRect.bottomRight().y()+fm.height());
    painter->drawText( m_titleRect, Qt::AlignCenter, m_infos.m_title);

}

void GraphsGraphicsItem::drawLegend(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen( m_infos.m_color);
    painter->setPen(pen);

    painter->setFont( m_infos.m_legendFont);

    QFontMetrics fmL( m_infos.m_legendFont);
    //int legendHeight = fmL.height();
    int size = 14;
    int space = size;

    int localwidth = 0;
    for( int i = 0; i < m_infos.m_Legends.size(); i++)
    {
        int xLeft = m_legendRect.topLeft().x() + localwidth;
        int wid = fmL.width( m_infos.m_Legends.at(i));

        localwidth += wid+size+space;

        //draw a little rectangle before
        QBrush brush( m_infos.m_Colors.at(i), Qt::SolidPattern);
        painter->setBrush(brush);

        QRectF  rect = m_legendRect;
        QPointF rectTopLeft( xLeft, m_legendRect.bottomLeft().y()- size);
        QPointF rectBottomRight( xLeft+size, m_legendRect.bottomLeft().y());

        rect.setTopLeft( rectTopLeft);
        rect.setBottomRight( rectBottomRight);

        painter->drawRect( rect);

        rect = m_legendRect;
        QPointF legendTopLeft( xLeft+size, m_legendRect.topLeft().y());
        QPointF legendbottomRight( xLeft+size+wid, m_legendRect.bottomRight().y());

        rect.setTopLeft( legendTopLeft);
        rect.setBottomRight( legendbottomRight);

        painter->drawText( rect, Qt::AlignLeft, m_infos.m_Legends.at(i) ) ;
     }
}


void GraphsGraphicsItem::drawAxis(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen( m_infos.m_color);
    painter->setPen(pen);

    painter->drawLine( m_pictRect.bottomLeft(), m_pictRect.bottomRight() );
    painter->drawLine( m_pictRect.bottomLeft(), m_pictRect.topLeft() );
}


void GraphsGraphicsItem::calculRects()
{
    m_pictRect = m_rect;
    int textHeight = 0;
    int legendHeight = 0;

    m_titleRect = {0,0,0,0};
    m_legendRect = {0,0,0,0};

    if( m_infos.m_title != "")
    {
        QFontMetrics fm( m_infos.m_titleFont);
        textHeight = fm.height();

        QPointF titleTopLeft( m_pictRect.topLeft().x(), m_pictRect.bottomRight().y()-textHeight);
        QPointF titlebottomRight( m_pictRect.bottomRight().x()-textHeight-legendHeight, m_pictRect.bottomRight().y());

        m_titleRect.setTopLeft( titleTopLeft);
        m_titleRect.setBottomRight( titlebottomRight);

    }
    if( m_infos.m_Legends.size() > 0 )
    {
       QFontMetrics fmL(m_infos.m_legendFont);
       legendHeight = fmL.height();

       QPointF legendTopLeft( m_pictRect.topLeft().x(), m_pictRect.bottomRight().y()-textHeight-legendHeight);
       QPointF legendbottomRight( m_pictRect.bottomRight().x()-textHeight-legendHeight, m_pictRect.bottomRight().y()-textHeight);

       m_legendRect.setTopLeft( legendTopLeft);
       m_legendRect.setBottomRight( legendbottomRight);
    }
    m_pictRect.setWidth(m_pictRect.width()-textHeight-legendHeight);
    m_pictRect.setHeight(m_pictRect.height()-textHeight-legendHeight);
}


void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Pie";

    //m_infos.m_boundingRect = {-100,-100,200,200};

    calculRects();

    int nbPoints = m_infos.m_Arcs.size();
    //Qt::NoBrush
    Qt::BrushStyle style = Qt::SolidPattern ;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);     //Qt::yellow

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    int localArc = 0;
    int i = 0;
    /*
    if( m_infos.m_transparent)
    {
        style = Qt::Dense3Pattern;

    }
    */

    //int radius = pictRect.width()-;

    style = Qt::SolidPattern;
    for( i = 0; i < nbPoints; i++)
    {
        QPen pen( m_infos.m_Colors.at(i) );
        pen.setWidth(0);
        painter->setPen(pen);
        QBrush brush( m_infos.m_Colors.at(i), style);
        painter->setBrush(brush);
        painter->drawPie( m_pictRect, localArc*16, m_infos.m_Arcs.at(i)*16);
        //double arcText = (localArc+m_infos.m_Arcs.at(i)/2) 3.14/180;
        localArc += m_infos.m_Arcs.at(i);
    }
    if( localArc < 360)
    {
        QPen pen( m_infos.m_Colors.at(i));
        pen.setWidth(0);
        painter->setPen(pen);
        QBrush brush( m_infos.m_Colors.at(i), style);
        painter->setBrush(brush);
        painter->drawPie( m_pictRect, localArc*16, (360-localArc)*16);
    }
/*
    QPen pen( m_infos.m_color);
    painter->setPen(pen);

    painter->setFont( m_infos.m_titleFont);
    QPoint tp ( pictRect.x()+pictRect.width()/2 - fm.width( m_infos.m_title)/2, pictRect.bottomRight().y()+fm.height());
    painter->drawText(tp, m_infos.m_title);
*/

    drawTitle(painter, option, widget);
    drawLegend(painter, option, widget);

    BaseGraphicItem::paint(painter, option, widget);
}




void GraphsGraphicsItem::drawHisto(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Histo";

    calculRects();

    int nbPoints = m_infos.m_Arcs.size();
    Qt::BrushStyle style = Qt::SolidPattern;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);     //Qt::yellow

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    int i = 0;
    /*
    if( m_infos.m_transparent)
    {
        style = Qt::Dense3Pattern;

    }
    */

   // int yAxe = pictRect.bottom();
    int widLine = 10;
    int space = 10;
    style = Qt::SolidPattern;
    for( i = 0; i < nbPoints; i++)
    {

        QPen pen( m_infos.m_Colors.at(i));
        pen.setWidth(0);
        painter->setPen(pen);
        QBrush brush( m_infos.m_Colors.at(i), style);
        painter->setBrush(brush);
        QRect rect( m_pictRect.x()+i*(widLine+space), m_pictRect.bottomLeft().y()- m_infos.m_Arcs.at(i), widLine, m_infos.m_Arcs.at(i) );
        painter->drawRect(rect);
    }

    drawTitle(painter, option, widget);
    drawLegend(painter, option, widget);

    drawAxis(painter, option, widget);

    BaseGraphicItem::paint(painter, option, widget);
}



void GraphsGraphicsItem::drawLine(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Line";

    calculRects();

    int nbPoints = m_infos.m_Points.size();

    Qt::BrushStyle style = Qt::SolidPattern; ;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    style = Qt::SolidPattern;

   // int yAxe = pictRect.bottom();
    int widLine = 1;
    QPen pen( m_infos.m_color);
    pen.setWidth(widLine);
    painter->setPen(pen);

    qDebug() << "nb points" << nbPoints ;
/*
 * //avec des lines
    for(int i = 0; i < nbPoints-1; i++)
    {
        QPoint p1( pictRect.x()+m_infos.m_Points.at(i).x(), pictRect.bottomLeft().y()- m_infos.m_Points.at(i).y() );
        QPoint p2( pictRect.x()+m_infos.m_Points.at(i+1).x(), pictRect.bottomLeft().y()- m_infos.m_Points.at(i+1).y() );
        qDebug() << "coords p1" << p1.x() << "  " << p1.y() << " coords p2 " << p2.x() << "  " << p2.y() ;

        painter->drawLine( p1, p2 );

    }
*/
    QVector<QPoint> vect = QVector<QPoint>::fromList( m_infos.m_Points);
    QPolygon poly(vect);
    for( int i=0; i<poly.size(); i++)
    {
        int x = poly.at(i).x() + m_pictRect.x();
        int y = m_pictRect.bottomLeft().y()-poly.at(i).y();
        QPoint p (x,y);
        poly[i]=p;
        //poly.at(i).setY( y);

    }
    painter->drawPolyline(poly );

    //draw litle cercles around the points
    int radius = 5;
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter->setPen(pen);
    for( int i=0; i<poly.size(); i++)
    {
        painter->drawEllipse( poly.at(i) ,radius, radius);
    }

/*
//  debug
    qDebug() << "Nb points poligon" << vect.size();
    for(int i = 0; i < vect.size() -1; i++)
    {
        QPoint p1( poly.point(i) );
        QPoint p2( poly.point(i) );
        qDebug() << "coords p1" << p1.x() << "  " << p1.y() << " coords p2 " << p2.x() << "  " << p2.y() ;
    }
*/

    drawTitle(painter, option, widget);

    drawAxis(painter, option, widget);

    BaseGraphicItem::paint(painter, option, widget);
}


/*
void GraphsGraphicsItem::drawArea(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Area";


    QRectF pictRect = m_rect;

    QFont font("times", 14);
    QFontMetrics fm(font);
    int textHeight = fm.height();

    pictRect.setWidth(pictRect.width() - textHeight);
    pictRect.setHeight(pictRect.height() - textHeight);

    Qt::BrushStyle style = Qt::SolidPattern;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( pictRect, brush);

    style = Qt::SolidPattern;
    brush.setColor( m_infos.m_color);
    brush.setStyle( style);

   // int yAxe = pictRect.bottom();
    int widLine = 1;
    QPen pen( m_infos.m_color);
    pen.setWidth(widLine);
    painter->setPen(pen);

    int nbPoints = m_infos.m_Points.size();
    qDebug() << "nb points 1" << nbPoints ;

    int nbPoints2 = m_infos.m_Points2.size();
    qDebug() << "nb points 2" << nbPoints2 ;

    QVector<QPoint> vect = QVector<QPoint>::fromList( m_infos.m_Points);
    QVector<QPoint> line2 = QVector<QPoint>::fromList( m_infos.m_Points2);

    QPolygon poly(vect);
    //QPolygon poly2(line2);
    poly.append(line2);

    int nbPoints3 = poly.size();
    qDebug() << "nb points tot" << nbPoints3 ;

    for( int i=0; i<poly.size(); i++)
    {
        int x = poly.at(i).x() + pictRect.x();
        int y = pictRect.bottomLeft().y()-poly.at(i).y();
        QPoint p (x,y);
        poly[i]=p;
        //poly.at(i).setY( y);

    }

    //painter->drawPolyline(poly);
    //painter->drawPolyline(poly2);

    painter->drawPolygon(poly, Qt::WindingFill );

    painter->setFont(font);

    QPoint tp ( pictRect.x()+pictRect.width()/2 - fm.width( m_infos.m_title)/2, pictRect.bottomRight().y()+fm.height());
    painter->drawText(tp, m_infos.m_title);

    BaseGraphicItem::paint(painter, option, widget);
}
*/
