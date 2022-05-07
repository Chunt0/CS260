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
    Node* current = nullptr;
    if(m_root != nullptr){
        current = min(m_root);
        while(current != nullptr){
            deletePtr = current;
            current = successor(current);
            delete deletePtr;
        }
    }
}

void Btree::insertNode(Node* node, Node* parent, int value){
    if(m_root == nullptr){
        Node* new_node = new Node;
        new_node->value = value;
        new_node->parent = parent;
        m_root = new_node;
    }
    else if(node == nullptr){
        Node* new_node = new Node;
        new_node->value = value;
        new_node->parent = parent;
        node = new_node;
    }
    else if(node != nullptr && value <= node->value){
        parent = node;
        insertNode(node->left, parent, value);
    }
    else if(node != nullptr && value > node->value){
        parent = node;
        insertNode(node->right, parent, value);
    }
}


void Btree::removeNode(Node* node, int value){
    Node* deletePtr;
    Node* current = node;
    if(current != nullptr){
        if(current->value == value){
            deletePtr = current;
            deletePtr = successor(deletePtr);
            current->value = deletePtr->value;
            delete deletePtr;
        }
        else if(current->value > value){
            current = current->left;
            removeNode(current, value);
        }
        else if(current->value < value){
            current = current->right;
            removeNode(current, value);
        }
    }
    else{
        std::cout << "Value is not in tree or tree is empty" << std::endl;
    }
}

Node* Btree::min(Node* node){
    if(node->left != nullptr){
        while(node->left != nullptr){
            node = node->left;
        }
    }

    return node;
}

Node* Btree::max(Node* node){
    if(node->right != nullptr){
        while(node->right != nullptr){
            node = node->right;
        }
    }
    return node;
}

Node* Btree::successor(Node* node){
    if(node->right != nullptr){
        node = node->right;
        node = min(node);
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value <= node->parent->value){
        node = node->parent;
    }
    else if(node->right == nullptr && node->parent != nullptr && node->value > node->parent->value){
        int value = node->value;
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
        node = node->left;
        node = max(node);
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

void Btree::printTree(){
    Node* current;
    if(m_root != nullptr){
        current = min(m_root);
        while(current != nullptr){
            std::cout << "Value: " << current->value << std::endl;
            current = successor(current);
        }
    }
    else{
        std::cout << "Tree is empty!" << std::endl;
    }
}

void Btree::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    Node* temp_parent {nullptr};
    while(select_on){
        std::cout << "\n1. Insert.\n2. Remove.\n3. Print list.\n4. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter integer value to store: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            insertNode(m_root, temp_parent, value);
            printTree();
            break;
            
            case 2:
            std::cout << "Enter integer value to remove: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            removeNode(m_root, value);
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
