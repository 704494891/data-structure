//
// Created by gsh on 2020/10/13.
//

#ifndef NORMAL_LINKLIST_LINK_LIST_H
#define NORMAL_LINKLIST_LINK_LIST_H

template <class T>
class Node
{
public:
    T data;
    Node <T> *next;
};

template<class T>
class Link_List{
private:
    Node<T> *head;
public:
    Link_List();
    ~Link_List();
    void create_List_begin(T a[],int n);//头插法
    void create_List_end(T a[],int n);//尾插法
    void print_list_data();
    int get_list_length();
    bool get_elem(int i,T &e);
    int find_elem(T e);
    bool list_insert(int i,T e);
    bool list_delete(int i);
    void sort();
};





#endif //NORMAL_LINKLIST_LINK_LIST_H
