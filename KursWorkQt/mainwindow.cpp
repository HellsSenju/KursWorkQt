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

    QFont fontAxisX;
    fontAxisX.setPixelSize(8);
    QFont fontAxisY;
    fontAxisY.setPixelSize(10);

    QFont fontLabels;
    fontLabels.setPixelSize(9);

    QCategoryAxis *aX = new QCategoryAxis();
    aX->setRange(0, 110000);
    aX->setTitleText("Количество итераций");
    aX->setLabelsAngle(90);
    aX->setLabelsFont(fontAxisX);
    aX->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    aX->append("0", 0);
    aX->append("10000", 10000);
    aX->append("50000", 50000);
    aX->append("100000", 100000);

    QCategoryAxis *aY = new QCategoryAxis();
    aY->setRange(0, 6000);
    aY->setTitleText("Микросекунды (мкс)");
    aY->setLabelsFont(fontAxisY);
    aY->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    aY->append("0", 0);


    QValueAxis  *axisX = new QValueAxis();
    axisX->setRange(0, 110000);
    axisX->setTitleText("Количество итераций");
    axisX->setTickCount(12);
//    axisX->setMinorTickCount(5);
    axisX->setLabelsAngle(90);
    axisX->setLabelsFont(fontAxisX);



    QValueAxis  *axisY = new QValueAxis();
    axisY->setRange(0, 6000);
    axisY->setTitleText("Микросекунды (мкс)");
    axisY->setTickCount(31);
//    axisY->setMinorTickCount();
    axisY->setLabelsFont(fontAxisY);


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
    aY->append(QString::number(time), time);
    series->append(10000, time);
    linkedList.clear();
    //


    // 50000
    timer.restart();
    for(int i = 0; i < 50000; i++){
        linkedList.pushBack(i);
    }

    time = timer.nsecsElapsed() / 1000;
    aY->append(QString::number(time), time);
    series->append(50000, time);
    linkedList.clear();
    //


    // 100000
    timer.restart();
    for(int i = 0; i < 100000; i++){
        linkedList.pushBack(i);
    }

    time = timer.nsecsElapsed() / 1000;
    aY->append(QString::number(time), time);
    series->append(100000, time);
    linkedList.clear();
    //

    QChart *chart = new QChart();
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
    chart->addAxis(aX, Qt::AlignBottom);
    chart->addAxis(aY, Qt::AlignLeft);
    series->attachAxis(aX);
    series->attachAxis(aY);

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
