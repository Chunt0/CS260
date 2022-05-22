/* Christopher Hunt
 * CS260
 * hash_map.cpp
 */

#include "./hash_map.h"

HashMap::HashMap(){
    capacity = 13; // Prime
    size = 0;
    map.reserve(capacity); // .reserve() sets the vectors capacity
}

HashMap::~HashMap(){
}

int HashMap::get_capacity(){
    return capacity;
}

float HashMap::get_load(){
    return size / capacity;
}

void add(int new_value);
