#include "linkedlist.h"

LinkedList::LinkedList()
{
    first = nullptr;
}

void LinkedList::pushBack(int d)
{
    Node *newNode = new Node(d);

    if(isEmpty()){
        first = newNode;
        last = newNode;
        return;
    }
    last->next = newNode;
    last = newNode;
}

void LinkedList::pushFront(int d)
{
    Node *newNode = new Node(d);

    if(isEmpty()){
        first = newNode;
        last = newNode;
        return;
    }

    newNode->next = first;
    first = newNode;
}

void LinkedList::removeFirst()
{
    if(isEmpty())
        return;

    Node* node = first;
    first = node->next;
    delete node;
}

void LinkedList::removeLast()
{
    if(isEmpty())
        return;
    if(first == last){
        removeFirst();
        return;
    }

    Node* node = first;
    while(node->next != last)
        node = node->next;

    node->next = nullptr;
    delete last;
    last = node;
}

Node *LinkedList::contains(int d)
{
    Node* node = first;
    while(node && node->data != d)
        node = node->next;

    return (node && node->data == d) ? node : nullptr;
}

void LinkedList::print()
{
    qDebug() << "===========Print LinkedList============";
    if(isEmpty()){
        qDebug() << "List is empty";
    }
    Node *current = first;
    while(current){
        qDebug() << current->data;
        current = current->next;
    }
    qDebug() << "========End Of Print LinkedList========";
    qDebug() << "";
}

void LinkedList::clear()
{
    if(isEmpty())
        return;

    Node* current = first;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }

    first = nullptr;
}

bool LinkedList::isEmpty()
{
    return first == nullptr;
}
