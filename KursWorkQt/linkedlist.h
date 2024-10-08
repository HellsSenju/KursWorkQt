#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QDebug>
#include <QList>
#include "Node.h"
#include "ilist.h"

class LinkedList: public IList
{
public:
    LinkedList();

    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    bool contains(int d);
    void print();
    void clear();
    QList<QString> *toQList();

private:
    Node *first;
    Node *last;

    bool isEmpty();
};

#endif // LINKEDLIST_H
