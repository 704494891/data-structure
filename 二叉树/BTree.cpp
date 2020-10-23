//
// Created by gsh on 2020/10/22.
//


#include "BTree.h"
#include <iostream>
#include "algorithm"

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
    int top = -1;
    int k = 0;
    int j = 0;
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
BTNode<T> *BTree<T>::find_Node_UN(BTNode<T> *t, T x) {
    BTNode<T> *p;
    if (t == nullptr) {
        return nullptr;
    } else if (t->data == x) {
        return t;
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
