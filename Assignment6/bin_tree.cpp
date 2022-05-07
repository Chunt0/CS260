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
    int value;
    if(m_root != nullptr){
        current = min(m_root);
        while(current != nullptr){
            if(!current->left && !current->right){
            deletePtr = current;
            current = successor(deletePtr);
            delete deletePtr;
            }
            else{
                deletePtr = successor(current);
                current->value = deletePtr->value;
                delete deletePtr;
            }
        }
    }
}


void Btree::insertNode(int value){
    Node* new_node = new Node;
    Node* current = nullptr;
    Node* parent = nullptr;

    new_node->value = value;
    
    if(m_root == nullptr){
        new_node->parent = parent;
        m_root = new_node;
    }
    else{
        current = m_root;
        parent = m_root->parent;

        while(true){
            parent = current;
            if(value <= parent->value){
                current = current->left;
                if(current == nullptr){
                    new_node->parent = parent;
                    parent->left = new_node;
                    return;
                }
            }
            else{
                current = current->right;
                if(current == nullptr){
                    new_node->parent = parent;
                    parent->right = new_node;
                    return;
                }
            }
        }
            
    }
}

void Btree::removeNode(int value){
    Node* deletePtr = nullptr;
    Node* current = nullptr;
    if(m_root != nullptr){
        current = m_root;
        while(true){
            if(current->value == value){
                deletePtr = successor(current);
                current->value = deletePtr->value;
                delete deletePtr;
                return;
            }
            else if(value < current->value){
                current = current->left;
            }
            else if(value > current->value){
                current = current->right;
            }
        }
    }
    else{
        std::cout << "Value is not in tree or tree is empty" << std::endl;
    }
}

Node* Btree::min(Node* node){
    while(node->left){
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
