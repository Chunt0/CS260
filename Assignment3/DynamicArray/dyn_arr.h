#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <iostream>

class DynArr{
    private:
    // Attributes
    int *m_array;
    int m_size;
    int m_init_size;
    int resize;

    public:
    // Constructor and Destructor
    DynArr();
    ~DynArr();

    // Methods
    void appendList(int item);
    void removeItem(int item);
    void printArr();
    bool isFull();
    bool isEmpty();
    void menu();
};

#endif