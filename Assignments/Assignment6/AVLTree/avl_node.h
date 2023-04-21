/* Christopher Hunt
 * CS260
 * avl_node.h
 */
#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <iostream>

struct Node{
    int value = 0;
    int height = 0;
    Node* left = nullptr;
    Node* right = nullptr;

};

#endif
