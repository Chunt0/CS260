#ifndef DYN_ARR.H
#define DYN_ARR.H

#include "dyn_node.h"

class DynArr{
    private:
    // Attributes
    DynNode* head;
    int size;

    public:
    // Constructor and Destructor
    DynArr();
    ~DynArr();

    // Methods
    
    void printArr();
};

#endif