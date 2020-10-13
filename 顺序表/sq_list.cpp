//
// Created by gsh on 2020/10/13.
//

#include "sq_list.h"
#include <iostream>

using namespace std;

const int max_size=100;

//顺序表的无参构造
template <class T>
sq_list<T>::sq_list()
{
    length=0;
    data=new T[max_size];
}

//顺序表的析构
template <class T>
sq_list<T>::~sq_list<T>()
{
    delete [] data;
}

//把in_put的前n个元素放到顺序表中
template <class T>
void sq_list<T>::create_list(T in_put[],int n)
{
    for (int i=0;i<n;i++)
    {
        data[i]=in_put[i];
    }
    this->length=n;
}

//打印顺序表
template <class T>
void sq_list<T>::print_list()
{
    if (this->length<1)
    {
        return;
    }
    for (int i=0;i< this->length;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

//返回长度
template <class T>
int sq_list<T>::print_list_length()
{
    return this->length;
}

//安索引返回元素值
template <class T>
bool sq_list<T>::get_elem(int i,T &e)
{
    if (i<0||i>length)
    {
        return false;
    }
    e=data[i];
    return true;
}

//返回元素索引
template <class T>
int sq_list<T>::find_elem_index(T e)
{
    for (int i=0;i<length;i++)
    {
        if (e==data[i])
        {
            return i;
        }
    }
    return -1;
}

//在索引为i的位置插入元素
template <class T>
bool sq_list<T>::list_insert(int i,T e)
{
    if (i<0||i>length)
    {
        return false;
    }
    int index;
    for (index= this->length;index>i;index--)
    {
        data[index]=data[index-1];
    }
    data[i]=e;
    length++;
}

//删除索引对应的元素
template <class T>
bool sq_list<T>::list_delete(int i)
{
    if (i<0||i>length)
    {
        return false;
    }
    for (int index=i;index<length-1;index++)
    {
        data[index]=data[index+1];
    }
    length--;
    return true;
}