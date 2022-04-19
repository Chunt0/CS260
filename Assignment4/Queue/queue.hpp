/*
Christopher Hunt
CS 260
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "./queue_node.hpp"

template<typename T>
class Queue{

    private:
    Node<T>* head;
    int position; 

    public:   
/*
Constructor: Queue()
Description: Constructs Queue object, assigns attributes. 
*/
    Queue(){
        head = nullptr;
        position = 0;
    }

/*
Destructor: ~Queue()
Description: Handles garbage collection when the Queue object goes out of scope.
    A Node* helper is used to cycle through the linked list and delete each.
*/
    ~Queue(){
        Node<T>* current;
        while(head != nullptr){
            current = head;
            head = head->next;
            delete current;
    }
}

/*
Method: enqueue()
Description: Creates a Node on the heap. Uses helper pointers to move through
    the linked list and assigns the node whose next value is NULL to be pointing
    at this new Node. This is considered the back of the list. If the head is
    NULL, head will now be pointing to the new Node.
*/
    void enqueue(T value){
        Node<T>* n = new Node<T>;
        Node<T>* current = head;
        n->value = value;
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

/*
Method: dequeue()
Description: A helper pointer is made equal to the head node. The head node
    is made to point to the next node in the list. The object the helper node
    points to is then deleted. Only the head (or First In) will ever be able
    to be removed.
*/
    void dequeue(){
        Node<T>* deletePtr;
        if(head != nullptr){
            deletePtr = head;
            head = head->next;
            delete deletePtr;
        }
        else{
            std::cout << "The queue is empty." << std::endl;
        }
    }

/*
Method: printQueue()
Description: Uses helper pointer to move through the linked list from the head
    to the back and print their associated values.
*/
    void printQueue(){
        Node<T>* current = head;
        while(current != nullptr){
            std::cout << "####VALUE: " << current->value << "####" << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

/*
Method: menu()
Description: A simple menu interface that allows a user to test the functionality
    of the Queue object.
*/
    void menu(){
        bool select_on {true};
        int selection {0};
        int value {0};
        while(select_on){
            std::cout << "\n1. Enqueue.\n2. Dequeue.\n3. Print list.\n4. Exit\n" << std::endl;
            std::cin >> selection;
            std::cout << "\n\n";
            switch(selection){
                case 1:
                std::cout << "Enter value to store: ";
                std::cin >> value;
                enqueue(value);
                printQueue();
                break;

                case 2:
                dequeue();
                printQueue();
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
};

#endif