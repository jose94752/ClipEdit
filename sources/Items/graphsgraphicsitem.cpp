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

//    m_heightBar = 45;        //pour les histogrames, la larguer d'une bare et la distance entre deux bares
//    m_heightSpace = m_heightBar/3;

      m_heightBar = BAR;        //pour les histogrames, la larguer d'une bare et la distance entre deux bares
      m_heightSpace = SPACE;

}


// Virtual methods from BaseGraphicItem
// -----------------------------------

QRectF GraphsGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void GraphsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    qDebug () << "paint GraphsGraphicsItem"  << endl;

    BaseGraphicItem::paint(painter, option, widget);

    if(m_infos.m_type == 0)
    {
        qDebug () << "paint GraphsGraphicsItem pie"  << endl;

        this->drawPie(painter, option, widget);
    }
    else
    if(m_infos.m_type == 1)
    {
        this->drawLine(painter, option, widget);
    }
    else
    if(m_infos.m_type == 2)     //to do
    {
       this->drawHisto(painter, option, widget);
    }
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

    //qDebug() << "Set Infos title " << m_infos.m_title;
}



//transform coordonates

void GraphsGraphicsItem::calcSizesLine()
{
    double minx = 0, miny = 0, maxx = 0, maxy = 0;

    int nbPoints = m_infos.m_Points.size();

    for ( int i=0; i < nbPoints; i++)
    {
        if ( m_infos.m_Points.at(i).x() < minx )
            minx = m_infos.m_Points.at(i).x();

        if ( m_infos.m_Points.at(i).x() > maxx )
            maxx = m_infos.m_Points.at(i).x();

        if ( m_infos.m_Points.at(i).y() < miny )
            miny = m_infos.m_Points.at(i).y();

        if ( m_infos.m_Points.at(i).y() > maxy )
            maxy = m_infos.m_Points.at(i).y();
    }

    qDebug() << " calcSizesLine tailles" << minx << miny << maxx << maxy;
    m_graphRect = QRectF ( QPointF (minx, miny), QPointF (maxx, maxy));
}


void GraphsGraphicsItem::calcSizesHisto()
{
    int nbPoints = m_infos.m_Points.size();

    double miny = 0, maxy = 0;
    double minx = 0, maxx = 0;

    maxx = nbPoints * ( BAR+SPACE );

    for ( int i=0; i < nbPoints; i++)
    {
        if ( m_infos.m_Points.at(i).y() < miny )
            miny = m_infos.m_Points.at(i).y();

        if ( m_infos.m_Points.at(i).y() > maxy )
            maxy = m_infos.m_Points.at(i).y();

    }
     m_graphRect = QRectF ( QPointF (minx, miny), QPointF (maxx, maxy));
}


//QPoint transformPoint( const QPointF &pointGraph) const;

//height y
//width x
QPointF GraphsGraphicsItem::transformPoint( const QPointF &pointGraph) const
{

    double  scaleX = m_pictRect.width() / m_graphRect.width();
    double  scaleY = m_pictRect.height() / m_graphRect.height();

//   double translationX = m_pictRect.topLeft().x() + m_graphRect.topLeft().x();
//   double translationY = m_pictRect.bottomLeft().y() + m_graphRect.bottomLeft().y();

 //   double x = translationX + pointGraph.x() * scaleX;
 //   double y = translationY + pointGraph.y() * scaleY;

    double x = m_pictRect.topLeft().x() + pointGraph.x() * scaleX;
    double y =  m_pictRect.bottomLeft().y() - pointGraph.y() * scaleY;

/*
 //debug
    qDebug() << "transformPoint" << pointGraph.x() << pointGraph.y();
    qDebug() << "scale x, y" << scaleX << scaleY;

    qDebug() << "pictRect" << m_pictRect.x() << m_pictRect.y();
    qDebug() << "graphRect" << m_graphRect.x() << m_graphRect.y();

    qDebug() << "pictRect width height " << m_pictRect.width() << m_pictRect.height();
    qDebug() << "graphRect width height" << m_graphRect.width() << m_graphRect.height();

    qDebug() << "scalex, scale y" << scaleX << scaleY;
    qDebug() << "x y" << x << y ;
*/
    return QPointF (x,y);
}


void GraphsGraphicsItem::transformPointsLine( )
{
   int nbPoints = m_infos.m_Points.size();

   m_GraphPoints.clear();
   for( int i=0; i<nbPoints ; i++)
   {
      m_GraphPoints.append( transformPoint( m_infos.m_Points.at(i) ) );
   }
}

void GraphsGraphicsItem::transformPointsHisto( )
{
   double  scaleX = m_pictRect.width() / m_graphRect.width();
//   double  scaleY = m_pictRect.height() / m_graphRect.height();

   m_heightBar = BAR * scaleX;
   m_heightSpace = SPACE * scaleX;

   transformPointsLine( );
}

//pour les pies
void GraphsGraphicsItem::transformArcsPie( )
{
   int nbPoints = m_infos.m_Arcs.size();
   double sizeTotal = 0;

   for( int i=0; i<nbPoints ; i++)
   {
       sizeTotal += m_infos.m_Arcs.at(i);
   }

   m_GraphArcs.clear();
   for( int i=0; i<nbPoints ; i++)
   {
       m_GraphArcs.append( m_infos.m_Arcs.at(i)/ sizeTotal * 360.0);
   }
  // qDebug() << "GraphsGraphicsItem::transformArcsPie nb points " <<  m_GraphArcs.size();
}



//rectangles pour les textes : titre et legend, en coordones ecran
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

    qDebug() << "calcul rects pictrect " << m_pictRect.width() << m_pictRect.height();
}


// Drawing titre et legend
// -------

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


//drawing axes
void GraphsGraphicsItem::drawAxis(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen( m_infos.m_color);
    painter->setPen(pen);

    painter->drawLine( m_pictRect.bottomLeft(), m_pictRect.bottomRight() );
    painter->drawLine( m_pictRect.bottomLeft(), m_pictRect.topLeft() );
}



void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Pie";

    calculRects();
    transformArcsPie();

    int nbPoints = m_GraphArcs.size();

    qDebug() << "nb points" << nbPoints;
    //Qt::NoBrush
    Qt::BrushStyle style = Qt::SolidPattern ;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);     //Qt::yellow

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    double localArc = 0;
    int i = 0;

    //int radius = pictRect.width()-;

    style = Qt::SolidPattern;
    for( i = 0; i < nbPoints; i++)
    {
        QPen pen( m_infos.m_Colors.at(i) );
        pen.setWidth(0);
        painter->setPen(pen);
        QBrush brush( m_infos.m_Colors.at(i), style);
        painter->setBrush(brush);
        painter->drawPie( m_pictRect, localArc*16, m_GraphArcs.at(i)*16);
        //double arcText = (localArc+m_infos.m_Arcs.at(i)/2) 3.14/180;
        localArc += m_GraphArcs.at(i);
    }
    drawTitle(painter, option, widget);
    drawLegend(painter, option, widget);

    BaseGraphicItem::paint(painter, option, widget);
}


/*
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
*/


void GraphsGraphicsItem::drawHisto(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Histo";

    calculRects();
    calcSizesHisto();
    transformPointsHisto( );
    //transformPointsLine( );

    int nbPoints = m_infos.m_Points.size();
    Qt::BrushStyle style = Qt::SolidPattern;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);
    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    int i = 0;
   // int yAxe = pictRect.bottom();
   // int widLine = 10;
   // int space = 10;
    style = Qt::SolidPattern;
    for( i = 0; i < nbPoints; i++)
    {

        QPen pen( m_infos.m_Colors.at(i));
        pen.setWidth(0);
        painter->setPen(pen);
        QBrush brush( m_infos.m_Colors.at(i), style);
        painter->setBrush(brush);

        //QRect rect( m_pictRect.x()+i*(widLine+space), m_pictRect.bottomLeft().y()- m_infos.m_Arcs.at(i), widLine, m_infos.m_Arcs.at(i) );
        //double x1rect = i*(widLine+space)
        //QPointF
        //QRect rect( m_pictRect.x()+i*(widLine+space), m_pictRect.bottomLeft().y()-
        //           m_infos.m_Arcs.at(i), widLine, m_infos.m_Arcs.at(i) );

        QRect rect;
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

    //int nbPoints = m_GraphPoints.size();
    calculRects();
    calcSizesLine();
    transformPointsLine( );

    Qt::BrushStyle style = Qt::SolidPattern; ;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);

    painter->setBackground( m_infos.m_backColor);
    painter->fillRect( m_pictRect, brush);

    style = Qt::SolidPattern;

   // int yAxe = pictRect.bottom();
    int widLine = 1;
    QPen pen( m_infos.m_color);
    pen.setWidth(widLine);
    painter->setPen(pen);

   // qDebug() << "nb points" << nbPoints ;
/*
 * //avec des lines
    for(int i = 0; i < nbPoints-1; i++)
    {
        QPoint p1( pictRect.x()+m_infos.m_Points.at(i).x(), pictRect.bottomLeft().y()- m_infos.m_Points.at(i).y() );
        QPoint p2( pictRect.x()+m_infos.m_Points.at(i+1).x(), pictRect.bottomLeft().y()- m_infos.m_Points.at(i+1).y() );
        qDebug() << "coordm_graphs p1" << p1.x() << "  " << p1.y() << " coords p2 " << p2.x() << "  " << p2.y() ;

        painter->drawLine( p1, p2 );

    }
*/
    QVector<QPointF> vect = QVector<QPointF>::fromList( m_GraphPoints);
    QPolygonF poly(vect);
    /*
    for( int i=0; i<poly.size(); i++)
    {
        int x = poly.at(i).x() + m_pictRect.x();
        int y = m_pictRect.bottomLeft().y()-poly.at(i).y();
        QPointF p (x,y);
        poly[i]=p;
        //poly.at(i).setY( y);

    }
    */
    painter->drawPolyline(poly );

    //draw litle cercles around the points
    int radius = 5;
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter->setPen(pen);
    for( int i=0; i<poly.size(); i++)
    {
        painter->drawEllipse( poly.at(i), radius, radius);
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

