/*
 CHRISTOPHER HUNT
 CS260
*/

#include "dyn_arr.h"

/*
Constructor: DynArr()
Description: Builds DynArr object. Sets intitial attributes.
*/
DynArr::DynArr(){
    m_array = nullptr;
    m_size = 0;
    m_capacity = 2;
}

/*
Destructor: ~DynArr()
Description: Manages the deallocation of heap memory.
*/
DynArr::~DynArr(){
    delete [] m_array;
}

/*
Method: appendList()
Description: Adds an int to the end of the list in the array. Utilizes several
    if clauses to manage different cases that may occur - whether the list is empty
    or if it contains values but is not full or if it is full. If the list is full
    there will be steps taken to create a new list with double the capacity, the list
    will be copied and the object will now be pointing to this new list, the old one
    will be deleted.
*/
void DynArr::appendList(int item){
    if(isEmpty()){
        m_array = new int[m_capacity];
        m_array[m_size] = item;
        ++m_size;
    }
    else if(!isFull()){
        m_array[m_size] = item;
        ++m_size;
    }
    else{
        int *deletePtr = m_array;
        m_capacity *= 2; 
        int *new_array = new int[m_capacity];
     
        for(int i = 0; i < m_size; i++){
            new_array[i] = m_array[i];
        }
     
        new_array[m_size] = item;
        ++m_size;
        m_array = new_array;
        delete [] deletePtr;
    }
}

/*
Method: removeItem()
Description: If the list is not empty it will search through the array, the 
    first value to match will then be removed and the list will shift to fill
    the void.
*/
void DynArr::removeItem(int item){
    if(!isEmpty()){
        for(int i = 0; i < m_size; i++){
            if(m_array[i] == item){
                // Close the gap
                for(int j = 0; j < (m_size - i); j++){
                    m_array[i+j] = m_array[i+j+1];
                }
                --m_size;
                break;
            }
            else{
                continue;
            }
        }
    }
    else{
        std::cout << "DynArray is already empty." << std::endl;
    }
}

/*
Method: insertItem()
Description: Takes a value and an index, inserts that value at the indexed location.
    the list shifts one to the right to make room for the addition.
*/
void DynArr::insertItem(int item, int index){
    if(index > (m_size-1) || index < 0){
        std::cout << "Index is out of range." << std::endl;
        return;
    }
    
    if(isEmpty()){
        std::cout << "Dynamic Array is empty. Insert at index 0 instead? [y/n] ";
        char answer;
        std::cin >> answer;
        std::cout << std::endl;
        if(answer == 'y'){
            appendList(item);
            return;
        }
        else{
            return;
        }        
    }
    else if(!isFull()){
        ++m_size;
        for(int i = m_size; i > index; i--){
            m_array[i] = m_array[i-1];
        }
        m_array[index] = item;
    }
    else{
    int *deletePtr = m_array;
        m_capacity *= 2; 
        int *new_array = new int[m_capacity];
     
        for(int i = 0; i < m_size; i++){
            new_array[i] = m_array[i];
        }

        for(int i = m_size; i > index; i--){
            new_array[i] = new_array[i-1];
        }
        new_array[index] = item;
        ++m_size;
        m_array = new_array;
        
        delete [] deletePtr;
    }
}

/*
Method: countItem()
Description: Loops through the array. When a value in the array matches the
    value inputed by the user a counter is incremented by one. Returns 
    count.
*/
int DynArr::countItem(int item){
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_array[i] == item){
            count++;
        }
    }
    return count;
}

/*
Method: indexItem()
Description: Loops through the array. When the value is found, the index is recorded
    and returned.
*/
int DynArr::indexItem(int item){
    int index = -1;
    bool found = false;
    for(int i = 0; i < m_size; i++){
        if(m_array[i] == item && !found){
            index = i;
            found = true;
        }
    }
    return index;
}

/*
Method: popItem()
Description: User inputs an index. Starting from the index location specified
    the values are made equal to that which proceeds it.
*/
void DynArr::popItem(int index){
    if(index > (m_size-1) || index < 0){
        std::cout << "Index is out of range." << std::endl;
        return;
    }
    for(int i = index; i < m_size; i++){
        m_array[i] = m_array[i+1];
    }
    --m_size;   
}

/*
Method: clearList()
Description: Deletes list and makes the array point to a nullpointer.
####BROKEN####
*/
void DynArr::clearList(){
    int* deletePtr = m_array;
    m_array = nullptr;
    m_size = 0;
    m_capacity = 2;
    delete [] deletePtr;
}

/*
Method: copyList()
Description: A new int array is created with the same capacity. The values from DynArr
    are copied to the new list. That list is returned.
*/
void DynArr::copyList(int* new_list){
    //new_list = new int[m_capacity];
    for(int i = 0; i < m_size; i++){
        new_list[i] = m_array[i];
    }
}

/*
Method: extendList()
Description: When given a list to add and it's corresponding length, each item is appended
    to the DynArr. In this iteration, the deals with memory alloc and dealloc. Can be tweaked.
*/
void DynArr::extendList(int* list_to_add, int length){
    for(int i = 0; i < length; i++){
        appendList(list_to_add[i]);
    }
} 

/*
Method: reverseList()
Description: Creates a new list the same size as m_array. The m_array is looped 
    from last to first while being placed in the first position to the last in
    the new list. m_array is made to point to the new list, the old list is
    deleted.
*/
void DynArr::reverseList(){
    int* new_list = new int[m_capacity];
    int* deletePtr = m_array;
    int count = 0;
    for(int i = (m_size-1); i >= 0; i--){
        new_list[count] = m_array[i];
        count++;
    }
    m_array = new_list;
    delete [] deletePtr;
}

/*
Method: sortList()
Description: Uses a selection sort algorithm to sort from minimum to maximum.
    Steps through each element of the array, compares it's value to those proceeding
    it, if smaller, swap places. 
*/
void DynArr::sortList(){
    int min, temp;
    if(m_size > 1){
        for(int i = 0; i < m_size; i++){
            min = i;
            for(int j = i + 1; j < m_size; j++){
                if (m_array[j] < m_array[min]){
                    min = j;
                }
            }
            temp = m_array[i];
            m_array[i] = m_array[min];
            m_array[min] = temp;
        }
    }
}

/*
Method: printArr()
Description: Loops through the array and prints associated values.
*/
void DynArr::printArr(){
    if(!isEmpty()){
        for(int i = 0; i < m_size; i++){
            std::cout << "m_array[" << i << "]: " << m_array[i] << std::endl;
            std::cout << "m_size: " << m_size << std::endl;
        }    
    }
    else{
        std::cout << "DynArray is empty." << std::endl;
    }
}

/*
Method: isFull()
Description: Checks if the size is equal to the capacity.
*/
bool DynArr::isFull(){return (m_size == m_capacity);}

/*
Method: isEmpty()
Description: True if m_size is zero.
*/
bool DynArr::isEmpty(){return (m_size == 0);}

/*
Method: menu()
Description: A simple menu interface to allow the user to test functionality
    of the object.
*/
void DynArr::menu(){
    bool select_on {true};
    int selection {0};
    int item{0};
    int index{0};
    int location{0};
    int amount{0};
    int* new_list = nullptr;
    int extend_test[] = {100, 200, 300};
    int length = (sizeof(extend_test)/sizeof(extend_test[0]));
    while(select_on){
        std::cout << "\n1. Append List\n2. Remove Item\n3. Insert Item\n4. Count Item\n5. Index Item\n6. Pop Item\n7. Clear List\n8. Copy List\n9. Extend List\n10. Reverse List\n11. Sort List\n12. Print Array\n13. Dev Options\n14. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter value to store [must be an integer]: ";
            std::cin >> item;
            appendList(item);
            item = 0;
            printArr();
            break;
            
            case 2:
            std::cout << "Enter value to remove [must be an integer]: ";
            std::cin >> item;
            removeItem(item);
            item = 0;
            printArr();
            break;

            case 3:
            std::cout << "Enter a value to store [must be an integer]: ";
            std::cin >> item;
            std::cout << "Enter the index you wish to insert the value [must be an integer]: ";
            std::cin >> index;
            insertItem(item, index);
            printArr();
            item = 0;
            index = 0;
            break;

            case 4:
            std::cout << "Enter value to count [must be an integer]: ";
            std::cin >> item;
            amount = countItem(item);
            std::cout << "There are " << amount << " items of value " << item << std::endl;
            item = 0;
            printArr();
            break;

            case 5:
            std::cout << "Enter value to index [must be an integer]: ";
            std::cin >> item;
            location = indexItem(item);
            item = 0;
            std::cout << "The index is: " << location << std::endl;
            printArr();
            break;

            case 6:
            std::cout << "Enter index to pop [must be an integer]: ";
            std::cin >> index;
            popItem(index);
            index = 0;
            printArr();
            break;

            case 7:
            clearList(); 
            break;

            case 8:
            delete [] new_list;
            new_list = new int[m_capacity];
            copyList(new_list);
            for(index = 0; index < m_size; index++){
                std::cout << "new_list[" << index << "]: " << new_list[index] << std::endl;
            }
            index = 0;
            break;

            case 9:
            extendList(extend_test, length);
            printArr();
            break;

            case 10:
            if(m_size > 1){
                reverseList();
            }
            printArr();
            break;

            case 11:
            sortList();
            printArr();
            break;

            case 12:
            printArr();
            break;

            case 13:
            break;

            case 14:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
            if(new_list != nullptr){
                delete [] new_list;
            }
        }    
    }
}
