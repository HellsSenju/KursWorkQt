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

    template<class T>
    void test();
};
#endif // MAINWINDOW_H
