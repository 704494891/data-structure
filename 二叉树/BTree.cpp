//
// Created by gsh on 2020/10/22.
//


#include "BTree.h"
#include <iostream>
#include "algorithm"
#include <queue>
#include <stack>

using namespace std;
const int maxsize = 1000;

template<class T>
BTree<T>::BTree() {
    root = nullptr;
}


template<class T>
void BTree<T>::destory_tree(BTNode<T> *root) //递归删除节点
{
    if (root != nullptr) {
        destory_tree(root->lchild);
        destory_tree(root->rchild);
        delete root;
    }
}

template<class T>
BTree<T>::~BTree() {
    destory_tree(root);
}

template<class T>
void BTree<T>::create_tree(char *str) {
    BTNode<T> *St[maxsize];//顺序栈
    BTNode<T> *p;
    int top = -1;//栈的指针
    int k = 0;//左右树的标志位
    int j = 0;//输入字符串的指针
    char ch;

    while (str[j] != '\0') {
        ch = str[j];
        switch (ch) {
            case '(':
                top++;
                St[top] = p;//把'('前的根节点进栈
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = new BTNode<T>();
                p->lchild = p->rchild = nullptr;
                p->data = ch;
                if (root == nullptr) {
                    this->root = p;
                } else {
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
                break;
        }
        j++;
    }
}


template<class T>
void BTree<T>::print_tree_UN(BTNode<T> *t) {
    if (t != nullptr) {
        cout << t->data;
        if (t->lchild != nullptr || t->rchild != nullptr) {
            cout << '(';
            print_tree_UN(t->lchild);
            if (t->rchild != nullptr) {
                cout << ',';
            }

            print_tree_UN(t->rchild);
            cout << ')';

        }
    }
}

template<class T>
void BTree<T>::print_tree() {
    print_tree_UN(this->root);
}

template<class T>
void BTree<T>::print_leaf_node(BTNode<T> *root)
{
     if (root==nullptr)
     {
         return;
     }
     if (root->lchild==nullptr&&root->rchild==nullptr){
         cout <<root->data;
     }

     print_leaf_node(root->lchild);
     print_leaf_node(root->rchild);
}

template<class T>
BTNode<T> *BTree<T>::find_Node_UN(BTNode<T> *t, T x) {
    BTNode<T> *p;
    //终止条件
    if (t == nullptr) {
        return nullptr;
    } else if (t->data == x) {
        return t;
        //每次递归做的事情
    } else {
        p = find_Node_UN(t->lchild, x);
        if (p != nullptr) {
            return p;
        } else {
            p = find_Node_UN(t->rchild, x);
            if (p != nullptr) {
                return p;
            }
        }
    }
}

template<class T>
BTNode<T> *BTree<T>::find_Node(T x) {
    return find_Node_UN(this->root, x);
}


template<class T>
int BTree<T>::tree_hight_UN(BTNode<T> *t) {
    int lchild, rchild;
    if (t == nullptr) {
        return 0;
    } else {
        lchild = tree_hight_UN(t->lchild);
        rchild = tree_hight_UN(t->rchild);
        int height = max(rchild, lchild) + 1;
        return height;
    }
}

template<class T>
int BTree<T>::tree_hight() {
    return tree_hight_UN(this->root);
}

//先序遍历(递归)
template<class T>
void pre_order_UN(BTNode<T> *t){
    if (t==nullptr)
    {
        return ;
    }
    cout<<t->data;
    pre_order_UN(t->lchild);
    pre_order_UN(t->rchild);
}

template<class T>
void pre_order(BTree<T> &obj_tree){
    pre_order_UN(obj_tree.root);
}

//中序遍历(递归)
template<class T>
void in_order_UN(BTNode<T> *t){
    if (t==nullptr)
    {
        return ;
    }

    in_order_UN(t->lchild);
    cout<<t->data;
    in_order_UN(t->rchild);
}

template<class T>
void in_order(BTree<T> &obj_tree){
    in_order_UN(obj_tree.root);
}

//后序遍历(递归)
template<class T>
void post_order_UN(BTNode<T> *t){
    if (t==nullptr)
    {
        return ;
    }

    post_order_UN(t->lchild);

    post_order_UN(t->rchild);
    cout<<t->data;
}

template<class T>
void post_order(BTree<T> &obj_tree){
    post_order_UN(obj_tree.root);
}

//先序遍历(非递归:用栈)
template<class T>
void pre_order_stack(BTree<T> &obj_tree){
    pre_order_stack_UN(obj_tree.root);
}

template<class T>
void pre_order_stack_UN(BTNode<T> *t){
//    BTNode<T> *st[100];//这里注释掉的是没问题的,用数组模拟了栈
//    int top=-1;
//    BTNode<T> *p=t;
//    while(p!=nullptr||top!=-1)
//    {
//        while(p!=nullptr)
//        {
//            cout<<p->data;//第一次碰到它
//            top++;
//            st[top]=p;
//            p=p->lchild;
//        }
//        if (top!=-1)
//        {
//            p=st[top];
//            top--;
//            p=p->rchild;
//        }
        stack <BTNode<T> *> tmp;
        BTNode<T>*p=t;
        while (!tmp.empty()||p!=nullptr)
        {
            while(p!=nullptr)
            {
                cout<<p->data;
                tmp.push(p);
                p=p->lchild;
            }
            if (!tmp.empty())
            {
                p=tmp.top();
                p=p->rchild;
                tmp.pop();
            }

    }
}


//中序遍历(非递归:用栈)
template<class T>
void in_order_stack(BTree<T> &obj_tree){
    in_order_stack_UN(obj_tree.root);
}

template<class T>
void in_order_stack_UN(BTNode<T> *t){
    BTNode<T> *st[100];
    int top=-1;
    while(t!=nullptr||top!=-1)
    {
        while(t!=nullptr)//把所有左节点压近栈里
        {
            top++;
            st[top]=t;
            t=t->lchild;
        }
        if(top>-1)
        {
            t=st[top];
            top--;
            cout<<t->data;//第二次碰到它
            t=t->rchild;

        }
    }
}


//后序遍历(非递归:用栈)//这个好难想明白...
template<class T>
void post_order_stack(BTree<T> &obj_tree){
    post_order_stack_UN(obj_tree.root);
}

template<class T>
void post_order_stack_UN(BTNode<T> *t){
    BTNode<T> *st[100];
    int top=-1;
    BTNode<T> *q;
    bool flag;
    do
    {
        while(t!=nullptr)//把所有左节点压近栈里
        {
            top++;
            st[top]=t;
            t=t->lchild;
        }
        q=nullptr;
        flag=true;
        while(top!=-1 &&flag==true){
            t=st[top];
            if (t->rchild==q)
            {
                cout<<t->data;
                top--;
                q=t;

            } else
            {
                t=t->rchild;
                flag=false;
            }
        }
    }while(top!=-1);
}



template<class T>
void print_level(BTree<T> &obj_tree)
{
    queue<BTNode<T>*> qu;
    BTNode<T> *p;
    p=obj_tree.root;
    qu.push(p);
    if (p==nullptr)
    {
        return;
    }
    while(!qu.empty())
    {
        BTNode<T> *tmp=qu.front();
        cout<<tmp->data;
        qu.pop();
        if (tmp->lchild!=nullptr)
        {
            qu.push(tmp->lchild);
        }
        if (tmp->rchild!=nullptr)
        {
            qu.push(tmp->rchild);
        }
    }
}