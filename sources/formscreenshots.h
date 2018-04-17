#ifndef FORMSCREENSHOTS_H
#define FORMSCREENSHOTS_H

#include <QWidget>

namespace Ui {
class Formscreenshots;
}

class Formscreenshots : public QWidget
{
    Q_OBJECT

public:
    explicit Formscreenshots(QWidget *parent = 0);
    ~Formscreenshots();

private:
    Ui::Formscreenshots *ui;
};

#endif // FORMSCREENSHOTS_H
