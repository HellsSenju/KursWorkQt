#include "dequelist.h"

DequeList::DequeList()
{
    deque = new Deque();
}

DequeList::DequeList(int dequeSize)
{
    deque = new Deque(dequeSize);
}

DequeList::~DequeList()
{
    delete deque;
}

void DequeList::pushBack(int d)
{
    deque->insertRear(d);
}

void DequeList::pushFront(int d)
{
    deque->insertFront(d);
}

void DequeList::removeFirst()
{
    deque->deleteFront();
}

void DequeList::removeLast()
{
    deque->deleteRear();
}

bool DequeList::contains(int d)
{
    return deque->contains(d);
}

void DequeList::print()
{
    qDebug() << "===========Print DequeList============";
    deque->print();
    qDebug() << "========End Of Print DequeList========";
    qDebug() << "";
}
