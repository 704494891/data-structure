//
// Created by gsh on 2020/10/16.
//

#include "Link_Queue.h"

template <class T>
Link_Queue<T>::Link_Queue()
{
    Q=new Link_Queue_Head<T>();
    Q->begin= nullptr;
    Q->end= nullptr;
}

template <class T>
Link_Queue<T>::~Link_Queue()
{
    Node<T> *p;
    Node<T> *q;
    p=Q->begin;
    if (p!= nullptr)
    {
        if (Q->begin==Q->end)
        {
            delete Q->begin;
        } else{
            q=p->next;
            while (q!= nullptr)
            {
                delete p;
                p=q;
                q=p->next;
            }
            delete p;
        }
    }delete Q;
}

template <class T>
bool Link_Queue<T>::queue_empty()
{
    return Q->end==Q->begin== nullptr;
}

template <class T>
void Link_Queue<T>::push_queue(T e)
{
    Node<T> *p=new Node<T>();
    p->data=e;
    p->next= nullptr;
    if (Q->end== nullptr)//如果链队是空
    {
        Q->begin=p;
        Q->end=p;
    }
    else
    {
        Q->end->next=p;
        Q->end=p;
    }
}

template <class T>
bool Link_Queue<T>::pop_queue(T &e)
{
    Node<T> *p;
    p=Q->begin;
    if (p== nullptr){
        return false;
    }
    if (p==Q->end)
    {
        e=p->data;
        delete p;
        p=Q->end= nullptr;

    } else{
        e=p->data;
        Q->begin=p->next;
        delete p;
    }

}