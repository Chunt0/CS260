/* Christopher Hunt
 * CS260
 * auto_sort_list.cpp
 */

#include "auto_sort_list.h"

AutoSortList::AutoSortList(){
    m_head = nullptr;
    m_size = 0;
}

AutoSortList::~AutoSortList(){
    Node* deletePtr;
    while(m_head != nullptr){
        deletePtr = m_head;
        m_head = m_head->next;
        delete deletePtr;
    }
}

int AutoSortList::get_position(int value){
    Node* current = m_head;
    int position = -1;
    if(current != nullptr){
        position = 0;
        while(current != nullptr && current->value != value){
            position++;
            current = current->next;
        }
    } 
    return position;
}

int AutoSortList::get_value(int index){
    Node* current = m_head;
    int value = -1;
    if(current != nullptr)
        for(int i = 0; i <= index; i++)
            current = current->next;
        value = current->value;
    return value;
}

void AutoSortList::add_node(int value){
    Node* new_node = new Node;
    Node* current;
    Node* temp;

    new_node->value = value;

    if(m_head != nullptr){
        // If the value being added is smaller than head
        if(value <= m_head->value){
            temp = m_head;
            m_head = new_node;
            m_head->next = temp;
        }
        // If the value is larger than head
        else if(value > m_head->value){
            current = m_head;
            temp = current;
            while(current->next != nullptr && value > current->value){
                temp = current;
                current = current->next;
            }
            // If the value is larger than the largest value in the list
            if(current->next == nullptr && value > current->value){
                current->next = new_node;
            }
            // If value fits in between the largest and smallest of the list
            else if(value <= current->value){
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

void AutoSortList::remove_node(int index){
    Node* deletePtr;
    Node* current;
    Node* temp;
    if(m_head != nullptr && index < m_size){
        // If index is the first element of the list
        if(index == 0){
            deletePtr = m_head;
            m_head = m_head->next;
            delete deletePtr;
            m_size--;
        }
        else{
            current = m_head;
            for(int i = 0; i < index; i++){
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

void AutoSortList::print_list(){
    Node* current = m_head;
    int index = 0;
    while(current != nullptr){
        std::cout << "Index: " << index << "## Value: " << current->value << std::endl;
        current = current->next;
        index++;
    }

}

void AutoSortList::menu(){
    bool select_on = true;
    int value;
    int index;
    int selection;
    while(select_on){
        std::cout << "1. Add Node\n2. Remove Node\n3. Print List\n4. Exit" << std::endl;
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "Enter a positive integer: " << std::endl;
                std::cin >> value;
                add_node(value);
                print_list();
                break;
            case 2:
                std::cout << "Enter index of the value you want to remove: " << std::endl;
                std::cin >> index;
                remove_node(index);
                print_list();
                break;
            case 3:
                print_list();
                break;
            case 4:
                std::cout << "Bye Bye" << std::endl;
                select_on = false;
                break;
        }
            
    }
}
