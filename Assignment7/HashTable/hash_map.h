/* Christopher Hunt
 * CS260
 * hash_map.h
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "list.h"


class HashMap{
    private:
        // Attributes
        static const int capacity = 13;
        List map[capacity];

        // Private Methods
        int hashByDiv(int key);

    public:
        // Constructor and Destructor
        HashMap();
        ~HashMap();

        // Public Methods
        void add(char* key, int value);
        void remove(char* key);
        int search(char* key);
        void printTable();
        void menu();
};

#endif
