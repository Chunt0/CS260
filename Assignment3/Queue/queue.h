#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"

class Queue{
    
    private:  
    // Attributes
    Node* head;
    int position;

    public:
    // Constructor/Destructor
    Queue();
    ~Queue();

    // Methods
    void enqueue();
    void dequeue();
    void printQueue();
    void menu();
};

#endif