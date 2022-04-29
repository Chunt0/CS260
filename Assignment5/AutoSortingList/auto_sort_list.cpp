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
    

}

void AutoSortList::remove_node(int index){

}

void AutoSortList::print_list(){

}

void AutoSortList::menu(){

}
