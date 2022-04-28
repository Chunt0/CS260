/* Christopher Hunt
 * CS260
 */

#include "linklist_sort.h"

LinkList::LinkList(){
    m_head = nullptr;
    m_size = 0;
}

LinkList::~LinkList(){
    Node* delete_ptr;
    while(m_head != nullptr){
        delete_ptr = m_head;
        m_head = m_head->next;
        delete delete_ptr;
    }
}

void LinkList::addValue(int value){
    Node* n = new Node;
    Node* current = m_head;

    n->value = value;
    
    if(m_head != nullptr){
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = n;
    }
    else{
        m_head = n;
    }
}

void LinkList::removeValue(int value){
    Node* delete_ptr;
    Node* current = m_head;
    Node* temp = m_head;
    if(m_head != nullptr){
        while(current->value != value && current != nullptr){
            temp = current;
            current = current->next;
        }
        // If the value searched for is m_head
        if (current->value == value && current == m_head){
            delete_ptr = current;
            current = current->next;
            m_head = current;
            delete delete_ptr;
            m_size--;
            }
        // If the value searched for is any other value but the last node in the list
        else if (current->value == value && current != m_head && current->next != nullptr){
            delete_ptr = current;
            current = current->next;
            temp->next = current;
            delete delete_ptr;
            m_size--;
        }
        // If the value searched for is the last value in the list
        else if(current->value == value && current != m_head && current->next == nullptr){
            delete_ptr = current;
            temp->next = nullptr;
            delete delete_ptr;
            m_size--;
        }
        else{
            std::cout << "The value: " << value << " was not found in the list" << std::endl;
        }
    }
    else{
        std::cout << "The list is empty" << std::endl;
    }
}

void LinkList::bubbleSort(){

}
    
void LinkList::selectionSort(){

}
  
void LinkList::insertionSort(){

}

void LinkList::mergeSort(){

}
 
void LinkList::quickSort(){

}
    
void LinkList::randomQuickSort(){

}
    
void LinkList::countingSort(){

}
    
void LinkList::radixSort(){

}

void LinkList::printList(){

}

void LinkList::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    while(select_on){
        std::cout << "\n1. Add value\n2. Remove value\n3. Bubble sort\n4. Selection sort\n5. Insertion sort\n6. Merge sort\n7. Quick sort\n8. Random quick sort\n9. Counting sort\n10. Radix sort\n11. Print list\n12. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
                std::cout << "Enter value to store [must be an integer]: ";
                std::cin >> value;
                addValue(value);
                printList();
                break;
            case 2:
                std::cout << "Enter value to remove [must be an integer]: ";
                std::cin >> value;
                addValue(value);
                printList();
                break;
            case 3:
                bubbleSort();
                printList();
                break;
            case 4:
                selectionSort();
                printList();
                break;
            case 5:
                insertionSort();
                printList();
                break;
            case 6:
                mergeSort();
                printList();
                break;
            case 7:
                quickSort();
                printList();
                break;
            case 8:
                randomQuickSort();
                printList();
                break;
            case 9:
                countingSort();
                printList();
                break;
            case 10:
                radixSort();
                printList();
                break;
            case 11:
                printList();
                break;
            case 12:
                select_on = false;
                std::cout << "Bye Bye!" << std::endl;
                break;

        }
    }
}
