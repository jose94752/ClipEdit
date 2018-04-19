#ifndef RESIZESCENEDIALOG_H
#define RESIZESCENEDIALOG_H
#include <QGraphicsScene>

#include <QDialog>

namespace Ui {
class ResizeSceneDialog;
}

class ResizeSceneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeSceneDialog(QWidget *parent,QGraphicsScene*);
    ~ResizeSceneDialog();

public slots:
    void sizeChanged();

private:
    Ui::ResizeSceneDialog *ui;
    QGraphicsScene *scene;
};

#endif // RESIZESCENEDIALOG_H
