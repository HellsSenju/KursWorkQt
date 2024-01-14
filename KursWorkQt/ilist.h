#ifndef ILIST_H
#define ILIST_H


class IList
{
public:

    virtual ~IList() {};

    virtual void pushBack(int d) = 0;
    virtual void pushFront(int d) = 0;
    virtual void removeFirst() = 0;
    virtual void removeLast() = 0;
    virtual bool contains(int d) = 0;
    virtual void print() = 0;
    virtual void clear() = 0;
};

#endif // ILIST_H
