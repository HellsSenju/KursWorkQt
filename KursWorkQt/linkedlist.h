#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QDebug>
#include "Node.h"

class LinkedList
{
public:
    LinkedList();
//    ~LinkedList();
    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    Node* contains(int d);
    void print();
    void clear();

private:
    Node *first;
    Node *last;

    bool isEmpty();
};

#endif // LINKEDLIST_H
