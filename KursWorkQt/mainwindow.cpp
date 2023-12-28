#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chart = new QChart();
    configure();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chart;
}

void MainWindow::configure()
{
    maxIter = 100;
    colIter = 4;
    del = 1;
    fontChartTitle.setPixelSize(18);

    // config title
    chart->setTitleFont(fontChartTitle);
    chart->setTitleBrush(Qt::black);
    chart->setTitle("test chart");

    // config legend
    chart->legend()->setAlignment(Qt::AlignBottom);

    // config fonts
    fontAxis.setPixelSize(10);
    fontPointLabels.setPixelSize(8);
}


void MainWindow::setChartProps(QChart *chart, QString name)
{
    chart->setTitleFont(fontChartTitle);
    chart->setTitle(name);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(fontAxis);
    chart->setAnimationOptions(QChart::AllAnimations);
}


void MainWindow::setSeriesProps(QLineSeries *series, QString name, QColor color, bool labelsVisible)
{
    series->setPointsVisible(true);
    series->setPointLabelsVisible(labelsVisible);
    series->setPointLabelsFormat("(@xPoint,@yPoint)");
    series->setPointLabelsFont(fontPointLabels);
    series->setPointLabelsClipping(false);
    QPen pen(color);
    pen.setWidth(2);
    series->setPen(pen);
    series->setName(name);
    series->append(0,0);
}


void MainWindow::setAxisProps(QValueAxis *axis, QString name, int interval, int minorTickCount)
{
    axis->setLabelsFont(fontAxis);
    axis->setTickType(QValueAxis::TicksDynamic);
    axis->setTickAnchor(0);
    axis->setTitleText(name);
    axis->setTickInterval(interval);
    axis->setMinorTickCount(minorTickCount);
}


template<typename T>
void MainWindow::test(T* list, QValueAxis *axisX, QValueAxis *axisY, QLineSeries *series)
{
    QElapsedTimer timer;
    int maxX = 0, maxY = axisY->max();
    int offset = maxIter / colIter;
    int temp = offset;
    int time = 0;

    switch (methods[ui->comboBox->currentText()])
    {
    case Method::PushBack:

        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->pushBack(i);

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

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

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    case Method::DeleteFirst:
        while(temp <= maxIter){
            for(int i = 0; i < temp; i++)
                list->pushBack(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->removeFirst();

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    case Method::DeleteLast:
        while(temp <= maxIter){
            for(int i = 0; i < temp; i++)
                list->pushBack(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->removeLast();

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

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

            time = timer.elapsed();
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;
    }

    axisX->setRange(0, maxX);
    axisY->setRange(0, maxY);
}


template<typename T>
void MainWindow::testQt(T *list, QValueAxis *axisX, QValueAxis *axisY, QLineSeries *series)
{
    QElapsedTimer timer;
    int maxX = 0, maxY = axisY->max();
    int offset = maxIter / colIter;
    int temp = offset;
    int time = 0;
    switch (methods[ui->comboBox->currentText()]) {
    case Method::PushBack:
        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->push_back(i);

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;
    case Method::PushFront :
        while(temp <= maxIter){
            timer.restart();

            for(int i = 0; i < temp; i++)
                list->push_front(i);

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;
    case Method::DeleteFirst:
        while(temp <= maxIter){
            for(int i = 0; i < temp; i++)
                list->push_back(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->pop_front();

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;
    case Method::DeleteLast:
        while(temp <= maxIter){
            for(int i = 0; i < temp; i++)
                list->push_back(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->pop_back();

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

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
                list->push_back(i);

            timer.restart();

            for(int i = 0; i < temp; i++)
                list->contains(i);

            time = timer.nsecsElapsed() / del;
            series->append(temp, time);

            list->clear();

            if(temp > maxX)
                maxX = temp;

            if(time > maxY)
                maxY = time;

            temp += offset;
        }
        break;

    }

    axisX->setRange(0, maxX);
    axisY->setRange(0, maxY);
}


void MainWindow::on_pushButton_clicked()
{
    LinkedList linkedList;
    ArrayList arrayList;
    DoubleLinkedList doubleLinkedList;
    DequeList dequeList(maxIter);

    QChart *chart = new QChart();
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();
    QLineSeries *series4 = new QLineSeries();

    setChartProps(chart, "Вставка в конец");
    setSeriesProps(series1, "LinkedList", QColor(255,0,255),false);
    setSeriesProps(series2, "ArrayList", QColor(0,100,100),false);
    setSeriesProps(series3, "DoubleLinkedList", QColor(0,0,255),false);
    setSeriesProps(series4, "DequeList", QColor(255,100,0),false);

    test(&arrayList,axisX,axisY, series2);
    test(&doubleLinkedList, axisX,axisY, series3);
    test(&dequeList, axisX,axisY, series4);
    test(&linkedList, axisX,axisY, series1);


    axisX->setRange(0, axisX->max() + axisX->max()*0.1);
    setAxisProps(axisX, "Количество итераций", maxIter / colIter, 0);

    axisY->setRange(0, axisY->max() + axisY->max()*0.1);
    setAxisProps(axisY, ui->comboBox_ci->currentText(), axisY->max() / 20, 1);

    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->addSeries(series4);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series1->attachAxis(axisX);
    series1->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);
    series3->attachAxis(axisX);
    series3->attachAxis(axisY);
    series4->attachAxis(axisX);
    series4->attachAxis(axisY);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}


void MainWindow::on_pushButton_2_clicked()
{
    LinkedList linkedList;
    DoubleLinkedList doubleLinkedList;

    QChart *chart = new QChart();
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();

    setChartProps(chart, "Вставка в конец");
    setSeriesProps(series1, "LinkedList", QColor(255,0,255),true);
    setSeriesProps(series2, "DoubleLinkedList", QColor(255,0,100),true);

    test(&linkedList, axisX,axisY, series1);
    test(&doubleLinkedList, axisX,axisY, series2);

    axisX->setRange(0, axisX->max() + axisX->max()*0.1);
    setAxisProps(axisX, "Количество итераций", maxIter / colIter, 0);

    axisY->setRange(0, axisY->max() + axisY->max()*0.05);
    setAxisProps(axisY, ui->comboBox_ci->currentText(), (axisY->max() / 20), 1);

    chart->addSeries(series1);
    chart->addSeries(series2);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series1->attachAxis(axisX);
    series1->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}


void MainWindow::on_pushButton_qt_mine_clicked()
{
    try {
        LinkedList linkedList;
        ArrayList arrayList;
        DoubleLinkedList doubleLinkedList;
        DequeList dequeList(maxIter);

        QLinkedList<int> QLinkedList;
        QList<int> QList;

        QChart *chart = new QChart();
        QValueAxis *axisX = new QValueAxis();
        QValueAxis *axisY = new QValueAxis();
        QLineSeries *series1 = new QLineSeries();
        QLineSeries *series2 = new QLineSeries();

        QString chartName = "";

        switch (qt[ui->comboBox_qt->currentText()]) {
        case 0:
            chartName += "Сравнение QLinkedList";
            setSeriesProps(series2, "QLinkedList", QColor(255,0,100),false);
            testQt(&QLinkedList,axisX,axisY, series2);
            break;
        case 1:
            chartName += "Сравнение QList";
            setSeriesProps(series2, "QList", QColor(255,0,100),false);
            testQt(&QList, axisX,axisY, series2);
            break;
        }

        switch (mine[ui->comboBox_mine->currentText()]) {
        case 0:
            chartName += " c моим LinkedList";
            setSeriesProps(series1, "LinkedList", QColor(255,0,255),false);
            test(&linkedList,axisX,axisY, series1);
            break;
        case 1:
            chartName += " c моим ArrayList";
            setSeriesProps(series1, "ArrayList", QColor(255,0,255),false);
            test(&arrayList,axisX,axisY, series1);
            break;
        case 2:
            chartName += " c моим DoubleLinkedList";
            setSeriesProps(series1, "DoubleLinkedList", QColor(255,0,255),false);
            test(&doubleLinkedList, axisX,axisY, series1);
            break;
        case 3:
            chartName += " c моим DequeList";
            setSeriesProps(series1, "DequeList", QColor(255,0,255),false);
            test(&dequeList, axisX,axisY, series1);
            break;
        }

        setChartProps(chart, chartName);

        axisX->setRange(0, axisX->max() + axisX->max()*0.1);
        setAxisProps(axisX, "Количество итераций", maxIter / colIter, 0);

        axisY->setRange(0, axisY->max() + axisY->max()*0.1);
        setAxisProps(axisY, ui->comboBox_ci->currentText(), (axisY->max() / 20), 1);


        chart->addSeries(series1);
        chart->addSeries(series2);

        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);

        series1->attachAxis(axisX);
        series1->attachAxis(axisY);
        series2->attachAxis(axisX);
        series2->attachAxis(axisY);

        ui->chartView->setChart(chart);
        ui->chartView->setRenderHint(QPainter::Antialiasing);
    }  catch (...) {
        return;
    }
}


void MainWindow::on_comboBox_maxIter_currentTextChanged(const QString &arg1)
{
    maxIter = arg1.toInt();
}


void MainWindow::on_comboBox_colIter_currentTextChanged(const QString &arg1)
{
    colIter = arg1.toInt();
}


void MainWindow::on_comboBox_ci_currentTextChanged(const QString &arg1)
{
    del = ci[arg1];
}


void MainWindow::on_pushButton_create_clicked()
{
    ui->listWidget->clear();
    QString name = ui->lineEdit_list_name->text();
    LinkedList *list = new LinkedList();

    if(lists.contains(name) || name.isEmpty()){
        delete list;
        list = nullptr;
        return;
    }

    if(ui->checkBox){
        int kol = ui->spinBox->value();
        for(int i = 0; i < kol; i++){
            int el = QRandomGenerator::global()->generate();
            list->pushBack(el);
            ui->listWidget->addItem(QString::number(el));
        }
    }

    lists.insert(name, list);
    ui->comboBox_select->addItem(name);

    ui->lineEdit_list_name->clear();
    ui->checkBox->setChecked(false);
    ui->spinBox->setValue(20);
}


void MainWindow::on_comboBox_select_currentTextChanged(const QString &arg1)
{
    ui->listWidget->clear();
    QList<QString> *list = lists[arg1]->toQList();

    for( int i = 0; i < list->count(); i++)
        ui->listWidget->addItem(list->value(i));
}


void MainWindow::on_pushButton_add_clicked()
{
    int el = ui->lineEdit_add->text().toInt();
    QString list = ui->comboBox_select->currentText();
    if(ui->radioButton_add_first->isChecked())
        lists[list]->pushFront(el);

    else if(ui->radioButton_add_last->isChecked())
        lists[list]->pushBack(el);

    ui->lineEdit_add->clear();
    on_comboBox_select_currentTextChanged(list);
}


void MainWindow::on_pushButton_del_clicked()
{
    QString list = ui->comboBox_select->currentText();
    if(ui->radioButton_del_first->isChecked())
        lists[list]->removeFirst();

    else if(ui->radioButton_del_last->isChecked())
        lists[list]->removeLast();

    on_comboBox_select_currentTextChanged(list);
}


void MainWindow::on_pushButton_contains_clicked()
{
    int el = ui->lineEdit_contains->text().toInt();
    if(lists[ui->comboBox_select->currentText()]->contains(el))
        ui->label_contains->setText("Элемент найден");
    else
        ui->label_contains->setText("Элемент не найден");

    ui->lineEdit_contains->clear();
}


void MainWindow::on_pushButton_del_list_clicked()
{
    ui->listWidget->clear();
    lists.remove(ui->comboBox_select->currentText());
    ui->comboBox_select->removeItem(ui->comboBox_select->currentIndex());
}

