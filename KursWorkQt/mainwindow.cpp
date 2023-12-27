#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart = new QChart();
    configure();

    //

    LinkedList *linkedList = new LinkedList();
    ArrayList *arrayList = new ArrayList();
//    DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();
//    DequeList *dequeList = new DequeList();


/*
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
    */


    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->setRange(0, 110000);
    axisX->setTitleText("Количество итераций");
    axisX->setLabelsAngle(90);
    axisX->setLabelsFont(fontAxisX);
    axisX->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    axisX->append("0", 0);

    QCategoryAxis *axisY = new QCategoryAxis();
//    axisY->setRange(0, 6000);
    axisY->setTitleText("Микросекунды (мкс)");
    axisY->setLabelsFont(fontAxisY);
    axisY->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    axisY->append("0", 0);

    QLineSeries *series1 = new QLineSeries();
    series1->setPointsVisible(true);
    series1->setPointLabelsVisible(true);
    series1->setPointLabelsFormat("(@xPoint,@yPoint)");
    series1->setPointLabelsFont(fontPointLabels);
    series1->setPointLabelsClipping(false);
    series1->append(0,0);

    QLineSeries *series2 = new QLineSeries();
    series2->setPointsVisible(true);
    series2->setPointLabelsVisible(true);
    series2->setPointLabelsFormat("(@xPoint,@yPoint)");
    series2->setPointLabelsFont(fontPointLabels);
    series2->setPointLabelsClipping(false);
    series2->append(0,0);

    int max1 = test(linkedList, Method::PushBack, axisX, axisY, series1, 100000, 3);
    int max2 = test(arrayList, Method::PushBack, axisX, axisY, series2, 100000, 3);
    qDebug() << max1 << max2;
    delete linkedList;
    delete arrayList;

    axisY->setRange(0, qMax(max1, max2) + 1000);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addSeries(series1);
    chart->addSeries(series2);

    QPen pen(QColor(255,0,255));
    pen.setWidth(2);
    series1->setPen(pen);
    series1->setName("1");
    series1->attachAxis(axisY);

    pen.setColor(QColor(255,0,100));
    pen.setWidth(2);
    series2->setPen(pen);
    series2->setName("2");
    series2->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);


    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete chart;
}

void MainWindow::configure()
{
    fontChartTitle.setPixelSize(18);

    // config title
    chart->setTitleFont(fontChartTitle);
    chart->setTitleBrush(Qt::black);
    chart->setTitle("test chart");

    // config legend
    chart->legend()->setAlignment(Qt::AlignBottom);

    // config fonts
    fontAxisX.setPixelSize(10);
    fontAxisY.setPixelSize(10);
    fontPointLabels.setPixelSize(9);
}

template<typename T>
int MainWindow::test(T* list, Method method, QCategoryAxis *axisX, QCategoryAxis *axisY, QLineSeries *series, int maxIter, int colIter)
{
    QElapsedTimer timer;
    int max = 0;
    int offset = round(maxIter / colIter);
    qDebug() << "offset" << offset;
    int temp = offset;
    int time = 0;

    switch (method)
    {
    case Method::PushBack:

        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->pushBack(i);

            time = timer.nsecsElapsed() / 1000;
            axisY->append(QString::number(time), time);
            axisX->append(QString::number(temp), temp);
            qDebug() << temp << time;

            series->append(temp, time);
            list->clear();

            if(time > max)
                max = time;

            temp += offset;
        }
        //
        break;

    case Method::PushFront:
        break;

    case Method::RemoveFirst:
        break;

    case Method::RemoveLast:
        break;

    case Method::Contains:
        break;
    }
     return max;
}
