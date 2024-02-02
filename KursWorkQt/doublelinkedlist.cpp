#include "doublelinkedlist.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = tail = nullptr;
}

void DoubleLinkedList::pushBack(int d)
{
   Node* newNode = new Node(d);

   newNode->prev = tail;
   if (tail != nullptr)
            tail->next = newNode;

   if (head == nullptr)
            head = newNode;

   tail = newNode;
}

void DoubleLinkedList::pushFront(int d)
{
    Node* newNode = new Node(d);

    newNode->next = head;
    if(head != nullptr)
        head->prev = newNode;

    if(tail == nullptr)
        tail = newNode;

    head = newNode;
}

void DoubleLinkedList::removeFirst()
{
    if (head == nullptr)
        return;

   Node* node = head->next;

   if (node != nullptr)
        node->prev = nullptr;
   else
        tail = nullptr;

   delete head;
   head = node;
}

void DoubleLinkedList::removeLast()
{
    if (tail == nullptr) return;

    Node* node = tail->prev;

    if (node != nullptr)
         node->next = nullptr;
    else
         head = nullptr;

    delete tail;
    tail = node;
}

bool DoubleLinkedList::contains(int d)
{
    Node* node = head;

    while(node){
        if(node->data == d)
            return true;
        node = node->next;
    }
    return false;
}

void DoubleLinkedList::print()
{
    qDebug() << "===========Print DoubleLinkedList============";
    if(isEmpty()){
        qDebug() << "List is empty";
    }
    Node *current = head;
    while(current){
        qDebug() << current->data;
        current = current->next;
    }
    qDebug() << "========End Of Print DoubleLinkedList========";
    qDebug() << "";
}

void DoubleLinkedList::clear()
{
    if(isEmpty())
        return;

    Node* current = head;
    Node* next = nullptr;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = nullptr;
}

bool DoubleLinkedList::isEmpty()
{
    return head == nullptr && tail == nullptr;
}
