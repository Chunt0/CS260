/* Christopher Hunt
 * CS260
 */

#include "linklist_sort.h"

LinkList::LinkList(){
    m_head = nullptr;
    m_size = 0;
}

LinkList::~LinkList(){
    Node* delete_ptr;
    while(m_head != nullptr){
        delete_ptr = m_head;
        m_head = m_head->next;
        delete delete_ptr;
    }
}

void LinkList::addValue(int value){
    Node* n = new Node;
    Node* current = m_head;

    n->value = value;
    
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

void LinkList::removeValue(int value){
    Node* delete_ptr;
    Node* current = m_head;
    Node* temp = m_head;
    if(m_head != nullptr)
        while(current->value != value && current != nullptr){
            temp = current;
            current = current->next;
        }
        if (current->value == value && current == m_head){
            delete_ptr = current;
            current = current->next;
            m_head = current;
            delete delete_ptr;
            m_size--;
            }
        else if (current->value == value && current != m_head){
            delete_ptr = current;
            current = current->next;
            temp->next = current;
            delete delete_ptr;
            m_size--;
        }
    else{
        std::cout << "The list is empty" << std::endl;
    }
}
