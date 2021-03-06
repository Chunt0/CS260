/* Christopher Hunt
 * CS260
 */
#ifndef LINKLIST_SORT_H
#define LINKLIST_SORT_H

#include <iostream>
#include "./node.h"

class LinkList{
    private:
        // Attributes
        Node* m_head;
        int m_size;

        int get_size();
        int get_position(int value);
        int get_value(int position);

    public:
        // Constructor Destructor
        LinkList();
        ~LinkList();

        // Methods
        void addValue(int value);
        void removeValue(int index);
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void mergeSort();
        void quickSort();
        void randomQuickSort();
        void countingSort();
        void radixSort();
        void printList();
        void menu();

};

#endif
