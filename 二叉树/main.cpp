#include <iostream>
#include "BTree.h"
#include "string"
#include "BTree.cpp"

using namespace std;

int main() {
//    string ss="A(B(D(,G)),C(E,F))";
    BTree<char> test_tree;
    char *tree_str = "A(B(D(,G)),C(E,F))";
    test_tree.create_tree(tree_str);

    //打印输出树
    test_tree.print_tree();


    BTNode<char> *node_test_find;
    cout << endl;
    node_test_find = test_tree.find_Node('G');
    cout << "查找的结果是" << node_test_find->data;


    int height = test_tree.tree_hight();
    cout << "高度是:" << height << endl;

    //先序遍历
    cout << "先序遍历:";
    pre_order(test_tree);

    cout << endl;

    //中序遍历
    cout << "中序遍历:";
    in_order(test_tree);

    cout << endl;

    //后序遍历
    cout << "后序遍历:";
    post_order(test_tree);

//非递归
    cout << endl;
    cout << "先序遍历:";
    pre_order_stack(test_tree);

    cout << endl;
    cout << "中序遍历:";
    in_order_stack(test_tree);

    cout << endl;
    cout << "后序遍历:";
    post_order_stack(test_tree);

    //层次遍历(用队列)
    cout <<endl ;
    cout <<"层次遍历:";
    print_level(test_tree);

    //打印叶子节点
    cout <<endl;
    test_tree.print_leaf_node(test_tree.root);

    return 0;
}
