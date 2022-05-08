/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "bin_node.h"

class Btree{
    private:
        // Attributes
        Node* m_root;

        // Private Methods
        Node* min(Node* node);
        Node* max(Node* node);
        Node* successor(Node* node);
        Node* predecessor(Node* node); 
        void printTreeSmall(Node* node);


    public:
        // Constructor and Destructor
        Btree();
        ~Btree();

        // Public Methods
        Node* insertNode(Node* root, Node* parent, int value);
        Node* removeNode(Node* root, int value);
        void menu();
};
