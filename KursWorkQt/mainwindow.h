#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "linkedlist.h"
#include "arraylist.h"
#include "doublelinkedlist.h"
#include "dequelist.h"

#include <QMainWindow>
#include <QElapsedTimer>
#include <QtCharts>
#include <QRgb>
#include <QPainter>
#include <QLineSeries>
#include <QObject>
#include <QtGlobal>
#include <cmath>


enum class Method {PushBack, PushFront, RemoveFirst, RemoveLast, Contains};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QChart *chart;

    QFont fontChartTitle;
    QFont fontAxisX;
    QFont fontAxisY;
    QFont fontPointLabels;

    void configure();
    void configureSeries();
    template<typename T>
    int test(T* list, Method method, QCategoryAxis *axisX, QCategoryAxis *axisY,
             QLineSeries *series, int maxIter, int colIter);
};
#endif // MAINWINDOW_H
