/* Christopher Hunt
 * CS260
 * b_node.cpp
 */

#include "bin_tree.h"

Btree::Btree(){
    m_root = nullptr;
}

Btree::~Btree(){
}


Node* Btree::insertNode(Node* root, Node* parent, int value){
    if(!root){
        Node* new_node = new Node;
        new_node->value = value;
        new_node->parent = parent;
        root = new_node;
    }
    else{
        if(value <= root->value){
            parent = root;
            root->left = insertNode(root->left, root, value);
        }
        else{
            parent = root;
            root->right = insertNode(root->right, root, value);
        }
    }
    return root;
}

Node* Btree::removeNode(Node* root, int value){
    if(!root){
        std::cout << "Tree is empty" << std::endl;
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

Node* Btree::successor(Node* node){
    int value = 0;
    if(node->right != nullptr){
        node = min(node->right);
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value <= node->parent->value){
        node = node->parent;
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value > node->parent->value){
        value = node->value;
        node = node->parent;
        while(node != nullptr && value > node->value){
            node = node->parent;
        }
    }
    else{
        node = nullptr;
    }
    return node;
}

Node* Btree::predecessor(Node* node){
    if(node->left != nullptr){
        node = max(node->left);
    }
    else if(node->left == nullptr && node->parent != nullptr && node->value >= node->parent->value){
        node = node->parent;
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value < node->parent->value){
        int value;
        value = node->value;
        node = node->parent;
        while(node != nullptr && value < node->value){
            node = node->parent;
        }
    }
    else{
        node = nullptr;
    }
    return node;
}

void Btree::printTreeSmall(Node* node){
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
    Node* temp {nullptr};
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
            if(!m_root){m_root = insertNode(m_root, temp, value);}
            else{insertNode(m_root, temp, value);}
            printTreeSmall(m_root);
            temp = nullptr;
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
