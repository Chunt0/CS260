/* Christopher Hunt
 * CS260
 * node.h
 */

#include <string>
#include <iostream>

struct Node{
    std::string key;
    int value;
    Node* next = nullptr;
};
