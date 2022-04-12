// CHRISTOPHER HUNT
// CS260
// node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>

// A node holds a value and points to the next element in a linked-list structure
struct Node{
    int value = 0;
    Node* next = nullptr;
};

#endif