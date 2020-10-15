//
// Created by gsh on 2020/10/15.
//

#ifndef UNTITLED_LISTSTACK_H
#define UNTITLED_LISTSTACK_H
template <class T>

class Node {
public:
    T data;
    Node<T> *next;
};

template <class T>
class ListStack {
public:
    Node<T> *head;
public:
    ListStack();
    ~ListStack();
    bool stack_empty();
    bool push(T e);
    bool pop (T &e);
    bool get_top_elem(T &e);
};


#endif //UNTITLED_LISTSTACK_H
