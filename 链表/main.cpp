#include <iostream>
#include "Link_List.h"
#include "Link_List.cpp"



int main() {

    Link_List<int> list;
    int front[]={7,8,9,10,11,12};
    list.create_List_begin(front,5);
    list.print_list_data();


    int len=list.get_list_length();
    cout<<"长度是: "<<len<<endl;

    int a;
    list.get_elem(2,a);
    cout<<"索引为2的元素是: "<<a<<endl;

    int b;
    b=list.find_elem(8);
    cout<<"寻找元素8的索引: "<<b<<endl;

    list.list_insert(3,47);
    list.print_list_data();

    list.list_delete(1);
    list.print_list_data();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
