#ifndef FORMCHARTS_H
#define FORMCHARTS_H

#include <QWidget>

namespace Ui {
class FormCharts;
}

class FormCharts : public QWidget
{
    Q_OBJECT

public:
    explicit FormCharts(QWidget *parent = 0);
    ~FormCharts();

private:
    Ui::FormCharts *ui;
};

#endif // FORMCHARTS_H
