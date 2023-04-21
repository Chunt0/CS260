/* Christopher Hunt
 * CS260
 * skip_list.h
 */

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#pragma once

#include "skip_node.h"

class SkipList{
    private:
        SkipNode** m_sentinel; 

    public:
        // Constructor and Destructor
        SkipList(int max_height);
        ~SkipList();
        
        // Public Methods
        void insert(int value); // Auto-sorting
        void remove(int value);
        void print();
};

#endif
