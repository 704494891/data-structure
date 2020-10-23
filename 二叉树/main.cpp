#include <iostream>
#include "BTree.h"
#include "string"
#include "BTree.cpp"
using namespace std;
int main() {
//    string ss="A(B(D(,G)),C(E,F))";
    BTree<char> test_tree;
    char *tree_str= "A(B(D(,G)),C(E,F))";
    test_tree.create_tree(tree_str);
    test_tree.print_tree();



    BTNode<char> *node_test_find;
    cout <<endl;
    node_test_find=test_tree.find_Node('G');
    cout <<"查找的结果是"<<node_test_find->data;



    int height=test_tree.tree_hight();
    cout <<"高度是:"<<height<<endl;





    return 0;
}
