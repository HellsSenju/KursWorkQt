#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QDebug>

struct Node{
    int data;
    Node *next;

    Node(int _data) : data(_data), next(nullptr){}
};

class LinkedList
{
public:
    LinkedList();
    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    Node* contains(int d);
    void print();

private:
    Node *first;
    Node *last;

    bool isEmpty();
};

#endif // LINKEDLIST_H
