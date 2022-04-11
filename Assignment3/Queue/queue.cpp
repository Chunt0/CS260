#include "queue.h"

Queue::Queue(){
    head = nullptr;
    position = 0;
}

Queue::~Queue(){
    Node* current;
    while(head != nullptr){
        current = head;
        head = head->next;
        delete current;
    }
}

void Queue::enqueue(){
    Node* n = new Node;
    Node* current = head;
    position++;
    n->value = position;
    if(head != nullptr){
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = n;
    }
    else{
        head = n;
    }
}

void Queue::dequeue(){
    Node* deletePtr;
    if(head != nullptr){
        deletePtr = head;
        head = head->next;
        delete deletePtr;
    }
    else{
        std::cout << "The queue is empty." << std::endl;
    }
}