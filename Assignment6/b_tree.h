/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "b_node.h"

class Btree{
    private:
        int m_size;
        Node* m_root;


    public:
        Btree();
        ~Btree();
        void insertNode(int value);
        void removeNode(int value);
        void printTree();
        void menu();
};
