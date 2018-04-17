#ifndef FORMSCREENSHOTS_H
#define FORMSCREENSHOTS_H

#include <QWidget>

namespace Ui {
class formscreenshots;
}

class formscreenshots : public QWidget
{
    Q_OBJECT

public:
    explicit formscreenshots(QWidget *parent = 0);
    ~formscreenshots();

private:
    Ui::formscreenshots *ui;
};

#endif // FORMSCREENSHOTS_H
