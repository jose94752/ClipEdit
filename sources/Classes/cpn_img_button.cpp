#include "cpn_img_button.h"

#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>


My_Img_Button::My_Img_Button(QWidget* parent): QWidget(parent),
                current_image(IMG_NONE), img_height(0), img_width(0) {

//  setMouseTracking(true);

    setMinimumSize( QSize((int) img_width, (int) img_height) );
    setMaximumSize( QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX) );

    setCursor(Qt::PointingHandCursor);
}


void My_Img_Button::mouseReleaseEvent(QMouseEvent* event) {
    if ((event != NULL) && (event->button() == Qt::LeftButton)) {
        emit on_click();
    }
}


void My_Img_Button::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

//  if (paint_event != NULL) {
        QPainter painter(this);

        painter.drawImage(event->rect(), image, event->rect());
//  }
}


void My_Img_Button::set_image(t_Img new_image) {
    if ((new_image != IMG_NONE) && (new_image != current_image)) {
        current_image = new_image;

        switch (current_image) {
        case IMG_NONE:
            break;

        case IMG_ERASER:
            {
                uchar* scanline;

                image = QImage(25, 22, QImage::Format_RGBA8888_Premultiplied);

                scanline = image.scanLine(0);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x00; scanline[40 + 1] = 0x00; scanline[40 + 2] = 0x00; scanline[40 + 3] = 0x00;
                scanline[44 + 0] = 0x00; scanline[44 + 1] = 0x00; scanline[44 + 2] = 0x00; scanline[44 + 3] = 0x00;
                scanline[48 + 0] = 0x00; scanline[48 + 1] = 0x00; scanline[48 + 2] = 0x00; scanline[48 + 3] = 0x00;
                scanline[52 + 0] = 0x00; scanline[52 + 1] = 0x00; scanline[52 + 2] = 0x00; scanline[52 + 3] = 0x00;
                scanline[56 + 0] = 0x00; scanline[56 + 1] = 0x00; scanline[56 + 2] = 0x00; scanline[56 + 3] = 0x00;
                scanline[60 + 0] = 0x04; scanline[60 + 1] = 0x03; scanline[60 + 2] = 0x05; scanline[60 + 3] = 0x08;
                scanline[64 + 0] = 0x07; scanline[64 + 1] = 0x05; scanline[64 + 2] = 0x08; scanline[64 + 3] = 0x0D;
                scanline[68 + 0] = 0x01; scanline[68 + 1] = 0x00; scanline[68 + 2] = 0x01; scanline[68 + 3] = 0x02;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(1);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x00; scanline[40 + 1] = 0x00; scanline[40 + 2] = 0x00; scanline[40 + 3] = 0x00;
                scanline[44 + 0] = 0x00; scanline[44 + 1] = 0x00; scanline[44 + 2] = 0x00; scanline[44 + 3] = 0x00;
                scanline[48 + 0] = 0x00; scanline[48 + 1] = 0x00; scanline[48 + 2] = 0x00; scanline[48 + 3] = 0x00;
                scanline[52 + 0] = 0x00; scanline[52 + 1] = 0x00; scanline[52 + 2] = 0x00; scanline[52 + 3] = 0x00;
                scanline[56 + 0] = 0x14; scanline[56 + 1] = 0x0F; scanline[56 + 2] = 0x17; scanline[56 + 3] = 0x25;
                scanline[60 + 0] = 0x50; scanline[60 + 1] = 0x43; scanline[60 + 2] = 0x5E; scanline[60 + 3] = 0x8F;
                scanline[64 + 0] = 0x60; scanline[64 + 1] = 0x57; scanline[64 + 2] = 0x75; scanline[64 + 3] = 0xA7;
                scanline[68 + 0] = 0x2F; scanline[68 + 1] = 0x25; scanline[68 + 2] = 0x36; scanline[68 + 3] = 0x56;
                scanline[72 + 0] = 0x03; scanline[72 + 1] = 0x02; scanline[72 + 2] = 0x03; scanline[72 + 3] = 0x06;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(2);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x00; scanline[40 + 1] = 0x00; scanline[40 + 2] = 0x00; scanline[40 + 3] = 0x00;
                scanline[44 + 0] = 0x00; scanline[44 + 1] = 0x00; scanline[44 + 2] = 0x00; scanline[44 + 3] = 0x00;
                scanline[48 + 0] = 0x00; scanline[48 + 1] = 0x00; scanline[48 + 2] = 0x00; scanline[48 + 3] = 0x00;
                scanline[52 + 0] = 0x0C; scanline[52 + 1] = 0x09; scanline[52 + 2] = 0x0E; scanline[52 + 3] = 0x17;
                scanline[56 + 0] = 0x68; scanline[56 + 1] = 0x59; scanline[56 + 2] = 0x7C; scanline[56 + 3] = 0xB7;
                scanline[60 + 0] = 0xA2; scanline[60 + 1] = 0xBF; scanline[60 + 2] = 0xE1; scanline[60 + 3] = 0xFC;
                scanline[64 + 0] = 0xA7; scanline[64 + 1] = 0xD1; scanline[64 + 2] = 0xF1; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x8D; scanline[68 + 1] = 0x8D; scanline[68 + 2] = 0xB4; scanline[68 + 3] = 0xEB;
                scanline[72 + 0] = 0x30; scanline[72 + 1] = 0x26; scanline[72 + 2] = 0x37; scanline[72 + 3] = 0x57;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(3);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x00; scanline[40 + 1] = 0x00; scanline[40 + 2] = 0x00; scanline[40 + 3] = 0x00;
                scanline[44 + 0] = 0x00; scanline[44 + 1] = 0x00; scanline[44 + 2] = 0x00; scanline[44 + 3] = 0x00;
                scanline[48 + 0] = 0x0C; scanline[48 + 1] = 0x09; scanline[48 + 2] = 0x0E; scanline[48 + 3] = 0x17;
                scanline[52 + 0] = 0x66; scanline[52 + 1] = 0x58; scanline[52 + 2] = 0x7D; scanline[52 + 3] = 0xBB;
                scanline[56 + 0] = 0x8A; scanline[56 + 1] = 0xAD; scanline[56 + 2] = 0xDB; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x9E; scanline[60 + 1] = 0xC8; scanline[60 + 2] = 0xEC; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0xAA; scanline[64 + 1] = 0xD9; scanline[64 + 2] = 0xF7; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0xAA; scanline[68 + 1] = 0xD9; scanline[68 + 2] = 0xF7; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x94; scanline[72 + 1] = 0x8D; scanline[72 + 2] = 0xB8; scanline[72 + 3] = 0xFA;
                scanline[76 + 0] = 0x31; scanline[76 + 1] = 0x26; scanline[76 + 2] = 0x37; scanline[76 + 3] = 0x58;
                scanline[80 + 0] = 0x03; scanline[80 + 1] = 0x02; scanline[80 + 2] = 0x03; scanline[80 + 3] = 0x06;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(4);
                scanline[0 + 0] = 0x00; scanline[0 + 1] = 0x00; scanline[0 + 2] = 0x00; scanline[0 + 3] = 0x00;
                scanline[4 + 0] = 0x00; scanline[4 + 1] = 0x00; scanline[4 + 2] = 0x00; scanline[4 + 3] = 0x00;
                scanline[8 + 0] = 0x00; scanline[8 + 1] = 0x00; scanline[8 + 2] = 0x00; scanline[8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x00; scanline[40 + 1] = 0x00; scanline[40 + 2] = 0x00; scanline[40 + 3] = 0x00;
                scanline[44 + 0] = 0x16; scanline[44 + 1] = 0x10; scanline[44 + 2] = 0x18; scanline[44 + 3] = 0x28;
                scanline[48 + 0] = 0x65; scanline[48 + 1] = 0x58; scanline[48 + 2] = 0x7C; scanline[48 + 3] = 0xB9;
                scanline[52 + 0] = 0x88; scanline[52 + 1] = 0xAC; scanline[52 + 2] = 0xDB; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCA; scanline[56 + 2] = 0xF7; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x88; scanline[60 + 1] = 0xAD; scanline[60 + 2] = 0xDC; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x96; scanline[64 + 1] = 0x99; scanline[64 + 2] = 0xC5; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0xA9; scanline[68 + 1] = 0xD8; scanline[68 + 2] = 0xF6; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0xAA; scanline[72 + 1] = 0xD9; scanline[72 + 2] = 0xF7; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x8E; scanline[76 + 1] = 0x8F; scanline[76 + 2] = 0xB6; scanline[76 + 3] = 0xEC;
                scanline[80 + 0] = 0x37; scanline[80 + 1] = 0x2B; scanline[80 + 2] = 0x3F; scanline[80 + 3] = 0x63;
                scanline[84 + 0] = 0x03; scanline[84 + 1] = 0x02; scanline[84 + 2] = 0x03; scanline[84 + 3] = 0x06;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(5);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x00; scanline[36 + 1] = 0x00; scanline[36 + 2] = 0x00; scanline[36 + 3] = 0x00;
                scanline[40 + 0] = 0x0C; scanline[40 + 1] = 0x09; scanline[40 + 2] = 0x0E; scanline[40 + 3] = 0x17;
                scanline[44 + 0] = 0x65; scanline[44 + 1] = 0x57; scanline[44 + 2] = 0x7C; scanline[44 + 3] = 0xB9;
                scanline[48 + 0] = 0x85; scanline[48 + 1] = 0xB0; scanline[48 + 2] = 0xDF; scanline[48 + 3] = 0xFC;
                scanline[52 + 0] = 0x85; scanline[52 + 1] = 0xCA; scanline[52 + 2] = 0xF8; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCB; scanline[56 + 2] = 0xF8; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xCA; scanline[60 + 2] = 0xF7; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x88; scanline[64 + 1] = 0xBE; scanline[64 + 2] = 0xEB; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x9A; scanline[68 + 1] = 0xCC; scanline[68 + 2] = 0xF1; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0xAB; scanline[72 + 1] = 0xE0; scanline[72 + 2] = 0xFD; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0xAA; scanline[76 + 1] = 0xD9; scanline[76 + 2] = 0xF7; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0x8D; scanline[80 + 1] = 0x8E; scanline[80 + 2] = 0xB5; scanline[80 + 3] = 0xEC;
                scanline[84 + 0] = 0x30; scanline[84 + 1] = 0x25; scanline[84 + 2] = 0x36; scanline[84 + 3] = 0x57;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(6);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x00; scanline[32 + 1] = 0x00; scanline[32 + 2] = 0x00; scanline[32 + 3] = 0x00;
                scanline[36 + 0] = 0x0C; scanline[36 + 1] = 0x09; scanline[36 + 2] = 0x0E; scanline[36 + 3] = 0x17;
                scanline[40 + 0] = 0x65; scanline[40 + 1] = 0x57; scanline[40 + 2] = 0x7B; scanline[40 + 3] = 0xB8;
                scanline[44 + 0] = 0x88; scanline[44 + 1] = 0xAB; scanline[44 + 2] = 0xDA; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x85; scanline[48 + 1] = 0xCA; scanline[48 + 2] = 0xF7; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x85; scanline[52 + 1] = 0xCB; scanline[52 + 2] = 0xF8; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCB; scanline[56 + 2] = 0xF8; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xCB; scanline[60 + 2] = 0xF8; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x85; scanline[64 + 1] = 0xCB; scanline[64 + 2] = 0xF8; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x88; scanline[68 + 1] = 0xAE; scanline[68 + 2] = 0xDD; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x95; scanline[72 + 1] = 0x99; scanline[72 + 2] = 0xC4; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0xAA; scanline[76 + 1] = 0xD9; scanline[76 + 2] = 0xF7; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0xA9; scanline[80 + 1] = 0xD8; scanline[80 + 2] = 0xF6; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0x92; scanline[84 + 1] = 0x8B; scanline[84 + 2] = 0xB6; scanline[84 + 3] = 0xF9;
                scanline[88 + 0] = 0x2F; scanline[88 + 1] = 0x25; scanline[88 + 2] = 0x36; scanline[88 + 3] = 0x56;
                scanline[92 + 0] = 0x03; scanline[92 + 1] = 0x02; scanline[92 + 2] = 0x03; scanline[92 + 3] = 0x06;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(7);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x00; scanline[28 + 1] = 0x00; scanline[28 + 2] = 0x00; scanline[28 + 3] = 0x00;
                scanline[32 + 0] = 0x16; scanline[32 + 1] = 0x10; scanline[32 + 2] = 0x18; scanline[32 + 3] = 0x28;
                scanline[36 + 0] = 0x65; scanline[36 + 1] = 0x57; scanline[36 + 2] = 0x7C; scanline[36 + 3] = 0xB9;
                scanline[40 + 0] = 0x88; scanline[40 + 1] = 0xAB; scanline[40 + 2] = 0xDA; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0x86; scanline[44 + 1] = 0xBA; scanline[44 + 2] = 0xE8; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x85; scanline[48 + 1] = 0xC5; scanline[48 + 2] = 0xF2; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x85; scanline[52 + 1] = 0xCB; scanline[52 + 2] = 0xF8; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCB; scanline[56 + 2] = 0xF8; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xCB; scanline[60 + 2] = 0xF8; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x85; scanline[64 + 1] = 0xCB; scanline[64 + 2] = 0xF8; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x85; scanline[68 + 1] = 0xCA; scanline[68 + 2] = 0xF7; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x88; scanline[72 + 1] = 0xAB; scanline[72 + 2] = 0xD9; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x95; scanline[76 + 1] = 0x97; scanline[76 + 2] = 0xC3; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0xA8; scanline[80 + 1] = 0xD2; scanline[80 + 2] = 0xF1; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0xAA; scanline[84 + 1] = 0xD9; scanline[84 + 2] = 0xF7; scanline[84 + 3] = 0xFF;
                scanline[88 + 0] = 0x8D; scanline[88 + 1] = 0x8E; scanline[88 + 2] = 0xB5; scanline[88 + 3] = 0xEC;
                scanline[92 + 0] = 0x32; scanline[92 + 1] = 0x27; scanline[92 + 2] = 0x39; scanline[92 + 3] = 0x5B;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(8);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x00; scanline[24 + 1] = 0x00; scanline[24 + 2] = 0x00; scanline[24 + 3] = 0x00;
                scanline[28 + 0] = 0x0C; scanline[28 + 1] = 0x09; scanline[28 + 2] = 0x0E; scanline[28 + 3] = 0x17;
                scanline[32 + 0] = 0x66; scanline[32 + 1] = 0x4E; scanline[32 + 2] = 0x72; scanline[32 + 3] = 0xB7;
                scanline[36 + 0] = 0x89; scanline[36 + 1] = 0x89; scanline[36 + 2] = 0xB9; scanline[36 + 3] = 0xFC;
                scanline[40 + 0] = 0x86; scanline[40 + 1] = 0xC5; scanline[40 + 2] = 0xF2; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0x89; scanline[44 + 1] = 0x9F; scanline[44 + 2] = 0xCE; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x86; scanline[48 + 1] = 0xC2; scanline[48 + 2] = 0xEF; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x85; scanline[52 + 1] = 0xCB; scanline[52 + 2] = 0xF8; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCB; scanline[56 + 2] = 0xF8; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xCB; scanline[60 + 2] = 0xF8; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x85; scanline[64 + 1] = 0xCB; scanline[64 + 2] = 0xF8; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x85; scanline[68 + 1] = 0xCB; scanline[68 + 2] = 0xF8; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x85; scanline[72 + 1] = 0xCA; scanline[72 + 2] = 0xF7; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x88; scanline[76 + 1] = 0xB2; scanline[76 + 2] = 0xE0; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0x96; scanline[80 + 1] = 0x98; scanline[80 + 2] = 0xC4; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0xAA; scanline[84 + 1] = 0xDA; scanline[84 + 2] = 0xF7; scanline[84 + 3] = 0xFF;
                scanline[88 + 0] = 0xA8; scanline[88 + 1] = 0xD4; scanline[88 + 2] = 0xF3; scanline[88 + 3] = 0xFF;
                scanline[92 + 0] = 0x6D; scanline[92 + 1] = 0x68; scanline[92 + 2] = 0x88; scanline[92 + 3] = 0xBB;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(9);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x00; scanline[20 + 1] = 0x00; scanline[20 + 2] = 0x00; scanline[20 + 3] = 0x00;
                scanline[24 + 0] = 0x0C; scanline[24 + 1] = 0x09; scanline[24 + 2] = 0x0E; scanline[24 + 3] = 0x17;
                scanline[28 + 0] = 0x6F; scanline[28 + 1] = 0x4F; scanline[28 + 2] = 0x72; scanline[28 + 3] = 0xB9;
                scanline[32 + 0] = 0xCA; scanline[32 + 1] = 0x74; scanline[32 + 2] = 0x9B; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xB8; scanline[36 + 1] = 0x72; scanline[36 + 2] = 0x9C; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0x8D; scanline[40 + 1] = 0x97; scanline[40 + 2] = 0xC7; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0x85; scanline[44 + 1] = 0xC6; scanline[44 + 2] = 0xF4; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x87; scanline[48 + 1] = 0xAF; scanline[48 + 2] = 0xDE; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x89; scanline[52 + 1] = 0x98; scanline[52 + 2] = 0xC8; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x85; scanline[56 + 1] = 0xCA; scanline[56 + 2] = 0xF7; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xCB; scanline[60 + 2] = 0xF8; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x85; scanline[64 + 1] = 0xCB; scanline[64 + 2] = 0xF8; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x85; scanline[68 + 1] = 0xCB; scanline[68 + 2] = 0xF8; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x85; scanline[72 + 1] = 0xCB; scanline[72 + 2] = 0xF8; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x85; scanline[76 + 1] = 0xCA; scanline[76 + 2] = 0xF7; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0x88; scanline[80 + 1] = 0xAA; scanline[80 + 2] = 0xD9; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0x95; scanline[84 + 1] = 0x98; scanline[84 + 2] = 0xC3; scanline[84 + 3] = 0xFF;
                scanline[88 + 0] = 0xA4; scanline[88 + 1] = 0xC9; scanline[88 + 2] = 0xEA; scanline[88 + 3] = 0xFE;
                scanline[92 + 0] = 0x67; scanline[92 + 1] = 0x5F; scanline[92 + 2] = 0x7F; scanline[92 + 3] = 0xB2;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(10);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x16; scanline[20 + 1] = 0x10; scanline[20 + 2] = 0x18; scanline[20 + 3] = 0x28;
                scanline[24 + 0] = 0x6F; scanline[24 + 1] = 0x4F; scanline[24 + 2] = 0x72; scanline[24 + 3] = 0xB8;
                scanline[28 + 0] = 0xCC; scanline[28 + 1] = 0x74; scanline[28 + 2] = 0x9B; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xEC; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xEB; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xBE; scanline[40 + 1] = 0x76; scanline[40 + 2] = 0x9F; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0x8F; scanline[44 + 1] = 0x99; scanline[44 + 2] = 0xC8; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x87; scanline[48 + 1] = 0xB4; scanline[48 + 2] = 0xE2; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x86; scanline[52 + 1] = 0xBD; scanline[52 + 2] = 0xEB; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x88; scanline[56 + 1] = 0xAB; scanline[56 + 2] = 0xDA; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x85; scanline[60 + 1] = 0xC6; scanline[60 + 2] = 0xF4; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x85; scanline[64 + 1] = 0xCB; scanline[64 + 2] = 0xF8; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x85; scanline[68 + 1] = 0xCB; scanline[68 + 2] = 0xF8; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x85; scanline[72 + 1] = 0xCB; scanline[72 + 2] = 0xF8; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x85; scanline[76 + 1] = 0xCB; scanline[76 + 2] = 0xF8; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0x85; scanline[80 + 1] = 0xCA; scanline[80 + 2] = 0xF7; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0x89; scanline[84 + 1] = 0x99; scanline[84 + 2] = 0xCA; scanline[84 + 3] = 0xFF;
                scanline[88 + 0] = 0x7C; scanline[88 + 1] = 0x69; scanline[88 + 2] = 0x92; scanline[88 + 3] = 0xDB;
                scanline[92 + 0] = 0x26; scanline[92 + 1] = 0x1D; scanline[92 + 2] = 0x2B; scanline[92 + 3] = 0x46;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(11);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x0D; scanline[16 + 1] = 0x0A; scanline[16 + 2] = 0x0F; scanline[16 + 3] = 0x18;
                scanline[20 + 0] = 0x70; scanline[20 + 1] = 0x50; scanline[20 + 2] = 0x73; scanline[20 + 3] = 0xBA;
                scanline[24 + 0] = 0xD1; scanline[24 + 1] = 0x73; scanline[24 + 2] = 0x99; scanline[24 + 3] = 0xFC;
                scanline[28 + 0] = 0xEC; scanline[28 + 1] = 0x78; scanline[28 + 2] = 0x99; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xEA; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xBF; scanline[44 + 1] = 0x76; scanline[44 + 2] = 0x9F; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x8D; scanline[48 + 1] = 0x96; scanline[48 + 2] = 0xC6; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x86; scanline[52 + 1] = 0xC4; scanline[52 + 2] = 0xF1; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x87; scanline[56 + 1] = 0xB2; scanline[56 + 2] = 0xE1; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x86; scanline[60 + 1] = 0xBA; scanline[60 + 2] = 0xE8; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x86; scanline[64 + 1] = 0xBF; scanline[64 + 2] = 0xED; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x85; scanline[68 + 1] = 0xCB; scanline[68 + 2] = 0xF8; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x85; scanline[72 + 1] = 0xCB; scanline[72 + 2] = 0xF8; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x85; scanline[76 + 1] = 0xCB; scanline[76 + 2] = 0xF8; scanline[76 + 3] = 0xFF;
                scanline[80 + 0] = 0x86; scanline[80 + 1] = 0xBA; scanline[80 + 2] = 0xE8; scanline[80 + 3] = 0xFF;
                scanline[84 + 0] = 0x7D; scanline[84 + 1] = 0x73; scanline[84 + 2] = 0xA0; scanline[84 + 3] = 0xE7;
                scanline[88 + 0] = 0x1C; scanline[88 + 1] = 0x16; scanline[88 + 2] = 0x20; scanline[88 + 3] = 0x34;
                scanline[92 + 0] = 0x01; scanline[92 + 1] = 0x01; scanline[92 + 2] = 0x01; scanline[92 + 3] = 0x03;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(12);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x0D; scanline[12 + 1] = 0x0A; scanline[12 + 2] = 0x0F; scanline[12 + 3] = 0x18;
                scanline[16 + 0] = 0x70; scanline[16 + 1] = 0x50; scanline[16 + 2] = 0x74; scanline[16 + 3] = 0xBC;
                scanline[20 + 0] = 0xCD; scanline[20 + 1] = 0x74; scanline[20 + 2] = 0x9B; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xEC; scanline[24 + 1] = 0x78; scanline[24 + 2] = 0x99; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xED; scanline[28 + 1] = 0x78; scanline[28 + 2] = 0x99; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xEB; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xB9; scanline[48 + 1] = 0x72; scanline[48 + 2] = 0x9C; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x8D; scanline[52 + 1] = 0x96; scanline[52 + 2] = 0xC6; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x86; scanline[56 + 1] = 0xC0; scanline[56 + 2] = 0xEF; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x8A; scanline[60 + 1] = 0x8B; scanline[60 + 2] = 0xBC; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x87; scanline[64 + 1] = 0xBB; scanline[64 + 2] = 0xEA; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x86; scanline[68 + 1] = 0xC6; scanline[68 + 2] = 0xF3; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x85; scanline[72 + 1] = 0xCB; scanline[72 + 2] = 0xF8; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x85; scanline[76 + 1] = 0xBD; scanline[76 + 2] = 0xEA; scanline[76 + 3] = 0xFE;
                scanline[80 + 0] = 0x77; scanline[80 + 1] = 0x73; scanline[80 + 2] = 0x9E; scanline[80 + 3] = 0xDB;
                scanline[84 + 0] = 0x1C; scanline[84 + 1] = 0x16; scanline[84 + 2] = 0x20; scanline[84 + 3] = 0x34;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(13);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x17; scanline[ 8 + 1] = 0x11; scanline[ 8 + 2] = 0x1A; scanline[ 8 + 3] = 0x2A;
                scanline[12 + 0] = 0x70; scanline[12 + 1] = 0x4E; scanline[12 + 2] = 0x73; scanline[12 + 3] = 0xBC;
                scanline[16 + 0] = 0xC6; scanline[16 + 1] = 0x6C; scanline[16 + 2] = 0x96; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xEA; scanline[20 + 1] = 0x76; scanline[20 + 2] = 0x98; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xED; scanline[24 + 1] = 0x78; scanline[24 + 2] = 0x99; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xED; scanline[28 + 1] = 0x78; scanline[28 + 2] = 0x99; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xEB; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xBF; scanline[52 + 1] = 0x75; scanline[52 + 2] = 0x9F; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0x8F; scanline[56 + 1] = 0x98; scanline[56 + 2] = 0xC7; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x86; scanline[60 + 1] = 0xC1; scanline[60 + 2] = 0xEF; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x87; scanline[64 + 1] = 0xB2; scanline[64 + 2] = 0xE1; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x88; scanline[68 + 1] = 0xAA; scanline[68 + 2] = 0xD9; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x87; scanline[72 + 1] = 0xB9; scanline[72 + 2] = 0xE7; scanline[72 + 3] = 0xFF;
                scanline[76 + 0] = 0x77; scanline[76 + 1] = 0x73; scanline[76 + 2] = 0x9E; scanline[76 + 3] = 0xDB;
                scanline[80 + 0] = 0x26; scanline[80 + 1] = 0x1D; scanline[80 + 2] = 0x2B; scanline[80 + 3] = 0x46;
                scanline[84 + 0] = 0x01; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x01; scanline[84 + 3] = 0x02;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(14);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x0C; scanline[ 4 + 1] = 0x09; scanline[ 4 + 2] = 0x0E; scanline[ 4 + 3] = 0x17;
                scanline[ 8 + 0] = 0x71; scanline[ 8 + 1] = 0x59; scanline[ 8 + 2] = 0x79; scanline[ 8 + 3] = 0xBA;
                scanline[12 + 0] = 0xD1; scanline[12 + 1] = 0x98; scanline[12 + 2] = 0xAD; scanline[12 + 3] = 0xFC;
                scanline[16 + 0] = 0xE0; scanline[16 + 1] = 0x67; scanline[16 + 2] = 0x8F; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xE4; scanline[20 + 1] = 0x6C; scanline[20 + 2] = 0x92; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xEC; scanline[24 + 1] = 0x77; scanline[24 + 2] = 0x98; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xED; scanline[28 + 1] = 0x78; scanline[28 + 2] = 0x99; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xED; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xEA; scanline[52 + 1] = 0x77; scanline[52 + 2] = 0x99; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0xBE; scanline[56 + 1] = 0x75; scanline[56 + 2] = 0x9F; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x8D; scanline[60 + 1] = 0x96; scanline[60 + 2] = 0xC7; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x86; scanline[64 + 1] = 0xC4; scanline[64 + 2] = 0xF2; scanline[64 + 3] = 0xFF;
                scanline[68 + 0] = 0x87; scanline[68 + 1] = 0xB5; scanline[68 + 2] = 0xE3; scanline[68 + 3] = 0xFF;
                scanline[72 + 0] = 0x7F; scanline[72 + 1] = 0x74; scanline[72 + 2] = 0xA1; scanline[72 + 3] = 0xE9;
                scanline[76 + 0] = 0x1C; scanline[76 + 1] = 0x16; scanline[76 + 2] = 0x20; scanline[76 + 3] = 0x34;
                scanline[80 + 0] = 0x01; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x01; scanline[80 + 3] = 0x02;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(15);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x41; scanline[ 4 + 1] = 0x2F; scanline[ 4 + 2] = 0x45; scanline[ 4 + 3] = 0x70;
                scanline[ 8 + 0] = 0xC3; scanline[ 8 + 1] = 0x83; scanline[ 8 + 2] = 0xA5; scanline[ 8 + 3] = 0xFF;
                scanline[12 + 0] = 0xF5; scanline[12 + 1] = 0xD7; scanline[12 + 2] = 0xD0; scanline[12 + 3] = 0xFF;
                scanline[16 + 0] = 0xED; scanline[16 + 1] = 0xAC; scanline[16 + 2] = 0xB7; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xE1; scanline[20 + 1] = 0x6D; scanline[20 + 2] = 0x92; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xE5; scanline[24 + 1] = 0x6D; scanline[24 + 2] = 0x92; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xEC; scanline[28 + 1] = 0x77; scanline[28 + 2] = 0x98; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0x78; scanline[32 + 2] = 0x99; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xED; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xED; scanline[52 + 1] = 0x78; scanline[52 + 2] = 0x99; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0xEB; scanline[56 + 1] = 0x78; scanline[56 + 2] = 0x99; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0xB8; scanline[60 + 1] = 0x71; scanline[60 + 2] = 0x9D; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x8B; scanline[64 + 1] = 0x90; scanline[64 + 2] = 0xC0; scanline[64 + 3] = 0xFE;
                scanline[68 + 0] = 0x79; scanline[68 + 1] = 0x75; scanline[68 + 2] = 0xA1; scanline[68 + 3] = 0xDE;
                scanline[72 + 0] = 0x1E; scanline[72 + 1] = 0x17; scanline[72 + 2] = 0x22; scanline[72 + 3] = 0x37;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(16);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x46; scanline[ 4 + 1] = 0x31; scanline[ 4 + 2] = 0x49; scanline[ 4 + 3] = 0x77;
                scanline[ 8 + 0] = 0xC1; scanline[ 8 + 1] = 0x69; scanline[ 8 + 2] = 0x95; scanline[ 8 + 3] = 0xFF;
                scanline[12 + 0] = 0xE5; scanline[12 + 1] = 0x83; scanline[12 + 2] = 0x9F; scanline[12 + 3] = 0xFF;
                scanline[16 + 0] = 0xF4; scanline[16 + 1] = 0xCC; scanline[16 + 2] = 0xCA; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xEE; scanline[20 + 1] = 0xAC; scanline[20 + 2] = 0xB7; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xE1; scanline[24 + 1] = 0x6D; scanline[24 + 2] = 0x92; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xE5; scanline[28 + 1] = 0x6D; scanline[28 + 2] = 0x92; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xEC; scanline[32 + 1] = 0x76; scanline[32 + 2] = 0x98; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0x78; scanline[36 + 2] = 0x99; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xED; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xED; scanline[52 + 1] = 0x78; scanline[52 + 2] = 0x99; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0xED; scanline[56 + 1] = 0x78; scanline[56 + 2] = 0x99; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0xDB; scanline[60 + 1] = 0x76; scanline[60 + 2] = 0x9B; scanline[60 + 3] = 0xFF;
                scanline[64 + 0] = 0x80; scanline[64 + 1] = 0x5E; scanline[64 + 2] = 0x8A; scanline[64 + 3] = 0xDE;
                scanline[68 + 0] = 0x28; scanline[68 + 1] = 0x1E; scanline[68 + 2] = 0x2D; scanline[68 + 3] = 0x49;
                scanline[72 + 0] = 0x01; scanline[72 + 1] = 0x01; scanline[72 + 2] = 0x01; scanline[72 + 3] = 0x03;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(17);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x11; scanline[ 4 + 1] = 0x0D; scanline[ 4 + 2] = 0x13; scanline[ 4 + 3] = 0x1F;
                scanline[ 8 + 0] = 0x78; scanline[ 8 + 1] = 0x52; scanline[ 8 + 2] = 0x77; scanline[ 8 + 3] = 0xC4;
                scanline[12 + 0] = 0xD1; scanline[12 + 1] = 0x68; scanline[12 + 2] = 0x92; scanline[12 + 3] = 0xFF;
                scanline[16 + 0] = 0xE4; scanline[16 + 1] = 0x7D; scanline[16 + 2] = 0x9C; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xF4; scanline[20 + 1] = 0xCC; scanline[20 + 2] = 0xCA; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xEE; scanline[24 + 1] = 0xAD; scanline[24 + 2] = 0xB8; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xE0; scanline[28 + 1] = 0x67; scanline[28 + 2] = 0x8F; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xE4; scanline[32 + 1] = 0x6D; scanline[32 + 2] = 0x92; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xEC; scanline[36 + 1] = 0x77; scanline[36 + 2] = 0x98; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xED; scanline[40 + 1] = 0x78; scanline[40 + 2] = 0x99; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xED; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xED; scanline[52 + 1] = 0x78; scanline[52 + 2] = 0x99; scanline[52 + 3] = 0xFF;
                scanline[56 + 0] = 0xDC; scanline[56 + 1] = 0x76; scanline[56 + 2] = 0x9A; scanline[56 + 3] = 0xFF;
                scanline[60 + 0] = 0x91; scanline[60 + 1] = 0x64; scanline[60 + 2] = 0x8F; scanline[60 + 3] = 0xE7;
                scanline[64 + 0] = 0x1E; scanline[64 + 1] = 0x17; scanline[64 + 2] = 0x22; scanline[64 + 3] = 0x38;
                scanline[68 + 0] = 0x01; scanline[68 + 1] = 0x01; scanline[68 + 2] = 0x01; scanline[68 + 3] = 0x03;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(18);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x19; scanline[ 8 + 1] = 0x13; scanline[ 8 + 2] = 0x1D; scanline[ 8 + 3] = 0x2F;
                scanline[12 + 0] = 0x7B; scanline[12 + 1] = 0x57; scanline[12 + 2] = 0x80; scanline[12 + 3] = 0xD0;
                scanline[16 + 0] = 0xD0; scanline[16 + 1] = 0x68; scanline[16 + 2] = 0x92; scanline[16 + 3] = 0xFF;
                scanline[20 + 0] = 0xE5; scanline[20 + 1] = 0x83; scanline[20 + 2] = 0x9F; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xF6; scanline[24 + 1] = 0xD8; scanline[24 + 2] = 0xD1; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xED; scanline[28 + 1] = 0xAC; scanline[28 + 2] = 0xB7; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xE1; scanline[32 + 1] = 0x6D; scanline[32 + 2] = 0x92; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xE4; scanline[36 + 1] = 0x6D; scanline[36 + 2] = 0x92; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xEC; scanline[40 + 1] = 0x77; scanline[40 + 2] = 0x98; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xED; scanline[44 + 1] = 0x78; scanline[44 + 2] = 0x99; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xED; scanline[48 + 1] = 0x78; scanline[48 + 2] = 0x99; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0xDE; scanline[52 + 1] = 0x75; scanline[52 + 2] = 0x99; scanline[52 + 3] = 0xFE;
                scanline[56 + 0] = 0x90; scanline[56 + 1] = 0x5F; scanline[56 + 2] = 0x87; scanline[56 + 3] = 0xDB;
                scanline[60 + 0] = 0x1C; scanline[60 + 1] = 0x16; scanline[60 + 2] = 0x20; scanline[60 + 3] = 0x34;
                scanline[64 + 0] = 0x00; scanline[64 + 1] = 0x00; scanline[64 + 2] = 0x00; scanline[64 + 3] = 0x00;
                scanline[68 + 0] = 0x00; scanline[68 + 1] = 0x00; scanline[68 + 2] = 0x00; scanline[68 + 3] = 0x00;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(19);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x19; scanline[12 + 1] = 0x13; scanline[12 + 2] = 0x1D; scanline[12 + 3] = 0x2F;
                scanline[16 + 0] = 0x78; scanline[16 + 1] = 0x52; scanline[16 + 2] = 0x77; scanline[16 + 3] = 0xC4;
                scanline[20 + 0] = 0xCA; scanline[20 + 1] = 0x68; scanline[20 + 2] = 0x94; scanline[20 + 3] = 0xFF;
                scanline[24 + 0] = 0xE5; scanline[24 + 1] = 0x83; scanline[24 + 2] = 0xA0; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xF4; scanline[28 + 1] = 0xCD; scanline[28 + 2] = 0xCA; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xED; scanline[32 + 1] = 0xAB; scanline[32 + 2] = 0xB7; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xE1; scanline[36 + 1] = 0x6D; scanline[36 + 2] = 0x92; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xE4; scanline[40 + 1] = 0x6C; scanline[40 + 2] = 0x92; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xEB; scanline[44 + 1] = 0x76; scanline[44 + 2] = 0x98; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0xDC; scanline[48 + 1] = 0x76; scanline[48 + 2] = 0x9A; scanline[48 + 3] = 0xFF;
                scanline[52 + 0] = 0x90; scanline[52 + 1] = 0x5F; scanline[52 + 2] = 0x87; scanline[52 + 3] = 0xDB;
                scanline[56 + 0] = 0x26; scanline[56 + 1] = 0x1D; scanline[56 + 2] = 0x2B; scanline[56 + 3] = 0x46;
                scanline[60 + 0] = 0x01; scanline[60 + 1] = 0x01; scanline[60 + 2] = 0x01; scanline[60 + 3] = 0x03;
                scanline[64 + 0] = 0x00; scanline[64 + 1] = 0x00; scanline[64 + 2] = 0x00; scanline[64 + 3] = 0x00;
                scanline[68 + 0] = 0x00; scanline[68 + 1] = 0x00; scanline[68 + 2] = 0x00; scanline[68 + 3] = 0x00;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(20);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x15; scanline[16 + 1] = 0x10; scanline[16 + 2] = 0x18; scanline[16 + 3] = 0x27;
                scanline[20 + 0] = 0x79; scanline[20 + 1] = 0x53; scanline[20 + 2] = 0x79; scanline[20 + 3] = 0xC6;
                scanline[24 + 0] = 0xCC; scanline[24 + 1] = 0x68; scanline[24 + 2] = 0x93; scanline[24 + 3] = 0xFF;
                scanline[28 + 0] = 0xE4; scanline[28 + 1] = 0x7E; scanline[28 + 2] = 0x9C; scanline[28 + 3] = 0xFF;
                scanline[32 + 0] = 0xF4; scanline[32 + 1] = 0xCD; scanline[32 + 2] = 0xCA; scanline[32 + 3] = 0xFF;
                scanline[36 + 0] = 0xED; scanline[36 + 1] = 0xAB; scanline[36 + 2] = 0xB7; scanline[36 + 3] = 0xFF;
                scanline[40 + 0] = 0xE0; scanline[40 + 1] = 0x67; scanline[40 + 2] = 0x8F; scanline[40 + 3] = 0xFF;
                scanline[44 + 0] = 0xD2; scanline[44 + 1] = 0x6C; scanline[44 + 2] = 0x95; scanline[44 + 3] = 0xFF;
                scanline[48 + 0] = 0x91; scanline[48 + 1] = 0x64; scanline[48 + 2] = 0x90; scanline[48 + 3] = 0xEA;
                scanline[52 + 0] = 0x1C; scanline[52 + 1] = 0x16; scanline[52 + 2] = 0x20; scanline[52 + 3] = 0x34;
                scanline[56 + 0] = 0x01; scanline[56 + 1] = 0x01; scanline[56 + 2] = 0x01; scanline[56 + 3] = 0x03;
                scanline[60 + 0] = 0x00; scanline[60 + 1] = 0x00; scanline[60 + 2] = 0x00; scanline[60 + 3] = 0x00;
                scanline[64 + 0] = 0x00; scanline[64 + 1] = 0x00; scanline[64 + 2] = 0x00; scanline[64 + 3] = 0x00;
                scanline[68 + 0] = 0x00; scanline[68 + 1] = 0x00; scanline[68 + 2] = 0x00; scanline[68 + 3] = 0x00;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x00; scanline[76 + 1] = 0x00; scanline[76 + 2] = 0x00; scanline[76 + 3] = 0x00;
                scanline[80 + 0] = 0x00; scanline[80 + 1] = 0x00; scanline[80 + 2] = 0x00; scanline[80 + 3] = 0x00;
                scanline[84 + 0] = 0x00; scanline[84 + 1] = 0x00; scanline[84 + 2] = 0x00; scanline[84 + 3] = 0x00;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                scanline = image.scanLine(21);
                scanline[ 0 + 0] = 0x00; scanline[ 0 + 1] = 0x00; scanline[ 0 + 2] = 0x00; scanline[ 0 + 3] = 0x00;
                scanline[ 4 + 0] = 0x00; scanline[ 4 + 1] = 0x00; scanline[ 4 + 2] = 0x00; scanline[ 4 + 3] = 0x00;
                scanline[ 8 + 0] = 0x00; scanline[ 8 + 1] = 0x00; scanline[ 8 + 2] = 0x00; scanline[ 8 + 3] = 0x00;
                scanline[12 + 0] = 0x00; scanline[12 + 1] = 0x00; scanline[12 + 2] = 0x00; scanline[12 + 3] = 0x00;
                scanline[16 + 0] = 0x00; scanline[16 + 1] = 0x00; scanline[16 + 2] = 0x00; scanline[16 + 3] = 0x00;
                scanline[20 + 0] = 0x18; scanline[20 + 1] = 0x12; scanline[20 + 2] = 0x1C; scanline[20 + 3] = 0x2D;
                scanline[24 + 0] = 0x61; scanline[24 + 1] = 0x4A; scanline[24 + 2] = 0x6E; scanline[24 + 3] = 0xB1;
                scanline[28 + 0] = 0x75; scanline[28 + 1] = 0x5A; scanline[28 + 2] = 0x84; scanline[28 + 3] = 0xD5;
                scanline[32 + 0] = 0x75; scanline[32 + 1] = 0x5A; scanline[32 + 2] = 0x84; scanline[32 + 3] = 0xD5;
                scanline[36 + 0] = 0x75; scanline[36 + 1] = 0x5A; scanline[36 + 2] = 0x84; scanline[36 + 3] = 0xD5;
                scanline[40 + 0] = 0x75; scanline[40 + 1] = 0x5A; scanline[40 + 2] = 0x84; scanline[40 + 3] = 0xD5;
                scanline[44 + 0] = 0x75; scanline[44 + 1] = 0x5A; scanline[44 + 2] = 0x84; scanline[44 + 3] = 0xD5;
                scanline[48 + 0] = 0x75; scanline[48 + 1] = 0x5A; scanline[48 + 2] = 0x84; scanline[48 + 3] = 0xD5;
                scanline[52 + 0] = 0x75; scanline[52 + 1] = 0x5A; scanline[52 + 2] = 0x84; scanline[52 + 3] = 0xD5;
                scanline[56 + 0] = 0x75; scanline[56 + 1] = 0x5A; scanline[56 + 2] = 0x84; scanline[56 + 3] = 0xD5;
                scanline[60 + 0] = 0x75; scanline[60 + 1] = 0x5A; scanline[60 + 2] = 0x84; scanline[60 + 3] = 0xD5;
                scanline[64 + 0] = 0x73; scanline[64 + 1] = 0x58; scanline[64 + 2] = 0x81; scanline[64 + 3] = 0xD0;
                scanline[68 + 0] = 0x33; scanline[68 + 1] = 0x27; scanline[68 + 2] = 0x39; scanline[68 + 3] = 0x5D;
                scanline[72 + 0] = 0x00; scanline[72 + 1] = 0x00; scanline[72 + 2] = 0x00; scanline[72 + 3] = 0x00;
                scanline[76 + 0] = 0x69; scanline[76 + 1] = 0x50; scanline[76 + 2] = 0x77; scanline[76 + 3] = 0xBF;
                scanline[80 + 0] = 0x6E; scanline[80 + 1] = 0x54; scanline[80 + 2] = 0x7C; scanline[80 + 3] = 0xC7;
                scanline[84 + 0] = 0x11; scanline[84 + 1] = 0x0D; scanline[84 + 2] = 0x13; scanline[84 + 3] = 0x1F;
                scanline[88 + 0] = 0x00; scanline[88 + 1] = 0x00; scanline[88 + 2] = 0x00; scanline[88 + 3] = 0x00;
                scanline[92 + 0] = 0x00; scanline[92 + 1] = 0x00; scanline[92 + 2] = 0x00; scanline[92 + 3] = 0x00;
                scanline[96 + 0] = 0x00; scanline[96 + 1] = 0x00; scanline[96 + 2] = 0x00; scanline[96 + 3] = 0x00;

                img_height = 22; img_width = 25;

//              Set the size hints to the given value and call updateGeometry()
                setFixedSize((int) img_width, (int) img_height);
            }
            break;
        }
    }
}
