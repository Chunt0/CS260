/*
Christopher Hunt
CS 260
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "queue_node.h"
template<typename T>
class Queue{
    
    private:  
    // Attributes
    Node<T>* head;
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