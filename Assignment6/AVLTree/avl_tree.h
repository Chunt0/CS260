/* Christopher Hunt
 * CS260
 * avl_tree.h
 */
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_node.h"

class Btree{
    private:
        // Attributes
        Node* m_root;

        // Private Methods
        Node* min(Node* node);
        Node* max(Node* node);
        void postOrderDelete(Node* root);
        void printTreeInOrder(Node* node);
        void printTreePreOrder(Node* node);
        void printTreePostOrder(Node* node);


    public:
        // Constructor and Destructor
        Btree();
        ~Btree();

        // Public Methods
        Node* insertNode(Node* root, int value);
        Node* removeNode(Node* root, int value);
        void menu();
};

#endif
