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

    LinkedList linkedList;
    ArrayList arrayList;
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

    test(&linkedList, Method::PushBack, axisX, axisY, series1, 100000, 3);
    test(&arrayList, Method::PushBack, axisX, axisY, series2, 100000, 3);

//    axisY->setRange(0, qMax(max1, max2) + 1000);
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
void MainWindow::test(T* list, Method method, QCategoryAxis *axisX, QCategoryAxis *axisY, QLineSeries *series,
                     int maxIter, int colIter)
{
    QElapsedTimer timer;
    int maxX = 0, maxY = 0;
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
            axisX->append(QString::number(temp), temp);
            axisY->append(QString::number(time), time);
            series->append(temp, time);

            qDebug() << temp << time;

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }

        break;

    case Method::PushFront:
        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->pushFront(i);

            time = timer.nsecsElapsed() / 1000;
            axisX->append(QString::number(temp), temp);
            axisY->append(QString::number(time), time);
            series->append(temp, time);

            qDebug() << temp << time;

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    case Method::RemoveFirst:
        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->removeFirst();

            time = timer.nsecsElapsed() / 1000;
            axisX->append(QString::number(temp), temp);
            axisY->append(QString::number(time), time);
            series->append(temp, time);

            qDebug() << temp << time;

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    case Method::RemoveLast:
        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->removeLast();

            time = timer.nsecsElapsed() / 1000;
            axisX->append(QString::number(temp), temp);
            axisY->append(QString::number(time), time);
            series->append(temp, time);

            qDebug() << temp << time;

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    case Method::Contains:
        while(temp <= maxIter){

            for(int i = 0; i < temp; i++)
                list->pushFront(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->contains(i);

            time = timer.nsecsElapsed() / 1000;
            axisX->append(QString::number(temp), temp);
            axisY->append(QString::number(time), time);
            series->append(temp, time);

            qDebug() << temp << time;

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;
    }

    axisX->setRange(0, maxX + 1000);
    axisY->setRange(0, maxY + 1000);

}

void MainWindow::on_pushButton_clicked()
{
    LinkedList linkedList;
    ArrayList arrayList;
    DoubleLinkedList doubleLinkedList;
    DequeList dequeList;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->clear();

    LinkedList linkedList;
    DoubleLinkedList doubleLinkedList;
    QElapsedTimer timer;



    QChart *chart = new QChart();
    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();

//    fontChartTitle.setPixelSize(18);

    // config title
    chart->setTitleFont(fontChartTitle);
//    chart->setTitleBrush(Qt::black);
    chart->setTitle("");

    // config legend
    chart->legend()->setAlignment(Qt::AlignBottom);

    // config fonts
    fontAxisX.setPixelSize(10);
    fontAxisY.setPixelSize(10);
    fontPointLabels.setPixelSize(9);

//    axisX->setRange(0, 110000);
    axisX->setTitleText("Количество итераций");
    axisX->setLabelsAngle(90);
    axisX->setLabelsFont(fontAxisX);
    axisX->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    axisX->append("0", 0);


//    axisY->setRange(0, 6000);
    axisY->setTitleText("Микросекунды (мкс)");
    axisY->setLabelsFont(fontAxisY);
    axisY->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    axisY->append("0", 0);


    series1->setPointsVisible(true);
    series1->setPointLabelsVisible(true);
    series1->setPointLabelsFormat("(@xPoint,@yPoint)");
    series1->setPointLabelsFont(fontPointLabels);
    series1->setPointLabelsClipping(false);
    series1->append(0,0);

    int maxIter = 100000;
    int colIter = 4;
    int offset = round(maxIter / colIter);
    int temp = offset;
    int time = 0;
    int maxX, maxY = 0;

    while(temp <= maxIter){
        timer.restart();

        for(int i = 0; i < temp; i++)
            linkedList.pushBack(i);

        time = timer.nsecsElapsed() / 1000;
        axisX->append(QString::number(temp), temp);
        axisY->append(QString::number(time), time);
        qDebug() << temp << time;

        series1->append(temp, time);
        linkedList.clear();

        if(temp > maxX)
            maxX = temp;

        if(time > maxY)
            maxY = time;

        temp += offset;
    }


    series2->setPointsVisible(true);
    series2->setPointLabelsVisible(true);
    series2->setPointLabelsFormat("(@xPoint,@yPoint)");
    series2->setPointLabelsFont(fontPointLabels);
    series2->setPointLabelsClipping(false);
    series2->append(0,0);

    temp = offset;
    time = 0;
    while(temp <= maxIter){
        timer.restart();

        for(int i = 0; i < temp; i++)
            doubleLinkedList.pushBack(i);

        time = timer.nsecsElapsed() / 1000;
        axisX->append(QString::number(temp), temp);
        axisY->append(QString::number(time), time);
        qDebug() << temp << time;

        series2->append(temp, time);
        doubleLinkedList.clear();

        if(temp > maxX)
            maxX = temp;

        if(time > maxY)
            maxY = time;

        temp += offset;
    }


    axisX->setRange(0, maxX + 1000);
    axisY->setRange(0, maxY + 1000);

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

    Form *form = new Form();
    form->getChartView()->setChart(chart);
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}

