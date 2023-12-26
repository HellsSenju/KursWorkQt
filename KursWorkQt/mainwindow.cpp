#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QElapsedTimer timer;

    LinkedList linkedList;
    ArrayList arrayList;
    DoubleLinkedList doubleLinkedList;
    DequeList dequeList;

    QFont fontLabels;
    fontLabels.setPixelSize(8);

    QValueAxis  *axisX = new QValueAxis();
    axisX->setRange(0, 110000);
    axisX->setTitleText("x");
    axisX->setTickCount(12);
    axisX->setLabelsAngle(90);
    axisX->setLabelsFont(fontLabels);
    axisX->setMinorGridLineVisible(true);

    QValueAxis  *axisY = new QValueAxis();
    axisY->setRange(0, 6000);
    axisY->setTitleText("y");


    QLineSeries *series = new QLineSeries();
    series->setPointsVisible(true);
    series->setPointLabelsVisible(true);
    series->setPointLabelsFormat("(@xPoint,@yPoint)");

    series->setPointLabelsFont(fontLabels);
    series->setPointLabelsClipping(false);
    series->append(0,0);
    series->setName("LinkedList");

    // 10000
    timer.start();
    for(int i = 0; i < 10000; i++){
        linkedList.pushBack(i);
    }

    int time = timer.nsecsElapsed() / 1000;
    series->append(10000, time);
    linkedList.clear();

    // 50000
    timer.restart();
    for(int i = 0; i < 50000; i++){
        linkedList.pushBack(i);
    }

    time = timer.nsecsElapsed() / 1000;
    series->append(50000, time);
    linkedList.clear();

    // 100000
    timer.restart();
    for(int i = 0; i < 100000; i++){
        linkedList.pushBack(i);
    }

    time = timer.nsecsElapsed() / 1000;
    series->append(100000, time);
    linkedList.clear();

    QChart *chart = new QChart();
//    chart->legend()->paint();
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QFont font;
    font.setPixelSize(18);

    chart->setTitleFont(font);
    chart->setTitleBrush(Qt::black);
    chart->setTitle("test chart");

    QPen pen(QColor(255,0,255));
    pen.setWidth(2);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);
//    chart->createDefaultAxes();
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

//    QCategoryAxis *axisX = new QCategoryAxis();
//    axisX->setTitleText("Количество элементов");
//    axisX->setTickCount(4);
//    axisX->append("q 1000", 1000);
//    axisX->append("q 10000", 10000);
//    axisX->append("q 50000", 50000);
//    axisX->append("q 100000", 100000);
//    axisX->setRange(0, 10000);


//    chart->setAxisX(axisX, series);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    chart->addAxis(axisY, Qt::AlignLeft);

//    chart->axes(Qt::);


//    series->attachAxis(axisX);
//    series->attachAxis(axisY);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);


}

MainWindow::~MainWindow()
{
    delete ui;
}

template<class T>
void MainWindow::test()
{

}
