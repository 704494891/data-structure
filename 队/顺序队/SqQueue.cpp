//
// Created by gsh on 2020/10/15.
//

#include "SqQueue.h"
const int max_size=100;
template <class T>
SqQueue<T>::SqQueue()
{
    data=new T[max_size];
    begin=-1;
    end=-1;
}

template <class T>
SqQueue<T>::~SqQueue()
{
    delete[] data;
}

template <class T>
bool SqQueue<T>::queue_empty()
{
    return begin==end;
}

template <class T>
bool SqQueue<T>::push_queue(T e)
{
    if (begin==max_size-1)
    {
        return false;
    }
    begin++;
    data[begin]=e;
    return true;
}

template <class T>
bool SqQueue<T>::pop_queue(T &e)
{
    if (begin==end)
    {
        return false;
    }
    begin++;
    e=data[begin];
    return true; byiu

}