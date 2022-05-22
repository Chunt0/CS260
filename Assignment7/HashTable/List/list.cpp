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
void List::addNode(int key, int value){
    Node* new_node = new Node;
    Node* current;
    Node* temp;
    
    new_node->value[0] = key;
    new_node->value[1] = value;

    if(m_head != nullptr){
        // If the value being added is smaller than head
        if(key <= m_head->value[0]){
            temp = m_head;
            m_head = new_node;
            m_head->next = temp;
        }
        // If the value is larger than head
        else if(key > m_head->value[0]){
            current = m_head;
            temp = current;
            while(current->next != nullptr && value > current->value[0]){
                temp = current;
                current = current->next;
            }
            // If the value is larger than the largest value in the list
            if(current->next == nullptr && value > current->value[0]){
                current->next = new_node;
            }
            // If value fits in between the largest and smallest of the list
            else if(value <= current->value[0]){
                temp->next = new_node;
                new_node->next = current;
            }
        }
        m_size++;
    }
    else{
        m_head = new_node;
        m_size++;
    }
}



/* NEED TO FIX FOR HASH MAP!!!!!
 * Function: removeNode(int index)
 * Description: Removes node at given index.
 * Analysis: O(n)
 */
void List::removeNode(int key){
    Node* deletePtr;
    Node* current;
    Node* temp;
    if(m_head != nullptr){
        // If index is the first element of the list
        if(key == m_head->value[0]){
            deletePtr = m_head;
            m_head = m_head->next;
            delete deletePtr;
            m_size--;
        }
        else{
            current = m_head;
            for(int i = 0; i < m_size; i++){
                temp = current;
                current = current->next;
            }
            // If the index searched for is in the last position
            if(current->next == nullptr){
                deletePtr = current;
                temp->next = nullptr;
                delete deletePtr;
                m_size--;
            }
            // Else if 
            else if(current->next != nullptr && current != nullptr){
                deletePtr = current;
                temp->next = current->next;
                delete deletePtr;
                m_size--;
            }
        }

    }

    else{
        std::cout << "List is empty." << std::endl;
    }
}

/* Function: print_list()
 * Description: Prints list to screen, index and value.
 * Analysis: O(n)
 */
void List::printList(){
    Node* current = m_head;
    int index = 0;
    while(current != nullptr){
        std::cout << "Index: " << index << "## Value: " << current->value << std::endl;
        current = current->next;
        index++;
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
    int key;
    while(select_on){
        std::cout << "\n1. Add Node\n2. Remove Node\n3. Print List\n4. Exit" << std::endl;
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "\nEnter a positive integer: " << std::endl;
                std::cin >> value;
                addNode(key, value);
                printList();
                break;
            case 2:
                std::cout << "\nEnter index of the value you want to remove: " << std::endl;
                std::cin >> index;
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
