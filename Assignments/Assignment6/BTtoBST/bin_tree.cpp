/* Christopher Hunt
 * CS260
 * b_node.cpp
 */

#include "bin_tree.h"

////////////////////////////////////////////////////////////////////////////////

/* Function: Btree()
 * Description: Default constructor. A Binary Tree is a data structure which only
 *     requires a Node pointer, called root.
 * Precondition: Must be called by driver program. Initializes a Btree object.
 * Postcondition: A Btree object is intiialized with it's m_root pointing to null. 
 * Analysis: O(1)
 */
Btree::Btree(){
    m_size = 0;
    m_root = nullptr;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: ~Btree()
 * Description: Destructor. Called when a Btree object goes out of scope.
 * Precondition: The Btree object must be created in a driver code.
 * Postcondition: Deletes all heap memory usage from the particular Btree object.
 * Analysis:O(n*h); n = number of nodes, h = height of tree
 */
Btree::~Btree(){
    postOrderDelete(m_root);
}

////////////////////////////////////////////////////////////////////////////////

/* Function: postOrderDelete()
 * Description: A recursive function that moves from the root node of a Btree to
 *     a leaf and then deletes that leaf, continues until all layers of the tree are deleted.
 * Precondition: A Btree object must exist.
 * Postcondition: All nodes in the tree are deleted, from the leaves to the root. 
 *     If root was null, function is returned, nothing done.
 * Analysis:O(n*h); n = number of nodes, h = height of tree
 */
void Btree::postOrderDelete(Node* root){
    if(!root){
        return;
    }
    postOrderDelete(root->left);
    postOrderDelete(root->right);
    delete root;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: insertNode(Node*, int)
 * Description: If root is null, node is created and becomes root. Else, the tree
 *     is traversed based on the rule if value <= key, move to left child; else if 
 *     value > key, move to right child. Once a nullptr is reached, new node is inserted.
 * Precondition: Btree must exist.
 * Postcondition: Btree aquires a new node of value int at an open child pointer 
 *     that satisfies the rule.
 * Analysis:O(h); h = height of tree
 */
Node* Btree::insertNode(Node* root, int value){
    if(!root){
        Node* new_node = new Node;
        new_node->value = value;
        root = new_node;
        m_size++;
    }
    else{
        if(value <= root->value){
            root->left = insertNode(root->left, value);
        }
        else{
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: removeNode(Node*, int)
 * Description: Searches the tree for an inputed value int, once found the node is
 *     removed. There are three potential conditions to resolve to delete a node. If
 *     the node has no children, the node has one child, or the node has two children.
 *     See code comments for details.
 * Precondition: Btree must exist, if there are nodes, these nodes can be deleted.
 * Postcondition: If value equals a key in the tree, that node will be deleted,
 *     otherwise there will be no change to the tree.
 * Analysis:O(h); h = heigt of tree
 */
Node* Btree::removeNode(Node* root, int value){
    if(!root){
        return root;
    }
    else{
        // Search for node which matches the inputed value, this is where recursion
        // is utilized. At the point the recursion is finished all the parents have 
        // been properly reconfigured to point towards the correct children. If the
        // value is not found the tree is unchanged
        if(value < root->value){
            root->left = removeNode(root->left, value);
        }
        else if(value > root->value){
            root->right = removeNode(root->right, value);
        }

        else{
            // Node has no child, just delete node.
            if(!root->left && !root->right){
                delete root;
                m_size--;
                return nullptr;
            }

            // Has right child, use temp to patch hole when deleting node
            else if(!root->left){
                Node* temp = root->right;
                delete root;
                m_size--;
                return temp;
            }

            // Has left child, use temp to patch hole when deleting node
            else if(!root->right){
                Node* temp = root->left;
                delete root;
                m_size--;
                return temp;
            }

            // Has both left and right children, enter recursion to eventually complete
            // the value swapping process
            Node* temp = min(root->right); // Move right and find successor
            root->value = temp->value;
            root->right = removeNode(root->right, temp->value);
        }
    }
    return root;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: BTtoBST(Node*)
 * Description:  
 * Precondition:
 * Postcondition:
 * Analysis:
 */
Node* Btree::BTtoBST(Node* root){
    int index = 0;
    int* inorder = new int[m_size];
    duplicateToArray(root, inorder, &index);
    
    index = 0;

    arrayToBST(root, inorder, &index);

    delete[] inorder;

    return  root;
    
}

////////////////////////////////////////////////////////////////////////////////

/* Function: duplicateToArray(Node*, int*, int*)
 * Description:  
 * Precondition:
 * Postcondition:
 * Analysis:
 */
void Btree::duplicateToArray(Node* root, int* inorder, int* index){
    if(!root){
        return;
    }
    else{
        duplicateToArray(root->left, inorder, index);
        
        inorder[*index] = root->value;
        (*index)++;

        duplicateToArray(root->left, inorder, index);
    } 
}

/////////////////////////////////////////////////////////////////////////////////

/* Function: arrayToBST(Node*, int*, int*)
 * Description:  
 * Precondition:
 * Postcondition:
 * Analysis:
 */
void Btree::arrayToBST(Node* root, int* inorder, int* index){
    if(!root){
        return;
    }
    else{
        arrayToBST(root->left, inorder, index);
        
        inorder[*index] = root->value;
        (*index)++;

        arrayToBST(root->right, inorder, index);
    } 
}


///////////////////////////////////////////////////////////////////////////////

/* Function: min(Node*)
 * Description: Finds the minimum value in a tree or subtree, depends on initial 
 *     input node.
 * Precondition: This is an internal function that is utilized in the removeNode()
 *     function, and perhaps others.
 * Postcondition: Returns the node pointer to the lowest value int in a tree or subtree.
 * Analysis:O(h); h= height of tree
 */
Node* Btree::min(Node* node){
    if(!node->left){
        return node;
    }
    else{
        node = min(node->left);
    }
    return node;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: max(Node*)
 * Description: Finds and returns the maximum value int in a tree or subtree
 *     depending on the intial input node.
 * Precondition: This is an internal function currently not utilized.
 * Postcondition: Returns node pointer to the largest value in a tree or subtree.
 * Analysis: O(h); h = height of tree
 */
Node* Btree::max(Node* node){
    if(!node->right){
        return node;
    }
    else{
        node = max(node->right);
    }
    return node;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: printTreeInOrder(Node*)
 * Description: Prints a Btree in order of smallest value int to largest value int.
 * Precondition: Btree must exist.
 * Postcondition: If Btree is null, returns null. Otherwise prints all values in tree
 *     from smallest to largest.
 * Analysis: O(h); h = height of tree
 */
void Btree::printTreeInOrder(Node* node){
    if(!node){
        return;
    }
    else{
        printTreeInOrder(node->left);
        std::cout << "Value: " << node->value << std::endl;
        printTreeInOrder(node->right);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: printTreePreOrder(Node*)
 * Description: Prints a Btree in pre-order.
 * Precondition: Btree must exist.
 * Postcondition: If Btree is null, returns null. Otherwise prints all values in tree
 *     pre-order.
 * Analysis: O(h); h = height of tree
 */
void Btree::printTreePreOrder(Node* node){
    if(!node){
        return;
    }
    else{
        std::cout << "Value: " << node->value << std::endl;
        printTreePreOrder(node->left);
        printTreePreOrder(node->right);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: printTreePostOrder(Node*)
 * Description: Prints a Btree in post-order.
 * Precondition: Btree must exist.
 * Postcondition: If Btree is null, returns null. Otherwise prints all values in tree
 *     in post-order.
 * Analysis: O(h); h = height of tree
 */
void Btree::printTreePostOrder(Node* node){
    if(!node){
        return;
    }
    else{
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        std::cout << "Value: " << node->value << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: menu()
 * Description: Menu system for testing of Btree
 * Precondition: Btree must exist.
 * Postcondition: Allows a user to test insert, remove, and print methods of the 
 *     Btree class
 * Analysis: O(n); n = number of choice selection cycles user makes
 */
void Btree::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    while(select_on){
        std::cout << "\n1. Insert.\n2. Remove.\n3. Binary Tree to Binary Search Tree\n4. In Order Print.\n5. Pre Order Print\n6. Post Order Print\n7. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter integer value to store: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            m_root = insertNode(m_root, value);
            printTreeInOrder(m_root);
            break;
            
            case 2:
            std::cout << "Enter integer value to remove: " << std::endl;
            std::cin >> value;
            std::cout << std::endl;
            m_root = removeNode(m_root, value);
            printTreeInOrder(m_root);
            break;

            case 3:
            std::cout << "Printing Binary Tree in preorder:" << std::endl;
            printTreePreOrder(m_root);
            std::cout << "Converting Binary Tree to Binary Search Tree..." << std::endl;
            m_root = BTtoBST(m_root);
            std::cout << "Printing Binary Search Tree in preorder:" << std::endl;
            printTreePreOrder(m_root);
            break;

            case 4:
            std::cout << "Printing Tree in order:" << std::endl;
            printTreeInOrder(m_root);
            break;

            case 5:
            std::cout << "Printing Tree in pre-order:" << std::endl;
            printTreePreOrder(m_root);
            break;
            
            case 6:
            std::cout << "Printing Tree in post-order:" << std::endl;
            printTreePostOrder(m_root);
            break;

            case 7:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
