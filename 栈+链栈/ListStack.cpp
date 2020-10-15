//
// Created by gsh on 2020/10/15.
//

#include "ListStack.h"

template <class T>
ListStack<T>::ListStack()
{
    head=new Node<T>();
    head->next= nullptr;
}

template <class T>
ListStack<T>::~ListStack()
{
    Node<T> *p,*q;
    p=head;
    q=p->next;
    while (q!= nullptr)
    {
        delete p;
        p=q;
        q=p->next;
    }
    delete p;
}

template <class T>
bool ListStack<T>::stack_empty()
{
    return head->next== nullptr;
}

template <class T>
bool ListStack<T>::push(T e)
{
    Node<T> *p=new ListStack<T>();
    p->data=e;
    p->next=head->next;
    head->next=p;
}

template <class T>
bool ListStack<T>::pop (T &e)
{
    if (head->next== nullptr)
    {
        return false;
    }
    Node<T> *p=new ListStack<T>();
    p=head->next;
    e=p->data;
    head->next=p->next;
    delete p;
    return true;
}

template <class T>
bool ListStack<T>::get_top_elem(T &e)
{
    if (head->next== nullptr)
    {
        return false;
    }
    e=head->next->data;
    return false;
}