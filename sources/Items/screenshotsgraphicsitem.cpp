/*
================================================
* File:         screenshotsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Manage screenshot items
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QPainter>
#include <QPixmap>

#include "screenshotsgraphicsitem.h"

// Constructor, destructor
// -----------------------

ScreenshotsGraphicsItem::ScreenshotsGraphicsItem(const QPixmap& pix, QGraphicsItem* parent)
        : BaseGraphicItem(parent)
{
    setScreenshot(pix);
}

// Virtual methods from BaseGraphicItem
// ------------------------------------

QRectF ScreenshotsGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void ScreenshotsGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QPixmap scaledScreenshot = m_screenshot.scaled(m_rect.toRect().size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter->drawPixmap(m_rect.toRect(), scaledScreenshot);

    BaseGraphicItem::paint(painter, option, widget);
}

int ScreenshotsGraphicsItem::type() const
{
    return CustomTypes::ScreenshotGraphicsItem;
}

// Getters and setters
// -------------------

void ScreenshotsGraphicsItem::setScreenshot(const QPixmap& screenshot)
{
    m_screenshot = screenshot;

    // Set the content rect accordingly
    setRect(QRectF(-m_screenshot.width()/4, -m_screenshot.height()/4, m_screenshot.width()/2, m_screenshot.height()/2));
}











