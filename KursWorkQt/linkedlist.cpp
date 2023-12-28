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

bool LinkedList::contains(int d)
{
    Node* node = first;

    while(node){
        if(node->data == d)
            return true;
        node = node->next;
    }
    return false;
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

QList<QString> *LinkedList::toQList()
{
    QList<QString> *list = new QList<QString>();
    Node *current = first;
    while(current){
        list->append(QString::number(current->data));
        current = current->next;
    }
    return list;
}

bool LinkedList::isEmpty()
{
    return first == nullptr;
}
