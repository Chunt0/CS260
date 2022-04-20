/*
Christopher Hunt
CS 260
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template<typename T>

class Queue{


    private:
    struct Node{
        T value;
        Node* next = nullptr;
        int node_index;
    };

    Node* m_head;
    int m_size; 

    public:   
/*
Constructor: Queue()
Description: Constructs Queue object, assigns attributes. 
*/
    Queue(){
        m_head = nullptr;
        m_size = 0;
    }

/*
Destructor: ~Queue()
Description: Handles garbage collection when the Queue object goes out of scope.
    A Node* helper is used to cycle through the linked list and delete each.
*/
    ~Queue(){
        Node* current;
        while(m_head != nullptr){
            current = m_head;
            m_head = m_head->next;
            delete current;
    }
}

/*
Method: enqueue(T value)
Description: Creates a Node on the heap. Uses helper pointers to move through
    the linked list and assigns the node whose next value is NULL to be pointing
    at this new Node. This is considered the back of the list. If the head is
    NULL, head will now be pointing to the new Node.
*/
    void enqueue(T value){
        Node* n = new Node;
        Node* current = m_head;
        
        n->value = value;
        n->node_index = m_size;
        m_size++;

        if(m_head != nullptr){
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = n;
        }
        else{
            m_head = n;
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
        Node* deletePtr;
        if(m_head != nullptr){
            deletePtr = m_head;
            m_head = m_head->next;
            delete deletePtr;
            m_size--;
        }
        else{
            std::cout << "The queue is empty." << std::endl;
        }
    }

/*
Method: insertItem(T value, int index)
Description:
*/
    void insertItem(T value, int index){
        Node* n = new Node;
        Node* current = m_head;
        Node* temp = m_head;

        n->value = value;
        n->node_index = index;
        m_size++;

        if(m_head != nullptr){
            while(current->next != nullptr && current->node_index != index){
                temp = current;
                current = current->next;
            }
            if(current->node_index == index){
                temp->next = n;
                n->next = current;

                while(current != nullptr){
                    index++;
                    current->node_index = index;
                    current = current->next;
                }
            }
            else{
                std::cout << "####INDEX NOT IN RANGE####" << std::endl;
            }
        }
        else{
            std::cout << "####LIST EMPTY####";
        }
    }

/*
Method: removeItem(int index)
Description: 
*/
    void removeItem(int index){
        Node* deletePtr;
        Node* current = m_head;
        Node* temp = m_head;
        if(m_head != nullptr){
            while(current->node_index != index){
                temp = current;
                current = current->next;
            }
                deletePtr = current;
                current = current->next;
                temp->next = current;
                delete deletePtr;
                m_size--;
                while(current != nullptr){
                    current->node_index = index;
                    current = current->next;
                    index++;
                }
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
        Node* current = m_head;
        while(current != nullptr){
            std::cout << "####VALUE: " << current->value << "####INDEX: " << current->node_index << "####"<< std::endl;
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
        T value;
        int index{0};

        while(select_on){
            std::cout << "\n1. Enqueue.\n2. Dequeue.\n3. Insert Value\n4. Remove by Index\n5. Print list.\n6. Exit\n" << std::endl;
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
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                std::cout << "Enter index to insert: ";
                std::cin >> index;
                insertItem(value, index);
                printQueue();
                break;

                case 4:
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                removeItem(index);
                printQueue();
                break;

                case 5:
                printQueue();
                break;

                case 6:
                std::cout << "#########################\n" << std::endl;
                select_on = false;
            }    
        }
    }
};

#endif