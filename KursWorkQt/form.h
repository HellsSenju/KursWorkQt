#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QtCharts>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    QChartView* getChartView();

private:
    Ui::Form *ui;
};

#endif // FORM_H
