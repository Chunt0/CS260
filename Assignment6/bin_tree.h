
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
        Node* insertNode(Node* node, Node* temp, int value);
        void removeNode(int value);
        void printTree();
        void menu();
};
