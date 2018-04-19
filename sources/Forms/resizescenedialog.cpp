#include "resizescenedialog.h"
#include "ui_resizescenedialog.h"
#include <QGraphicsScene>

ResizeSceneDialog::ResizeSceneDialog(QWidget *parent,QGraphicsScene *vscene) :
    QDialog(parent),
    ui(new Ui::ResizeSceneDialog)
{
    ui->setupUi(this);
    scene=vscene;
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(sizeChanged()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}

void ResizeSceneDialog::sizeChanged()
{
    int x=ui->spinBox_x->value();
    int y=ui->spinBox_y->value();
    int width=ui->spinBox_width->value();
    int height=ui->spinBox_height->value();
    scene->setSceneRect(x,y,width,height);
}
