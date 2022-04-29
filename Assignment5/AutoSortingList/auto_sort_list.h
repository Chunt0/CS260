/* Christopher Hunt
 * CS260
 * auto_sort.h
 */

#ifndef AUTO_SORT_LIST_H
#define AUTO_SORT_LIST_H

#include<iostream>
#include "node.h"

class AutoSortList{
    private:
        // Attributes
        Node* m_head;
        
        // Getters
        int get_size();
        int get_position(int value);
        int get_value(int index);

    public:
        // Methods
        void addNode(int value); // Auto Sort algorithm lives here ^_^
        void removeNode(int index);
        void printList();
        void menu();


};


#endif
