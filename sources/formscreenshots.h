#ifndef FORMSCREENSHOTS_H
#define FORMSCREENSHOTS_H

#include <QWidget>

namespace Ui {
class FormScreenShots;
}

class FormScreenShots : public QWidget
{
    Q_OBJECT

public:
    explicit FormScreenShots(QWidget *parent = 0);
    ~FormScreenShots();

private:
    Ui::FormScreenShots *ui;
};

#endif // FORMSCREENSHOTS_H
