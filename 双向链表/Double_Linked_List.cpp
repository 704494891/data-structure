//
// Created by gsh on 2020/10/14.
//

#include "Double_Linked_List.h"

template <class T>
Double_Linked_List<T>::Double_Linked_List()
{

}

template <class T>
Double_Linked_List<T>::~Double_Linked_List()
{

}

template <class T>
void Double_Linked_List<T>::create_List_begin(T a[],int n)//头插法(画图理解)
{
    Node<T> *new_node;
    head->next= nullptr;
    int i;
    for (i=0;i<n;i++)
    {
        new_node=new Node<T>();
        new_node->data=a[i];

        new_node->next=head->next;
        if (new_node->next!= nullptr)
        {
            new_node->next->prior=new_node;//新后 的头指针指向新节点
        }

        new_node->prior=head;
        head->next=new_node;//head->next向前挪一位
    }

}

template <class T>
void Double_Linked_List<T>::create_List_end(T a[],int n)//尾插法(画图理解)
{
    Node<T> * new_node;
    Node<T> * end_node;
    end_node=head;
    for (int i=0;i<n;i++)
    {
        end_node->next=new_node;
        new_node->prior=end_node;
        end_node=new_node;
    }
    end_node->next= nullptr;
}

template <class T>
void Double_Linked_List<T>::print_list_data()
{

}

template <class T>
int Double_Linked_List<T>::get_list_length()
{

}

template <class T>
bool Double_Linked_List<T>::get_elem(int i,T &e)
{

}

template <class T>
int Double_Linked_List<T>::find_elem(T e)
{

}

template <class T>
bool Double_Linked_List<T>::list_insert(int i,T e)
{
    int j=0;
    Node<T> *front_node;
    Node<T> *new_node;
    front_node=head;
    while (j<i-1&&front_node!= nullptr)
    {
        front_node=front_node->next;
        j++;
    }
    new_node=new Node<T>();
    new_node->data=e;

    new_node->next=front_node->next;
    new_node->prior=front_node;
    if (front_node->next!= nullptr)
    {
        front_node->next->prior=new_node;
    }
    front_node->next=new_node;


}

template <class T>
bool Double_Linked_List<T>::list_delete(int i)
{
    int j;
    
    Node<T> *delete_before_node;
    Node<T> *delete_after_node;
    Node<T> *delete_node;
    delete_before_node=head;
    for (j=0;j<i;j++)
    {
        delete_before_node=delete_before_node->next;
    }
    delete_node=delete_before_node->next;
    if (delete_node== nullptr)
    {
        return false;
    }
    delete_before_node->next=delete_after_node->next;
    if (delete_after_node->next!= nullptr)
    {
        delete_before_node->next->prior=delete_before_node;
    }

    delete delete_node;
    return true;


    
    
}