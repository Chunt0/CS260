/* Christopher Hunt
 * CS260
 * b_node.cpp
 */

#include "bin_tree.h"

Btree::Btree(){
    value = 0;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}

Btree::Btree(int value){
    value = value;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}

Btree::~Btree(){
}


Btree* Btree::insertNode(Btree* root, int value){
    return root;
}

Btree* Btree::removeNode(Btree* root, int value){
    return root;
}

Btree* Btree::min(Btree* node){
    while(node->left){
        node = node->left;
    }
    return node;
}

Btree* Btree::max(Node* node){
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}

Btree* Btree::successor(Btree* node){
}

Btree* Btree::predecessor(Btree* node){
}

void Btree::printTreeSmall(Btree* node){
    if(!node){
        return;
    }
    else{
        printTreeSmall(node->left);
        std::cout << "Value: " << node->value << std::endl;
        printTreeSmall(node->right);
    }
}


void Btree::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    while(select_on){
        std::cout << "\n1. Insert.\n2. Remove.\n3. Print list.\n4. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter integer value to store: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            insertNode(value);
            printTreeSmall(m_root);
            break;
            
            case 2:
            std::cout << "Enter integer value to remove: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            removeNode(value);
            printTreeSmall(m_root);
            break;

            case 3:
            printTreeSmall(m_root);
            break;

            case 4:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
            break;
        }    
    }
}
