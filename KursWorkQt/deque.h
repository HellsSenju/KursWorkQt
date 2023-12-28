#ifndef DEQUE_H
#define DEQUE_H

#include <QDebug>

class Deque
{
public:
    Deque(int capacity = 1000);
    ~Deque();

    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    bool contains(int data);
    int getFront();
    int getRear();
    void print();
    void clear();

private:
    int *arr;
    int capacity;   // максимальная емкость очереди
    int count;      // текущий размер очереди
    int front;      // первый элемент очереди
    int rear;       // последний элемент очереди

    bool isFull();
    bool isEmpty();
};

#endif // DEQUE_H
