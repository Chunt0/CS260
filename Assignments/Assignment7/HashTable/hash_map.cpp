/* Christopher Hunt
 * CS260
 * hash_map.cpp
 */

#include "./hash_map.h"

HashMap::HashMap(){} // Nothing to construct, Hashmap is already constructed in header file 

HashMap::~HashMap(){} // Nothing to destructor, all dynamic memory allocation happens in the linked lists

////////////////////////////////////////////////////////////////////////////////

/* 
 * Function: hashByDiv(int key)
 * Description: Takes an integer-ified key and performs the hash function
 * Analysis: O(1)
 */
int HashMap::hashByDiv(int key){
    return key % capacity;
}

////////////////////////////////////////////////////////////////////////////////

/* 
 * Function: add(std::string key, int value)
 * Description: Takes a key string and an integer value, hashes the key, finds an 
 *      index, adds key/value to linked list stored at corresponding index.
 * Analysis: O(k) where k is the number of key/value pairs stored in that indexes linked list.
 */
void HashMap::add(std::string key, int value){
    int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i]; // Turn the ANSCII char into the corresponding int value
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);
    
    // Index to the linked list and then add key and value to list
    map[hashed_key].addNode(key, value);
}

////////////////////////////////////////////////////////////////////////////////

/* 
 * Function: remove(std::string key)
 * Description: Takes a key string, hashes the key, finds an index, removes key/value
 *      in corresponding linked list.
 * Analysis: O(k) where k is the number of key/value pairs stored in that indexes linked list.
 */
void HashMap::remove(std::string key){
    int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i];
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);
    
    // Index to linked list that would contain the key/value pair and remove if found.
    map[hashed_key].removeNode(key);
}

////////////////////////////////////////////////////////////////////////////////

/* 
 * Function: search(std:: string key)
 * Description: Searches hash table to find specified key, returns value associated.
 * Analysis: O(k) where k is the number of nodes in the linked list stored in the hashtable array.
 */
int HashMap::search(std::string key){
     int hashed_key = 0;

    // Convert 3 char key into an integer, then hash that value
    for (int i = 0; i < 3; i++){
        hashed_key = hashed_key + (int)key[i];
    }

    // hashed_key will be an index between 0 and capacity-1
    hashed_key = hashByDiv(hashed_key);
    
    // Index to linked list which may contain the key/value pair and return value if found.
    int value = map[hashed_key].returnValue(key);

    return value;
}

////////////////////////////////////////////////////////////////////////////////

/*
 * Function: printTable()
 * Description: Prints every key/value pair stored in the hash table
 * Analysis: O(n)
 */
void HashMap::printTable(){
    for(int i = 0; i < capacity; i++){
        map[i].printList();
    }
}

////////////////////////////////////////////////////////////////////////////////

/*
 * Function: menu()
 * Description: User interface to test hashmap
 */
void HashMap::menu(){
    bool select_on {true};
    int selection = 0;
    int value = 0;
    std::string key;
    while(select_on){
        std::cout << "\n1. Add key and value\n2. Remove key and value\n3. Search for key, return value\n4. Print table\n5. Exit\n" << std::endl;
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "Enter a key: ";
                std::cin >> key;
                std::cout << "Enter a positive integer value: ";
                std::cin >> value;
                if(value >= 0){
                    add(key, value);
                    printTable();
                }
                else{
                    std::cout << "Value must be a positive integer." << std::endl;
                }
                break;

            case 2:
                std::cout << "Enter key to remove: ";
                std::cin >> key;
                remove(key);
                printTable();
                break;

            case 3:
                std::cout << "Enter key to retrieve value: ";
                std::cin >> key;
                value = search(key);
                if(value >= 0){
                    std::cout << "Key: " << key << " | Value: " << value << std::endl;
                }
                else{
                    std::cout << "Key not found." << std::endl;
                }
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
