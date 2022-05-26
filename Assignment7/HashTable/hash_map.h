/* Christopher Hunt
 * CS260
 * hash_map.h
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "list.h"
#include <string>
#include <vector>


class HashMap{
    private:
        // Attributes
        List* map[13];
        int capacity;
        int size;

        // Private Methods
        int hashByDiv(int key);

    public:
        // Constructor and Destructor
        HashMap();
        ~HashMap();

        // Public Methods
        void add(char key[], int value);
        void remove(char key[]);
        int search(char key[]);
        void menu();
};

#endif
