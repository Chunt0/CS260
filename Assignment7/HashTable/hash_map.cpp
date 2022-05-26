/* Christopher Hunt
 * CS260
 * hash_map.cpp
 */

#include "./hash_map.h"

HashMap::HashMap(){
    capacity = 13; // Prime
    size = 0;
    for(int i = 0; i < capacity; i++){
        map[i] = nullptr;
    }
}

HashMap::~HashMap(){
}

int HashMap::getCapacity(){
    return capacity;
}

float HashMap::getLoad(){
    return size / capacity;
}

int HashMap::hashByDiv(int key){
    return key % capacity;
}

void HashMap::add(char key[], int value){
    int hashed_key;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < sizeof(key[0]); i++){
        hashed_key = hashed_key + (int)key[i];
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);
    
    // If the index in the map is null, create a new linked list and have that
    // index point to that list.
    if(map[hashed_key] == nullptr){
        List* list = new List;
        list->addNode(key, value);
        map[hashed_key] = list;
    }
    else{
        map[hashed_key]->addNode(key, value);
    }
}

void HashMap::remove(char key[]){

}

int HashMap::search(char key[]){
    int value;

    return value;
}
