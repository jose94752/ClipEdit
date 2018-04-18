#ifndef DIALOGFILEALREADYEXISTS_H
#define DIALOGFILEALREADYEXISTS_H

#include <QDialog>

namespace Ui {
class DialogFileAlreadyExists;
}

class DialogFileAlreadyExists : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFileAlreadyExists(QWidget *parent = 0);
    ~DialogFileAlreadyExists();

private:
    Ui::DialogFileAlreadyExists *ui;
};

#endif // DIALOGFILEALREADYEXISTS_H
