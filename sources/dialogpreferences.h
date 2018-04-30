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
    typedef enum PREF_LANG {
        PREFLANG_ENG,
        PREGLANG_FR,
        PREFLANG_RU
    } lang_e;
    explicit DialogPreferences(QWidget *parent = 0);
    ~DialogPreferences();
private:
    Ui::DialogPreferences *ui;
signals :
    void language (lang_e);
    //void rejected();
private slots :
    void accept ();
    void reject ();
};

#endif // DIALOGPREFERENCES_H
