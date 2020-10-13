//
// Created by gsh on 2020/10/13.
//

#ifndef C___SQ_LIST_H
#define C___SQ_LIST_H

template <class T>
class sq_list {
private:
    T *data;
    int length;
public:
    sq_list();
    ~sq_list();
    void create_list(T in_put[],int n);
    void print_list();
    int print_list_length();
    bool get_elem(int i,T &e);
    int find_elem_index(T e);
    bool list_insert(int i,T e);
    bool list_delete(int i);

};


#endif //C___SQ_LIST_H
