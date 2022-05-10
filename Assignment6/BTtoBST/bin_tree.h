/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "bin_node.h"

class Btree{
    private:
        // Attributes
        int m_size;
        Node* m_root;

        // Private Methods
        Node* min(Node* node);
        Node* max(Node* node);
        void postOrderDelete(Node* root);
        void printTreeInOrder(Node* node);
        void printTreePreOrder(Node* node);
        void printTreePostOrder(Node* node);
        void duplicateToArray(Node* root, int* inorder, int* index);
        void arrayToBST(Node* root, int* inorder, int* index);


    public:
        // Constructor and Destructor
        Btree();
        ~Btree();

        // Public Methods
        Node* insertNode(Node* root, int value);
        Node* removeNode(Node* root, int value);
        Node* BTtoBST(Node* root);
        void menu();
};
