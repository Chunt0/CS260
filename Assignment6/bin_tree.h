/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "bin_node.h"

class Btree{
    private:
        int m_value;
        Node* m_root;
        Node* min(Node* node);
        Node* max(Node* node);
        Node* successor(Node* node);
        Node* predecessor(Node* node); 
        void printTreeSmall(Node* node);


    public:
        Btree();
        ~Btree();
        void insertNode(int value);
        void removeNode(int value);
        void menu();
};
