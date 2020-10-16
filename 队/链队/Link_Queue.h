//
// Created by gsh on 2020/10/16.
//

#ifndef UNTITLED_LINK_QUEUE_H
#define UNTITLED_LINK_QUEUE_H



template <class T>
struct Node{
    T data;
    Node *next;
};

template <class T>
struct Link_Queue_Head {
    Node<T> *begin;
    Node<T> *end;
};

template <class T>
class Link_Queue
{
    Link_Queue_Head<T> *Q;

public:
    Link_Queue();
    ~Link_Queue();
    bool queue_empty();
    void push_queue(T e);
    bool pop_queue(T &e);
};




#endif //UNTITLED_LINK_QUEUE_H
