#include "resizescenedialog.h"
#include "ui_resizescenedialog.h"

ResizeSceneDialog::ResizeSceneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResizeSceneDialog)
{
    ui->setupUi(this);
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}
