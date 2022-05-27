/* Christopher Hunt
 * CS260
 * auto_sort_list.cpp
 */

#include "list.h"

/* Constructor: AutoSortList()
 * Description: Initializes list.
 * Analysis: O(1)
 */
List::List(){
    m_head = nullptr;
}

/* Destructor: ~AutoSortList()
 * Description: Traverses list and deletes each nodes
 * Analysis: O(n)
 */
List::~List(){
    Node* deletePtr;
    while(m_head != nullptr){
        deletePtr = m_head;
        m_head = m_head->next;
        delete deletePtr;
    }
}

/* Function: add_node(int value)
 * Description: Adds a node to the list in sorted order, smallest to largest.
 * Analysis: O(n)
 */
void List::addNode(std::string key, int value){
    Node* new_node = new Node;
    Node* current = m_head;
    
    new_node->key = key;
    new_node->value = value;

    if(m_head != nullptr){
        while(current->next != nullptr && current->key.compare(key) != 0){
            current = current->next;
        }
        if(current->next == nullptr && current->key.compare(key) != 0){
            current->next = new_node;    
        }
        else{
            delete new_node;
        }
    }
    else{
        m_head = new_node;
    }
}



/*
 * Function: removeNode(int index)
 * Description: Removes node at given index.
 * Analysis: O(n)
 */
void List::removeNode(std::string key){
    Node* deletePtr = nullptr;
    Node* current = nullptr;
    Node* temp = nullptr;
    if(m_head != nullptr){
        // If index is the first element of the list
        if(m_head->key.compare(key) == 0){
            deletePtr = m_head;
            m_head = m_head->next;
            delete deletePtr;
        }
        else{
            current = m_head;
            while(current != nullptr){
                temp = current;
                current = current->next;

                // If the index searched for is in the last position
                if(current->next == nullptr && current->key.compare(key) == 0){
                    deletePtr = current;
                    temp->next = nullptr;
                    delete deletePtr;
                    break;
                }
                // Else if 
                else if(current->next != nullptr && current->key.compare(key) == 0){
                    deletePtr = current;
                    temp->next = current->next;
                    delete deletePtr;
                    break;
                }
            }
        }
    }
    else{
        std::cout << "List is empty." << std::endl;
    }
}

int List::returnValue(std::string key){
    Node* current = m_head;
    int keys_value = -1;
    while(current != nullptr){
        if (current->key.compare(key) == 0){
            keys_value = current->value;
            break;
        }
        else{
            current = current->next;
        }
    }
    return keys_value;
}

/* Function: print_list()
 * Description: Prints list to screen, index and value.
 * Analysis: O(n)
 */
void List::printList(){
    Node* current = m_head;
    while(current != nullptr){
        std::cout << "Key: " << current->key << " | Value: " << current->value << std::endl;
        current = current->next;
    }
}

/* Function: menu()
 * Description: Allows user to access class methods and exit cleanly.
 * Analysis: O(1)
 */
void List::menu(){
    bool select_on = true;
    int value = 0;
    int index = 0;
    int selection = 0;
    char* key = nullptr;
    while(select_on){
        std::cout << "\n1. Add Node\n2. Remove Node\n3. Print List\n4. Exit" << std::endl;
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "\nEnter a 3-char key: " << std::endl;
                std::cin >> key;
                std::cout << "\nEnter a value: " << std::endl;
                std::cin >> value;
                addNode(key, value);
                printList();
                break;
            case 2:
                std::cout << "\nEnter the key you want to remove: " << std::endl;
                std::cin >> key;
                removeNode(key);
                printList();
                break;
            case 3:
                printList();
                break;
            case 4:
                std::cout << "\nBye Bye" << std::endl;
                select_on = false;
                break;
        }
            
    }
}
