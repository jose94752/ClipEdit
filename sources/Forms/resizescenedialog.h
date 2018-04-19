#ifndef RESIZESCENEDIALOG_H
#define RESIZESCENEDIALOG_H

#include <QDialog>

namespace Ui {
class ResizeSceneDialog;
}

class ResizeSceneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeSceneDialog(QWidget *parent = 0);
    ~ResizeSceneDialog();

private:
    Ui::ResizeSceneDialog *ui;
};

#endif // RESIZESCENEDIALOG_H
