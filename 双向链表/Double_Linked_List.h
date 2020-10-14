//
// Created by gsh on 2020/10/14.
//

#ifndef DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H

template <class T>
class Node{
public:
    T data;
    Node *prior;
    Node *next;
};

template <class T>
class Double_Linked_List {
public:
    Node<T> *head;
private:
    Double_Linked_List();
    ~Double_Linked_List();
    void create_List_begin(T a[],int n);//头插法
    void create_List_end(T a[],int n);//尾插法
    void print_list_data();
    int get_list_length();
    bool get_elem(int i,T &e);
    int find_elem(T e);
    bool list_insert(int i,T e);
    bool list_delete(int i);
};



#endif //DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
