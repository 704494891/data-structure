#include <iostream>
#include "sq_list.h"
#include "sq_list.cpp"//类模板记得要写cpp的include

using namespace std;
int main() {

    sq_list<int> list;
    int a[]={4,5,6,7,8,9};
    list.create_list(a,5);
    cout<<"list:";
    list.print_list();
    cout<<endl;

    int len=list.print_list_length();
    cout<<"list的长度是"<<len<<endl;

    int e;
    list.get_elem(2,e);
    cout<<"list索引2处的元素是"<<e<<endl;

    int index;
    index=list.find_elem_index(8);
    cout<<"元素8的索引"<<index<<endl;

    list.list_insert(2,99);
    cout<<"list索引2处插入99:";
    list.print_list();
    cout<<endl;

    list.list_delete(2);
    cout<<"list删除索引2处:";
    list.print_list();
    cout<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
