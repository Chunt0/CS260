/* Christopher Hunt
 * CS260
 * node.h
 */

#include <string>
#include <iostream>

struct Node{
    std::string key;
    int value; // Each node stores a pair of values, index 0 is the key, index 1 is the value
    Node* next = nullptr;
};
