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
    ui->spinBox_width->setValue(800);
    ui->spinBox_height->setValue(800);
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}

void ResizeSceneDialog::sizeChanged()
{
    int width=ui->spinBox_width->value();
    int height=ui->spinBox_height->value();
    int x=-width/2;
    int y=-height/2;
    scene->setSceneRect(x,y,width,height);
}
