//
// Created by gsh on 2020/10/13.
//

#include "Link_List.h"


#include "iostream"
using namespace std;

template <class T>
Link_List<T>::Link_List()
{
    head=new Node<T>();
    head->next= nullptr;
    head->data=0;
}


template <class T>
Link_List<T>::~Link_List()
{
    Node<T> *m,*n;
    m=head->next;
    n=m->next;
    while (n!= nullptr)
    {
        delete m;
        m=n;
        n=n->next;
    }
    delete m;
}

template <class T>
void Link_List<T>::create_List_begin(T a[],int n)//头插法
{
    int i;
    Node<T> *tmp;
    head->next=nullptr;
    for (i=0;i<n;i++)
    {
        tmp=new Node<T>();
        tmp->data=a[i];
        tmp->next=head->next;
        head->next=tmp;

    }
}
template <class T>
void Link_List<T>::create_List_end(T a[],int n)//尾插法
{
    int i;
    Node<T> *after_node;
    Node<T> *front_node=head;
    for (i=0;i<n;i++)
    {
        after_node=new Node<T>();
        after_node->data=a[i];

        front_node->next=after_node;
        front_node=after_node;
    }
    front_node= nullptr;
}
template <class T>
void Link_List<T>::print_list_data()
{
    Node<T> *p_current;
    p_current=head->next;
    cout<<"链表是: ";
    while (p_current!= nullptr)
    {
        cout<<p_current->data<<" ";
        p_current=p_current->next;
    }
    cout<<endl;
}

template <class T>
int Link_List<T>::get_list_length()
{
    Node<T> *p=head->next;
    int i=0;
    while (p!= nullptr)
    {
        i++;
        p=p->next;
    }
    return i;
}

template <class T>
bool Link_List<T>::get_elem(int i,T &e)
{

    Node<T> *tmp;
    tmp=head->next;
    for (int j=0;j<i;j++)
    {
        tmp=tmp->next;
    }
    if (tmp== nullptr){

        return false;
    } else{
        e=tmp->data;
        return true;
    }

}

template <class T>
int Link_List<T>::find_elem(T e)
{
    Node<T> *tmp;
    tmp=head->next;
    int i=0;
    while (tmp!= nullptr&&tmp->data!=e)
    {
        tmp=tmp->next;
        i++;
    }
    if (tmp==nullptr){
        return 0;
    } else{
        return i;
    }
}

template <class T>
bool Link_List<T>::list_insert(int i,T e)
{
    Node<T> *tmp;
    tmp=head->next;
    int j=0;
    while (tmp!= nullptr&&j<i-1)
    {
        tmp=tmp->next;
        j++;
    }
    Node<T> *insert_node=new Node<T>();
    insert_node->data=e;

    insert_node->next=tmp->next;
    tmp->next=insert_node;



}

template <class T>
bool Link_List<T>::list_delete(int i)
{
    Node<T> *tmp,*tmp2;
    tmp=head->next;
    int j=0;
    while (tmp!= nullptr&&j<i-1)
    {
        tmp=tmp->next;
        j++;
    }
    tmp2=tmp->next;
    if (tmp2== nullptr)
    {
        return false;
    } else{

        tmp->next=tmp2->next;
        delete tmp2;
        return true;
    }

}

template <class T>
void sort();