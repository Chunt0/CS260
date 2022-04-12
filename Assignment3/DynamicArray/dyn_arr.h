#ifndef DYN_ARR.H
#define DYN_ARR.H

#include "node.h"

class DynArr{
    private:
    // Attributes
    Node* head;
    int size;

    public:
    // Constructor and Destructor
    DynArr();
    ~DynArr();

    // Methods
    void printArr();
};

#endif