#ifndef FORMPICTURE_H
#define FORMPICTURE_H

#include <QWidget>

namespace Ui {
class FormPicture;
}

class FormPicture : public QWidget
{
    Q_OBJECT

public:
    explicit FormPicture(QWidget *parent = 0);
    ~FormPicture();

private:
    Ui::FormPicture *ui;

private slots:
   void recup_image();
};


#endif // FORMPICTURE_H
