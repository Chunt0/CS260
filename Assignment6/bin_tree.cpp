/* Christopher Hunt
 * CS260
 * b_node.cpp
 */

#include "bin_tree.h"

Btree::Btree(){
    m_size = 0;
    m_root = nullptr;
}

Btree::~Btree(){
    Node* deletePtr = nullptr;
    while(m_root != nullptr){
        deletePtr = m_root;
    }
}

Node* Btree::insertNode(Node* node, Node* temp, int value){
    Node* new_node = new Node;
    new_node->value = value;
    if(node == nullptr){
        new_node->parent = temp;
        node = new_node;
    }
    else if(new_node->value <= node->value){
        temp = node;
        node->left = insertNode(node->left, temp, value);
    }
    else{
        temp = node;
        node->right = insertNode(node->right, temp, value);
    }
    return node;
}


void Btree::removeNode(int value){

}

Node* Btree::min(Node* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

Node* Btree::max(Node* node){
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}

Node* Btree::successor(Node* node){
    Node* current;
    Node* successor;
    if(node->right != nullptr){
        current = node->right;
        successor = min(current);
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value < node->parent->value){
        successor = node->parent;
    }
    else{
        successor = nullptr;
    }
    return successor;
}

Node* Btree::predecessor(Node* node){
    Node* current;
    Node* predecessor;
    if(node->left != nullptr){
        current = node->left;
        predecessor = max(current);
    }
    else if(node->left == nullptr){}
    return predecessor;
}

void Btree::printTree(){
    Node* current;
    if(m_root != nullptr){
        current = min(m_root);
        while(current != nullptr){
            std::cout << "Value: " << current->value << std::endl;
            current = successor(current);
        }
    }
}

void Btree::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    Node* temp = nullptr;
    while(select_on){
        std::cout << "\n1. Insert.\n2. Remove.\n3. Print list.\n4. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter integer value to store: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            m_root = insertNode(m_root, temp, value);
            printTree();
            break;
            
            case 2:
            std::cout << "Enter integer value to remove: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            removeNode(value);
            printTree();
            break;

            case 3:
            printTree();
            break;

            case 4:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
            break;
        }    
    }
}
