//
// Created by gsh on 2020/10/22.
//

#ifndef TREE_BTREE_H
#define TREE_BTREE_H

template <class T>
struct BTNode
{
    T data;
    BTNode *lchild;
    BTNode *rchild;
};

template<class T>
class BTree {
public:
    BTNode<T> *root;

public:
    BTree();
    ~BTree();
    void create_tree(char *str);
    void print_tree();
    BTNode<T> *find_Node(T x);
    int tree_hight();
    void print_leaf_node(BTNode<T> *root);



private:
    int tree_hight_UN(BTNode<T> *t);
    BTNode<T> *find_Node_UN(BTNode<T> *t,T x);
    void print_tree_UN(BTNode<T> *t);
    void destory_tree(BTNode<T> *r);

};

template<class T>
void pre_order_stack(BTree<T> &obj_tree);
template<class T>
void in_order_stack(BTree<T> &obj_tree);
template<class T>
void post_order_stack(BTree<T> &obj_tree);

//template<class T>
//void pre_order_UN(BTNode<T> *t);

template<class T>
void print_level(BTree<T> &obj_tree);


#endif //TREE_BTREE_H
