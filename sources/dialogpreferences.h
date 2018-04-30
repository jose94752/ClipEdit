#ifndef DIALOGPREFERENCES_H
#define DIALOGPREFERENCES_H

#include <QDialog>

namespace Ui {
class DialogPreferences;
}

class DialogPreferences : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPreferences(QWidget *parent = 0, QString lang = "English");
    ~DialogPreferences();
signals :
    void signal_language (QString codelang);
    //void rejected();
private:
    Ui::DialogPreferences *ui;
private slots :
    void accept ();
    void reject ();
};

#endif // DIALOGPREFERENCES_H
