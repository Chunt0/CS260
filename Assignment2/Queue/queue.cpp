#include "queue.h"

Queue::Queue(){
    head = nullptr;
    position = 0;
}

Queue::~Queue(){

}

void Queue::enqueue(){
    Node* n = new Node;
    position++;
    n->value = position;



}

void Queue::dequeue(){

}