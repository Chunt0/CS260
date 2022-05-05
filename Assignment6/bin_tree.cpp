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

void Btree::printTree(){
    Node* current_L = nullptr;
    Node* current_R = nullptr;
    if(m_root != nullptr){
        std::cout << "Value: " << m_root->value << std::endl;
        current_L = m_root->left;
        current_R = m_root->right;
        while(current_L != nullptr || current_R != nullptr){
            if(current_L != nullptr){
                std::cout << "Value: " << current_L->value << std::endl;
                current_L = current_L->left;
            }
            if(current_R != nullptr){
                std::cout << "Value: " << current_R->value << std::endl;
                current_R = current_R->right;
            }

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
        }    
    }
}
