#ifndef NODE_H
#define NODE_H

struct Node{
    int data;
    Node *prev,*next;

    Node(int _data) : data(_data), prev(nullptr), next(nullptr){}
};

#endif // NODE_H
