/*
 * Christopher Hunt
 * CS260
 */
#ifndef DYNARR_SORT_H
#define DYNARR_SORT_H

#include <iostream>

class DynArr{
    private:
        // Attributes
        int *m_array;
        int m_size;
        int m_capacity;

    public:
        // Constructor Destructor
        DynArr();
        ~DynArr();

        // Methods
        void appendList(int value);
        void removeValue(int value);
        void insertValue(int value);
        void popValue(int index);
        void clearList();

};

#endif
