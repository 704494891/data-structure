//
// Created by gsh on 2020/10/15.
//

#ifndef UNTITLED_SQSTACK_H
#define UNTITLED_SQSTACK_H

template <class T>
class SqStack {

public:
    T *data;
    int top;

public:
    SqStack();
    ~SqStack();
    bool stack_empty();
    bool push(T e);
    bool pop (T &e);
    bool get_elem(T &e);
};




#endif //UNTITLED_SQSTACK_H
