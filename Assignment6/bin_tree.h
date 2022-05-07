/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "bin_node.h"

class Btree{
    private:
        int m_size;
        Node* m_root;


    public:
        Btree();
        ~Btree();
        void insertNode(int value);
        void removeNode(int value);
        Node* min(Node* node);
        Node* max(Node* node);
        Node* successor(Node* node);
        Node* predecessor(Node* node); 
        void printTree();
        void menu();
};
