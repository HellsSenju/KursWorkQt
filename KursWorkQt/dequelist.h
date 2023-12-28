#ifndef DEQUELIST_H
#define DEQUELIST_H

#include "deque.h"

class DequeList
{
public:
    DequeList();
    DequeList(int dequeSize);
    ~DequeList();

    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    bool contains(int d);
    void print();
    void clear();

private:
    Deque *deque;
};

#endif // DEQUELIST_H
