// CHRISTOPHER HUNT
// CS260
// node.h

#ifndef DYN_NODE_H
#define DYN_NODE_H

#include <iostream>

// A node holds a value and points to the next element in a linked-list structure
struct DynNode{
    int values[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    DynNode* next = nullptr;
};

#endif