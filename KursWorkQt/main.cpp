#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QtCharts>
#include <QGraphicsWidget>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
