#include "deque.h"

Deque::Deque(int capacity)
{
    arr = new int[capacity];
    this->capacity = capacity;
    count = 0;
    front = -1;
    rear = -1;
}

Deque::~Deque()
{
    delete[] arr;
}

void Deque::insertFront(int data)
{
    if(isFull()){
        qDebug() << "Очередь заполнена";
        return;
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }

    else if (front == 0)
        front = capacity - 1;
    else
        front--;

    arr[front] = data;
    count++;
}

void Deque::insertRear(int data)
{
    if (isFull()) {
        qDebug() << "Очередь заполнена";
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }

    else if (rear == capacity - 1)
        rear = 0;
    else
        rear++;

    arr[rear] = data;
    count++;
}

void Deque::deleteFront()
{
    if (isEmpty()) {
        qDebug() << "Очередь пуста";
        return;
    }

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == capacity - 1)
        front = 0;

    else
        front++;

    count--;
}

void Deque::deleteRear()
{
    if (isEmpty()) {
        qDebug() << "Очередь пуста";
        return;
    }

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = capacity - 1;
    else
        rear--;

    count--;
}

bool Deque::contains(int data)
{
    if (isEmpty()) {
        qDebug() << "Очередь пуста";
        return false;
    }
    int stop = rear;
    if(stop == capacity)
        stop = 0;

    int temp;
    bool result = false;

    while(front != stop){
        temp = getFront();
        deleteFront();
        insertRear(temp);

        if (temp == data)
            result = true;
    }

    return result;
}

int Deque::getFront()
{
    if(isEmpty()){
        qDebug() << "Очередь пуста";
        return -1;
    }

    return arr[front];
}

int Deque::getRear()
{
    if(isEmpty()){
        qDebug() << "Очередь пуста";
        return -1;
    }

    return arr[rear];
}

void Deque::print()
{
    if (isEmpty()) {
        qDebug() << "Очередь пуста";
        return;
    }
    int stop = rear + 1;
    if(stop == capacity)
        stop = 0;

    int temp;

    while(front != stop){
        temp = getFront();
        qDebug() << temp;
        deleteFront();
        insertRear(temp);
    }
}

void Deque::clear()
{
    count = 0;
    front = -1;
    rear = -1;
}

bool Deque::isFull()
{
    return count == capacity;
}

bool Deque::isEmpty()
{
    return count == 0;
}
