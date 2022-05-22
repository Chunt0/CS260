/* Christopher Hunt
 * CS260
 * hash_map.h
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "./List/list.h"
#include <vector>


class HashMap{
    private:
        // Attributes
        std::vector<List*> map; // Creates a vector which contains linked lists which contain key, value pairs.
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
        int get_capacity();
        float get_load();
        void add(int new_value);
        void remove(int old_value);
        int search(int candidate_value);
};

#endif
