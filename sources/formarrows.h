#ifndef FORMARROWS_H
#define FORMARROWS_H

#include <QWidget>

namespace Ui {
class FormArrows;
}

class FormArrows : public QWidget
{
    Q_OBJECT

public:
    explicit FormArrows(QWidget *parent = 0);
    ~FormArrows();

private:
    Ui::FormArrows *ui;
};

#endif // FORMARROWS_H
