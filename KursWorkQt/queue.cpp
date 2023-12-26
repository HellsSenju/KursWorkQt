#include "queue.h"

Queue::Queue(int _capacity)
{
    arr = new int[_capacity];
    capacity = _capacity;
    count = 0;
    front = 0;
    rear = -1;
}

Queue::~Queue()
{
    delete[] arr;
}
