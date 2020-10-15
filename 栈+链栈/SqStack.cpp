//
// Created by gsh on 2020/10/15.
//

#include "SqStack.h"
using namespace std;
const int max_num=100;

template<class T>
SqStack<T>::SqStack()
{
    data=new T[max_num];
    top=-1;
}

template<class T>
SqStack<T>::~SqStack()
{
    delete [] data;
}

template<class T>
bool SqStack<T>:: stack_empty()
{
    return top==-1;
}

template<class T>
bool SqStack<T>:: push(T e)
{
    if (top==max_num-1)
    {
        return false;
    }
    top++;
    data[top]=e;
    return true;
}

template<class T>
bool SqStack<T>:: pop (T &e)
{
    if (stack_empty())
    {
        return false;
    } else{
        e=data[top];
        top--;
        return true;
    }
}

template<class T>
bool SqStack<T>:: get_elem(T &e) {
    if (stack_empty()) {
        return false;
    } else {
        e = data[top];
        return true;
    }
}
