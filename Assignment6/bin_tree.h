/* Christopher Hunt
 * CS260
 * b_tree.h
 */
#include "bin_node.h"

class Btree{
    private:
        // Attributes
        int value;
        Btree* left;
        Btree* right;
        Btree* parent;
        
        // Private Methods
        Btree* min(Btree* node);
        Btree* max(Btree* node);
        Btree* successor(Btree* node);
        Btree* predecessor(Btree* node); 


    public:
        // Constructor and Destructor
        Btree();
        Btree(int value);
        ~Btree();

        // Public Methods
        Btree* insertNode(Btree* root, int value);
        Btree* removeNode(Btree* root, int value);
        void printTreeSmall(Btree* node);
        void menu();
};
