#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    LinkedList list;
    ArrayList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    list.print();

    list.pushFront(0);
    list.pushFront(-1);
    list.pushFront(-2);
    list.pushFront(-3);
    list.pushFront(-4);
    list.print();

    list.removeFirst();
    list.removeFirst();
    list.removeFirst();
    list.print();

    list.removeLast();
    list.removeLast();
    list.removeLast();
    list.print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

