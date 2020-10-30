//
// Created by gsh on 2020/10/30.
//

#include "BSTree.h"

template<typename T>
BSTree<T>::BSTree() {
    r = nullptr;
}

template<typename T>
BSTree<T>::~BSTree() {
    if (r != nullptr) {
        delete_tree(r);
    }
}


template<typename T>
bool BSTree<T>::insert_node(T key) {
    return insert_node_UN(r, key);
}

template<typename T>
bool BSTree<T>::insert_node_UN(BSTNode<T> *&p, T key) {
    if (p == nullptr) {
        p = new BSTNode<T>();
        p->key = key;
        p->lchild = p->rchild = nullptr;
        return true;
    } else if (key == p->key) {
        return false;
    } else if (key > p->key) {
        insert_node_UN(p->rchild, key);
    } else if (key < p->key) {
        insert_node_UN(p->lchild, key);
    }
}

template<typename T>
bool BSTree<T>::create_tree(T a[], int n) {
    int i = 0;
    while (i < n) {
        if (insert_node_UN(r, a[i])) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}

template<typename T>
void BSTree<T>::print_tree() {

}

template<typename T>
bool BSTree<T>::search_node(T k, BSTNode<T> *res) {
    search_node_UN(r, k);
}

template<typename T>
bool BSTree<T>::search_node_UN(BSTNode<T> *p, T k, BSTNode<T> *&res) {//尾递归
    if (p == nullptr) {
        return false;
    }
    if (k == p->key) {
        return true;
    }
    if (k < p->key) {
        res = p->lchild;
        return search_node_UN(p->lchild, k);
    }
    if (k > p->key) {
        res = p->rchild;
        return search_node_UN(p->rchild, k);
    }
}

template<typename T>
BSTNode<T> *BSTree<T>::search_node2(T k, BSTNode<T> *r)//迭代法
{
    while (r != nullptr) {
        if (k > r->key) {
            r = r->rchild;
        } else if (k < r->key) {
            r = r->lchild;
        } else {
            return r;
        }
    }
    return nullptr;
}

template<typename T>
bool BSTree<T>::delete_tree(BSTNode<T> *b) {
    if (b != nullptr) {
        destory_tree(b->lchild);
        destory_tree(b->rchild);
        delete b;
    }
}

template<typename T>
BSTNode<T> *BSTree<T>::find_min_node(BSTNode<T> *r) {
    if (r == nullptr) {
        return nullptr;
    } else if (r->lchild == nullptr) {
        return r;
    } else {
        return find_min_node(r->lchild);
    }

}

template<typename T>
BSTNode<T> *BSTree<T>::find_max_node(BSTNode<T> *r) {
    if (r == nullptr) {
        return nullptr;
    } else if (r->rchild == nullptr) {
        return r;
    } else {
        return find_min_node(r->rchild);
    }
}

//删除某个节点(我曹这里好难)
//叶子节点直接删
//有左子树的,把左子树的根节点换上去
//有右子树的,把右子树的根节点换上去
//左右都有的....就好恶心啊...
template<typename T>
bool BSTree<T>::delete_node(T k) {
    return delete_node1(r, k);
}

template<typename T>//查找作用
bool BSTree<T>::delete_node1(BSTNode<T> *b, T k) {

    if (b == nullptr) {
        return false;
    }
    if (k < b->key) {
        return delete_node1(b->lchild, k);
    } else if (k > b->key) {
        return delete_node1(b->rchild, k);
    } else {
        delete_node2(b);
        return true;
    }
}

template<typename T>//删除作用
bool BSTree<T>::delete_node2(BSTNode<T> *&p) {
    BSTNode<T> *q;
    if (p->rchild==nullptr)//右子树没有
    {
        q=p;
        p=p->lchild;
        delete q;
    }
    else if (p->lchild ==nullptr){//左子树没有
        q=p;
        p=p->rchild;
        delete q;
    } else{//左右都有
        delete_node3(p,p->rchild);
    }
}

template<typename T>
void BSTree<T>::delete_node3(BSTNode<T> *p,BSTNode<T> *&t)//处理左右都有的情况
{
    BSTNode<T> *q;
    if (t->rchild!=nullptr) {
        delete_node3(p, t->rchild);
    }
    else{
        p->key=t->key;
        q=t;
        t=t->lchild;
        delete q;
    }


}

