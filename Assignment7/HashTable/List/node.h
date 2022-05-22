/* Christopher Hunt
 * CS260
 * node.h
 */



struct Node{
    int value[2]; // Each node stores a pair of values, index 0 is the key, index 1 is the value
    Node* next = nullptr;
};
