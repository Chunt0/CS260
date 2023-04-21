/*
 CHRISTOPHER HUNT
 CS260
*/

#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <iostream>

class DynArr{
    private:
    // Attributes
    int *m_array;
    int m_size;
    int m_capacity;
    int resize;

    public:
    // Constructor and Destructor
    DynArr();
    ~DynArr();

    // Methods
    void appendList(int item);
    void removeItem(int item);
    void insertItem(int item, int index);
    int countItem(int item); 
    int indexItem(int item); 
    void popItem(int index);
    void clearList(); 
    void copyList(int* new_list);
    void extendList(int* list_to_add, int length);
    void reverseList();
    void sortList();
    void merge();
    void mergeSort();
    void printArr();
    bool isFull();
    bool isEmpty();
    void menu();
};

#endif
