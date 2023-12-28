#include "arraylist.h"

ArrayList::ArrayList()
{
    arr_size = 100;
    list_size = 0;
    data = new int[arr_size];
}

ArrayList::~ArrayList()
{
    delete []data;
}

void ArrayList::pushBack(int d)
{
    add(list_size, d);
}

void ArrayList::pushFront(int d)
{
    add(0, d);
}

void ArrayList::removeFirst()
{
    remove(0);
}

void ArrayList::removeLast()
{
    remove(list_size - 1);
}

int ArrayList::contains(int d)
{
    for(int i = 0; i < list_size; i++)
        if(data[i] == d)
            return i;

    return -1;
}

void ArrayList::print()
{
    qDebug() << "===========Print ArrayList============";
    if(isEmpty()){
        qDebug() << "List is empty";
    }

    for(int i = 0; i < list_size; i++)
        qDebug() << data[i];

    qDebug() << "========End Of Print ArrayList========";
    qDebug() << "";
}

void ArrayList::clear()
{
    list_size = 0;
}

void ArrayList::add(int index, int d)
{
    if(isNeedToResize())
        resize();

    for(int i = list_size; i >= index; i--)
        data[i + 1] = data[i];

    data[index] = d;
    list_size++;
}

void ArrayList::remove(int index)
{
    for(int i = index; i < list_size; i++)
        data[i] = data[i + 1];

    list_size--;
}

bool ArrayList::isEmpty()
{
    return list_size == 0;
}

bool ArrayList::isNeedToResize()
{
    return arr_size == list_size;
}

void ArrayList::resize()
{
    int *newArr = new int[arr_size*arr_size];

    for(int i = 0; i < arr_size; i++)
        newArr[i] = data[i];

    data = newArr;
    arr_size *= arr_size;
}
