/* Christopher Hunt
 * CS260
 * hash_map.cpp
 */

#include "./hash_map.h"

HashMap::HashMap(){}

HashMap::~HashMap(){}

int HashMap::hashByDiv(int key){
    return key % capacity;
}

void HashMap::add(char* key, int value){
    int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i]; // Turn the ANSCII char into the corresponding int value
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);

    map[hashed_key].addNode(key, value);
}

void HashMap::remove(char* key){
    int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i];
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);

    map[hashed_key].removeNode(key);
}

int HashMap::search(char* key){
     int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i];
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);
   
    int value = map[hashed_key].returnValue(key);

    return value;
}

void HashMap::printTable(){
    for(int i = 0; i < capacity; i++){
        map[i].printList();
    }
}

void HashMap::menu(){
    bool select_on {true};
    int selection = 0;
    int value = 0;
    char key[3];
    while(select_on){
        std::cout << "\n1. Add key and value\n2. Remove key and value\n3. Search for key, return value\n4. Print table\n5. Exit\n" << std::endl;
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "Enter a 3-letter key: ";
                std::cin >> key;
                std::cout << "Enter a positive integer value: ";
                std::cin >> value;
                add(key, value);
                printTable();
                break;

            case 2:
                std::cout << "Enter 3-letter key to remove: ";
                std::cin >> key;
                remove(key);
                printTable();
                break;

            case 3:
                std::cout << "Enter 3-letter key: ";
                std::cin >> key;
                value = search(key);
                std::cout << "Key: " << key << " | Value: " << value << std::endl;
                break;

            case 4:
                printTable();
                break;

            case 5:
                select_on = false;
                std::cout << "Bye bye" << std::endl;
                break;
        }         
    }
}
