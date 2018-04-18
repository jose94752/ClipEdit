#include "one_menu_button.h"
#include "ui_one_menu_button.h"


One_Menu_Button::One_Menu_Button(QWidget* parent) : QWidget(parent),
                ui(new Ui::One_Menu_Button), state(STATE_NORMAL) {

    ui->setupUi(this);

//  installEventFilter(this);
    ui->button_frame->setMouseTracking(true);
}


One_Menu_Button::~One_Menu_Button() {
    delete ui;
}


void One_Menu_Button::enterEvent(QEvent* /*event*/) {
    if (state == STATE_NORMAL) {
        ui->button_frame->setFrameShape(QFrame::Box);
    }
}


void One_Menu_Button::leaveEvent(QEvent* /*event*/) {
    if (state == STATE_NORMAL) {
        ui->button_frame->setFrameShape(QFrame::NoFrame);
    }
}

void One_Menu_Button::mouseReleaseEvent(QMouseEvent* event) {
    if ((event->button() == Qt::LeftButton) && (state == STATE_NORMAL)) {
        emit on_click(button_id);
    }
}


void One_Menu_Button::select() {
    if (state == STATE_NORMAL) {
        ui->button_frame->setFrameShape(QFrame::Box);
        ui->button_frame->setStyleSheet("background-color:#E8E4D0;");
        ui->button_frame->setCursor(Qt::ArrowCursor);

        state = STATE_SELECTED;
    }
}


void One_Menu_Button::set_pixmap(const QString& new_filename) {
    if (!new_filename.isEmpty()) {
        ui->pixmap_button->setPixmap( QPixmap(new_filename) );
    }
}


void One_Menu_Button::set_text(const QString& new_text) {
    if (!new_text.isEmpty()) {
        ui->text_button->setText(new_text);
    }
}

void One_Menu_Button::unselect(bool init) {
    if ((state == STATE_SELECTED) || init) {
        ui->button_frame->setFrameShape(QFrame::NoFrame);
        ui->button_frame->setStyleSheet("");
        ui->button_frame->setCursor(Qt::PointingHandCursor);

        state = STATE_NORMAL;
    }
}
