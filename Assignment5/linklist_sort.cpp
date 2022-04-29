/* Christopher Hunt
 * CS260
 */

#include "linklist_sort.h"

LinkList::LinkList(){
    m_head = nullptr;
    m_size = 0;
}

LinkList::~LinkList(){
    Node* delete_ptr = m_head;
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
        m_size++;
    }
    else{
        m_head = n;
        m_size++;
    }
}

void LinkList::removeValue(int value){
    Node* delete_ptr = nullptr;
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
        else if(current->value == value && current != m_head && current->next != nullptr){
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
    Node* left = nullptr;
    Node* right = nullptr;
    int lval, rval;
    int steps = m_size;
    bool swapped = true;
    while(swapped == true){
        swapped = false;
        left = m_head;
        right = left->next;
        for(int i = 1; i < steps; i++){
            if(left->value > right->value){
                lval = left->value;
                rval = right->value;
                left->value = rval;
                right->value = lval;
                swapped = true;
            }
            left = left->next;
            right = right->next;
        }
        steps--;
    }
}

    
void LinkList::selectionSort(){
    Node* smallest;
    Node* current;
    Node* temp_head;
    

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
    Node* current = m_head;
    while(current != nullptr){
        std::cout << "Value: " << current->value << std::endl;
        current = current->next;
        
    }
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
                removeValue(value);
                printList();
                break;
            case 3:
                std::cout << "BUBBLE SORT" << std::endl;
                bubbleSort();
                printList();
                break;
            case 4:
                std::cout << "SELECTION SORT" << std::endl;
                selectionSort();
                printList();
                break;
            case 5:
                std::cout << "INSERTION SORT" << std::endl;
                insertionSort();
                printList();
                break;
            case 6:
                std::cout << "MERGE SORT" << std::endl;
                mergeSort();
                printList();
                break;
            case 7:
                std::cout << "QUICK SORT" << std::endl;
                quickSort();
                printList();
                break;
            case 8:
                std::cout << "RANDOM QUICK SORT" << std::endl;
                randomQuickSort();
                printList();
                break;
            case 9:
                std::cout << "COUNTING SORT" << std::endl;
                countingSort();
                printList();
                break;
            case 10:
                std::cout << "RADIX SORT" << std::endl;
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
