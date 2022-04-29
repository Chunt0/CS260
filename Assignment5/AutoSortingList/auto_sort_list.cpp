/* Christopher Hunt
 * CS260
 * auto_sort_list.cpp
 */

#include "auto_sort_list.h"

AutoSortList::AutoSortList(){
    m_head = nullptr;
}

AutoSortList::~AutoSortList(){
    Node* deletePtr;
    while(m_head != nullptr){
        deletePtr = m_head;
        m_head = m_head->next;
        delete deletePtr;
    }
}

int AutoSortList::get_size(){
    return -1;
}

int AutoSortList::get_position(int value){
    return -1;
}

int AutoSortList::get_value(int index){
    return -1;
}

void AutoSortList::add_node(int value){

}

void AutoSortList::remove_node(int index){

}

void AutoSortList::print_list(){

}

void AutoSortList::menu(){

}
