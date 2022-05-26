/* Christopher Hunt
 * CS260
 * node.h
 */

#include <string>
#include <iostream>

struct Node{
    char* key;
    int value;
    Node* next = nullptr;
};
