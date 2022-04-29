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
        int m_size;
        
        // Getters
        int get_position(int value);
        int get_value(int index);

    public:
        // Constructor and Destructor
        AutoSortList();
        ~AutoSortList();

        // Methods
        void add_node(int value); // Auto Sort algorithm lives here ^_^
        void remove_node(int index);
        void print_list();
        void menu();


};


#endif
