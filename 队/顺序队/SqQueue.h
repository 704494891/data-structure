//
// Created by gsh on 2020/10/15.
//

#ifndef UNTITLED1_SQQUEUE_H
#define UNTITLED1_SQQUEUE_H

template <class T>
class SqQueue {
public:
    T *data;
    int end;
    int begin;
public:
    SqQueue();
    ~SqQueue();
    bool queue_empty();
    bool push_queue(T e);
    bool pop_queue(T &e);
};



#endif //UNTITLED1_SQQUEUE_H
