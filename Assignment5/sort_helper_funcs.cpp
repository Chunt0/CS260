/* Christopher Hunt
 * CS260
 * Sorting Helper functions
 */

#include <iostream>
#include "node.h"

void swap(Node *left, Node *right){
    int lval, rval;
    lval = left->value;
    rval = right->value;

    left->value = rval;
    right->value = lval;
}

Node* findNodeBefore(Node *root, Node *new_value_node){
    Node* current = root;
    if(current == nullptr){

    }
    while(current->next != nullptr && current->next->value < new_value_node->value){
        current = current->next;
    }
    
    return new_value_node;
}


int main(){
    Node* left = new Node{1, nullptr};
    Node* right = new Node{100, nullptr};

    std::cout << "Left value: " << left->value << " # Right value: " << right->value << std::endl;
    swap(left,right);
    std::cout << "Left value: " << left->value << " # Right value: " << right->value << std::endl;
    
    delete left;
    delete right;

    return 0;
}
