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
    int* copyList();
    void extendList(int* list_to_add); //
    void reverseList();
    void sortList(); // 
    void printArr();
    bool isFull();
    bool isEmpty();
    void menu();
};

#endif