#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <QDebug>
#include "Node.h"

class DoubleLinkedList
{
public:
    DoubleLinkedList();

    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    Node* contains(int d);
    void print();

private:
    Node *head, *tail;
    bool isEmpty();
};

#endif // DOUBLELINKEDLIST_H
