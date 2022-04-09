// CHRISTOPHER HUNT
// CS260
// stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"

// A Stack is a type of list that is of type: Last In, First Out
class Stack{
    private:
    Node* top;
    int size;

    public:
    // Constructor/Destructor
    Stack();
    ~Stack();

    // Methods
    int getSize();
    int emptyCheck();
    void addNode(int);
    void rmNode();
    void printStack();
    void selectionMenu();
};

#endif