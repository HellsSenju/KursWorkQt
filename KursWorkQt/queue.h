#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
public:
    Queue(int _capacity);
    ~Queue();

private:
    int *arr;
    int capacity;   // максимальная емкость очереди
    int count;      // текущий размер очереди
    int front;      // первый элемент очереди
    int rear;       // последний элемент очереди
};

#endif // QUEUE_H
