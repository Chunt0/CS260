// CHRISTOPHER HUNT
// CS260
// stack.cpp

#include "stack.h"

// Constructor
Stack::Stack(){
    top = nullptr;
    size = 0;
}

// Destructor
Stack::~Stack(){
    // Delete dynamically allocated objects
    Node* deletePtr;
    while(top != nullptr){
        deletePtr = top;
        top = top->next;
        delete deletePtr;
    }
}


//Methods

// Returns size of stack
int Stack::getSize(){return size;}

// Returns 1 if stack is empty, 0 if it contains nodes, 2 if some other error occurs.
int Stack::emptyCheck(){
    if(top == nullptr){
        return 1;
    }
    else if(top != nullptr){
        return 0;
    }
    return 2;
}

// Adds a node to the top of the stack: push
void Stack::addNode(int value){
    Node* n = new Node{value, top};
    top = n;
    size++;
}

// Removes the node at the top of the stack: pop
void Stack::rmNode(){
    if(emptyCheck() == 1){
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    else if(emptyCheck() == 2){
        std::cout << "#### ERROR CODE 2 ####" << std::endl;
        return;
    }

    else{
        Node* deletePtr = top;
        top = top->next;
        delete deletePtr;
        size--;
    }
}

// Prints stack
void Stack::printStack(){
    Node* current = top;
    while(current != nullptr){
        std::cout << "Value: " << current->value << std::endl;
        current = current->next;
    }
}

// Selection mode for the user to access the public methods
void Stack::selectionMenu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    while(select_on){
        std::cout << "\n1. Push.\n2. Pop.\n3. Print list.\n4. Get size.\n5. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter Value: ";
            std::cin >> value;
            std::cout << std::endl;
            addNode(value);
            value = 0;
            break;
            
            case 2:
            rmNode();
            break;

            case 3:
            printStack();
            break;

            case 4:
            std::cout << getSize() << std::endl;;
            break;

            case 5:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
        }    
    }
}
