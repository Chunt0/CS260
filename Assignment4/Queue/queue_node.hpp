/*
Christopher Hunt
CS 260
*/

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include <iostream>

// A node holds a value and points to the next element in a linked-list structure
template<typename N>
struct Node{
    N value;
    Node* next = nullptr;
};

#endif