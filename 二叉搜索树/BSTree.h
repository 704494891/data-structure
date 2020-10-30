//
// Created by gsh on 2020/10/30.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

template<typename T>
struct BSTNode{
    T key;
    char data;
    BSTNode<T> *lchild;
    BSTNode<T> *rchild;

};

template<typename T>
class BSTree {
    BSTNode<T> *r;
public :
    BSTree();
    ~BSTree();

    bool insert_node(T key);
    bool create_tree(T a[],int n);
    void print_tree();
    bool search_node(T k,BSTNode<T> *res);//尾递归
    BSTNode<T>* search_node2(T k,BSTNode<T> *r);//迭代
    bool delete_tree(BSTNode<T>*b);
    BSTNode<T>* find_min_node(BSTNode<T> *r);
    BSTNode<T>* find_max_node(BSTNode<T> *r);
    bool delete_node(T k);



private:
    bool insert_node_UN(BSTNode<T> *&p,T key);
    bool search_node_UN(BSTNode<T> *p,T k,BSTNode<T> *&res);
    bool delete_node1(BSTNode<T> *b, T k);
    bool delete_node2(BSTNode<T> *&p);
    void delete_node3(BSTNode<T> *p,BSTNode<T> *&t);



};


#endif //BSTREE_BSTREE_H
