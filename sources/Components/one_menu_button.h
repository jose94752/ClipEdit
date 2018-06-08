#ifndef ONE_MENU_BUTTON_H
#define ONE_MENU_BUTTON_H

#include <QEvent>
#include <QMouseEvent>
#include <QWidget>


// Forward Declaration
namespace Ui {
  class One_Menu_Button;
}


class One_Menu_Button : public QWidget {
    Q_OBJECT


// Constructor & Destructor
public:

    explicit One_Menu_Button(QWidget* parent = 0);

    ~One_Menu_Button();


// States
private :

    typedef enum e_STATES {
        STATE_SELECTED = 0,
        STATE_NORMAL
    } t_State;

    t_State state;


// Interface
public:

    void select();

    void set_pixmap(const QString&);

    void set_text(const QString&);

    void unselect(bool /*init*/ = false);


// Events
protected:

    void enterEvent(QEvent*);

    void leaveEvent(QEvent*);

    void mouseReleaseEvent(QMouseEvent*);


signals:

    void on_click(unsigned char);


// Data Members
private:

    Ui::One_Menu_Button* ui;

public:

    unsigned char button_id;
};


#endif // ONE_MENU_BUTTON_H
