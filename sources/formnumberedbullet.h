#ifndef FORMNUMBEREDBULLET_H
#define FORMNUMBEREDBULLET_H
#include "commongraphicitem.h"

#include <QWidget>

namespace Ui {
class FormNumberedBullet;
}

class FormNumberedBullet : public QWidget, public CommonGraphicItem
{
    Q_OBJECT

public:
    explicit FormNumberedBullet(QWidget *parent = 0);
    ~FormNumberedBullet();

private:
    Ui::FormNumberedBullet *ui;
};

#endif // FORMNUMBEREDBULLET_H
