#ifndef DIALOGSCREENSHOTS_H
#define DIALOGSCREENSHOTS_H

#include <QDialog>

namespace Ui {
class DialogScreenShots;
}

class DialogScreenShots : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScreenShots(QWidget *parent = 0);
    ~DialogScreenShots();

private:
    Ui::DialogScreenShots *ui;
};

#endif // DIALOGSCREENSHOTS_H
