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

void Queue::printQueue(){
    Node* current = head;
    while(current != nullptr){
        std::cout << "####VALUE: " << current->value << "####" << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

void Queue::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    while(select_on){
        std::cout << "\n1. Enqueue.\n2. Dequeue.\n3. Print list.\n4. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            enqueue();
            break;
            
            case 2:
            dequeue();
            break;

            case 3:
            printQueue();
            break;

            case 4:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
        }    
    }
}