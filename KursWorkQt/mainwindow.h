#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "linkedlist.h"
#include "arraylist.h"
#include "doublelinkedlist.h"
#include "dequelist.h"
#include "form.h"
#include "ilist.h"

#include <QMainWindow>
#include <QElapsedTimer>
#include <QtCharts>
#include <QRgb>
#include <QPainter>
#include <QLineSeries>
#include <QObject>
#include <QtGlobal>
#include <QLinkedList>
#include <QList>
#include <QRandomGenerator>
#include <QLineEdit>
#include <QComboBox>
#include <QValidator>
#include <cmath>


enum class Method {PushBack, PushFront, DeleteFirst, DeleteLast, Contains};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_qt_mine_clicked();

    void on_comboBox_maxIter_currentTextChanged(const QString &arg1);

    void on_comboBox_colIter_currentTextChanged(const QString &arg1);

    void on_comboBox_ci_currentTextChanged(const QString &arg1);

    void on_pushButton_create_clicked();

    void on_comboBox_select_currentTextChanged(const QString &arg1);

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_contains_clicked();

    void on_pushButton_del_list_clicked();

private:
    Ui::MainWindow *ui;
    QChart *chart;

    QFont fontChartTitle;
    QFont fontAxis;
    QFont fontPointLabels;
    int maxIter;
    int colIter;
    int del;

    QMap<QString, Method> methods{
        {"pushBack", Method::PushBack},
        {"pushFront", Method::PushFront},
        {"deleteFirst", Method::DeleteFirst},
        {"deleteLast", Method::DeleteLast},
        {"contains", Method::Contains}
    };

    QMap<QString, int> qt{
        {"QLinkedList", 0},
        {"QList", 1}
    };

    QMap<QString, int> mine{
        {"LinkedList", 0},
        {"ArrayList", 1},
        {"DoubleLinkedList", 2},
        {"DequeList", 3}
    };

    QMap<QString, int> ci{
        {"миллисекунда", 1000000},
        {"микросекунда", 1000},
        {"наносекунды", 1},
    };

    QMap<QString, LinkedList*> lists;

    void configure();
    void configureSeries();

    void test(IList* list, QValueAxis *axisX, QValueAxis *axisY, QLineSeries *series);

    template<typename T>
    void testQt(T* list, QValueAxis *axisX, QValueAxis *axisY, QLineSeries *series);

    void setChartProps(QChart *chart, QString name);
    void setSeriesProps(QLineSeries *series, QString name, QColor color, bool labelsVisible);
    void setAxisProps(QValueAxis *axis, QString name, int interval, int minorTickCount);
};
#endif // MAINWINDOW_H
