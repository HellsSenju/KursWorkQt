#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <QDebug>
#include <cmath>
#include "ilist.h"

class ArrayList: public IList
{
public:
    ArrayList();
    ~ArrayList();

    void pushBack(int d);
    void pushFront(int d);
    void removeFirst();
    void removeLast();
    bool contains(int d);
    void print();
    void clear();


private:
    int *data;
    int list_size; //текущий размер списка
    int arr_size; // текущий размер массива

    void add(int index, int d);
    void remove(int index);
    bool isEmpty();
    bool isNeedToResize();
    void resize();

};

#endif // ARRAYLIST_H
