/* Christopher Hunt
 * CS260
 * b_node.cpp
 */

#include "bin_tree.h"

Btree::Btree(){
    m_root = nullptr;
}

Btree::~Btree(){
    postOrderDelete(m_root);
}

void Btree::postOrderDelete(Node* root){
    if(!root){
        return;
    }
    postOrderDelete(root->left);
    postOrderDelete(root->right);
    delete root;
}

Node* Btree::insertNode(Node* root, int value){
    if(!root){
        Node* new_node = new Node;
        new_node->value = value;
        root = new_node;
    }
    else{
        if(value <= root->value){
            root->left = insertNode(root->left, value);
        }
        else{
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

Node* Btree::removeNode(Node* root, int value){
    if(!root){
        return root;
    }
    else{
        if(value < root->value){
            root->left = removeNode(root->left, value);
        }
        else if(value > root->value){
            root->right = removeNode(root->right, value);
        }
        else{
            // Node has no child, just delete node.
            if(!root->left && !root->right){
                delete root;
                return nullptr; 
            }

            // Has right child
            else if(!root->left){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            // Has left child
            else if(!root->right){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            // Has both left and right children
            Node* temp = min(root->right); // Move right and find successor
            root->value = temp->value;
            root->right = removeNode(root->right, temp->value);
        }
    }
    return root;
}

Node* Btree::min(Node* node){
    Node* current = node;
    while(current && current->left){
        current = current->left;
    }
    return current;
}

Node* Btree::max(Node* node){
    Node* current = node;
    while(current && current->right){
        current = current->right;
    }
    return current;
}


void Btree::printTreeInOrder(Node* node){
    if(!node){
        return;
    }
    else{
        printTreeInOrder(node->left);
        std::cout << "Value: " << node->value << std::endl;
        printTreeInOrder(node->right);
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
            m_root = insertNode(m_root, value);
            printTreeSmall(m_root);
            break;
            
            case 2:
            std::cout << "Enter integer value to remove: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            m_root = removeNode(m_root, value);
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
