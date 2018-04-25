#ifndef RESIZESCENEDIALOG_H
#define RESIZESCENEDIALOG_H
#include <QGraphicsScene>

#include <QDialog>
#include <QRectF>
#include <QGraphicsItem>

namespace Ui {
class ResizeSceneDialog;
}

class ResizeSceneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeSceneDialog(QWidget *parent,QGraphicsScene*,int*,int*,QGraphicsRectItem**);//(parent,precedent width,precedent height)
    ~ResizeSceneDialog();

public slots:
    void sizeChanged();
    void unityChanged(QString);

private:
    Ui::ResizeSceneDialog *ui;
    QGraphicsScene *scene;
    int *m_width;
    int *m_height;
    int dpix;
    int dpiy;
    QGraphicsRectItem **m_borderSceneItem;
};

#endif // RESIZESCENEDIALOG_H
