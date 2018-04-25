#include "resizescenedialog.h"
#include "ui_resizescenedialog.h"
#include <QGraphicsScene>
#include <QStringList>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

ResizeSceneDialog::ResizeSceneDialog(QWidget *parent,QGraphicsScene *vscene,int *v_width,int *v_height) :
    QDialog(parent),
    ui(new Ui::ResizeSceneDialog)
{
    ui->setupUi(this);
    scene=vscene;
    //Pixels by dpi
    QDesktopWidget *app_widget=QApplication::desktop();
    dpix=app_widget->logicalDpiX();
    dpiy=app_widget->logicalDpiY();
    if(dpix==0){
        dpix=25;
    }
    if(dpiy==0){
        dpiy=25;
    }
    //unities list
    QStringList unities={"mm","cm","inch","px"};
    //connects
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(sizeChanged()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->comboBox_unity,SIGNAL(currentTextChanged(QString)),this,SLOT(unityChanged(QString)));
    //initialize values
    ui->comboBox_unity->addItems(unities);
    //store width and height
    m_width=v_width;
    m_height=v_height;
    unityChanged("mm");
}

ResizeSceneDialog::~ResizeSceneDialog()
{
    delete ui;
}

void ResizeSceneDialog::sizeChanged()
{
    int width=0;
    int height=0;
    QString name=ui->comboBox_unity->currentText();
    if(name=="mm"){
        width=ui->doubleSpinBox_width->value()*dpix/25.4;
        height=ui->doubleSpinBox_height->value()*dpiy/25.4;
    }
    if(name=="cm"){
        width=ui->doubleSpinBox_width->value()*dpix/2.54;
        height=ui->doubleSpinBox_height->value()*dpiy/2.54;
    }
    if(name=="inch"){
        width=ui->doubleSpinBox_width->value()*dpix;
        height=ui->doubleSpinBox_height->value()*dpiy;
    }
    if(name=="px"){
        width=ui->doubleSpinBox_width->value();
        height=ui->doubleSpinBox_height->value();
    }
    int x=-width/2;
    int y=-height/2;
    scene->setSceneRect(x,y,width,height);
    *m_width=width;
    *m_height=height;
}

void ResizeSceneDialog::unityChanged(QString name)
{
    int width=*m_width;
    int height=*m_height;
    if(name=="mm"){
        ui->doubleSpinBox_width->setValue(width * 25.4/dpix);
        ui->doubleSpinBox_height->setValue(height * 25.4/dpiy);
        ui->doubleSpinBox_width->setDecimals(0);
        ui->doubleSpinBox_height->setDecimals(0);
    }
    if(name=="cm"){
        ui->doubleSpinBox_width->setValue(width * 2.54/dpix);
        ui->doubleSpinBox_height->setValue(height * 2.54/dpiy);
        ui->doubleSpinBox_width->setDecimals(1);
        ui->doubleSpinBox_height->setDecimals(1);
    }
    if(name=="inch"){
        ui->doubleSpinBox_width->setValue(width/dpix);
        ui->doubleSpinBox_height->setValue(height/dpiy);
        ui->doubleSpinBox_width->setDecimals(1);
        ui->doubleSpinBox_height->setDecimals(1);
    }
    if(name=="px"){
        ui->doubleSpinBox_width->setValue(width);
        ui->doubleSpinBox_height->setValue(height);
        ui->doubleSpinBox_width->setDecimals(0);
        ui->doubleSpinBox_height->setDecimals(0);
    }
}
