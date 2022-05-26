/* Christopher Hunt
 * CS260
 * hash_map.h
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "./List/list.h"
#include <string>
#include <vector>


class HashMap{
    private:
        // Attributes
        List* map[13]; // Creates a vector which contains linked lists which contain key, value pairs.
        int capacity;
        int size;

        // Private Methods
        int hashByDiv(int key);
        int hashByMul(int key);


    public:
        // Constructor and Destructor
        HashMap();
        ~HashMap();

        // Public Methods
        int getCapacity();
        float getLoad();
        void add(char key[], int value);
        void remove(char key[]);
        int search(char key[]);
};

#endif
