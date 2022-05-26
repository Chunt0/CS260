/* Christopher Hunt
 * CS260
 * list.h
 */

#ifndef LIST_H
#define LIST_H

#include "node.h"

class List{
    private:
        // Attributes
        Node* m_head;
        int m_size;
        
    public:
        // Constructor and Destructor
        List();
        ~List();

        // Methods
        void addNode(std::string key, int value); // Auto Sort algorithm lives here ^_^
        void removeNode(std::string key);
        void printList();
        void menu();
};


#endif
