/* Christopher Hunt
 * CS260
 * auto_sort_list.cpp
 */

#include "list.h"
#include <cstring>

/* Constructor: AutoSortList()
 * Description: Initializes list.
 * Analysis: O(1)
 */
List::List(){
    m_head = nullptr;
    m_size = 0;
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
void List::addNode(char* key, int value){
    Node* new_node = new Node;
    Node* current;
    
    new_node->key = key;
    new_node->value = value;

    if(m_head != nullptr){
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new_node;
    }
    else{
        m_head = new_node;
    }
    m_size++;
}



/*
 * Function: removeNode(int index)
 * Description: Removes node at given index.
 * Analysis: O(n)
 */
void List::removeNode(char key[]){
    Node* deletePtr;
    Node* current;
    Node* temp;
    if(m_head != nullptr){
        // If index is the first element of the list
        if(strcmp(m_head->key, key)){
            deletePtr = m_head;
            m_head = m_head->next;
            delete deletePtr;
        }
        else{
            current = m_head;
            for(int i = 0; i < m_size; i++){
                temp = current;
                current = current->next;
            }
            // If the index searched for is in the last position
            if(current->next == nullptr && strcmp(current->key, key)){
                deletePtr = current;
                temp->next = nullptr;
                delete deletePtr;
            }
            // Else if 
            else if(current->next != nullptr && current != nullptr && strcmp(current->key, key)){
                deletePtr = current;
                temp->next = current->next;
                delete deletePtr;
            }
        }
        m_size--;
    }

    else{
        std::cout << "List is empty." << std::endl;
    }
}

int List::returnValue(char key[]){
    Node* current = m_head;
    int keys_value{-1};
    while(current != nullptr){
        if (strcmp(current->key, key)){
            keys_value = current->value;
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
        std::cout << "Value: " << current->value << std::endl;
        current = current->next;
    }

}

/* Function: menu()
 * Description: Allows user to access class methods and exit cleanly.
 * Analysis: O(1)
 */
void List::menu(){
    bool select_on = true;
    int value;
    int index;
    int selection;
    char key[3];
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
