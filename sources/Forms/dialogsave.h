#ifndef DIALOGSAVE_H
#define DIALOGSAVE_H

#include <QDialog>
#include <QGraphicsItem>

namespace Ui {
class DialogSave;
}

class DialogSave : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSave(QWidget *parent,QList<QGraphicsItem *>);
    ~DialogSave();
private slots:
    void slotSaveApproved();

private:
    Ui::DialogSave *ui;
    QList<QGraphicsItem*> m_items;
};

#endif // DIALOGSAVE_H
