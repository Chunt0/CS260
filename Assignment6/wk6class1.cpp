/* Christopher Hunt
 * CS260
 * Binary Trees
 */

#include <iostream>

/*
 * BINARY TREE
 *
 * root node
 * internal nodes
 * leaf nodes
 *
 * n = number of elements in tree
 * depth = the longest chain from root to leaf
 *
 * left child/right child - each non-leaf node has at maximum 2 children
 *
 * BINARY SEARCH TREE
 * 
 * In a binary search tree there is an order to how the left and the right
 * children are selected.
 *
 * Ex. Left is < Root and Right is >= Root
 * 
 * Binary Node structure:
 * int value, counter of value?
 * Bnode* left, right
 *
 * When you want to remove the root, you must find the successor
 */


int main(int argc, char** argv){
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv[1]: " << argv[1] << std::endl;
    return 0;

}
