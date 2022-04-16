#include "dyn_arr.h"


DynArr::DynArr(){
    m_array = nullptr;
    m_size = 0;
    m_capacity = 2;
    resize = 1;
}

DynArr::~DynArr(){
    delete [] m_array;
}

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
        ++resize;
     
        for(int i = 0; i < m_size; i++){
            new_array[i] = m_array[i];
        }
     
        new_array[m_size] = item;
        ++m_size;
        m_array = new_array;
        delete [] deletePtr;
    }
}

void DynArr::removeItem(int item){
    if(!isEmpty()){
        for(int i = 0; i < m_size; i++){
            if(m_array[i] == item){
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

void DynArr::insertItem(int item, int index){
    if(index > (m_size-1)){
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
        for(int i = m_size; i > index; i--){
            m_array[i] = m_array[i-1];
        }
        m_array[index] = item;
        ++m_size;
    }
    else{
    int *deletePtr = m_array;
        m_capacity *= 2; 
        int *new_array = new int[m_capacity];
        ++resize;
     
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

int DynArr::countItem(int item){
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_array[i] == item){
            count++;
        }
    }
    return count;
}

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

void DynArr::popItem(int index){
    if(index > (m_size-1)){
        std::cout << "Index is out of range." << std::endl;
        return;
    }
    for(int i = index; i < m_size; i++){
        m_array[i] = m_array[i+1];
    }
    --m_size;   
}

void DynArr::clearList(){
    int* deletePtr = m_array;
    m_array = nullptr;
    delete [] deletePtr;
}

int* DynArr::copyList(){
    int* new_list = new int[m_capacity];
    for(int i = 0; i < m_size; i++){
        new_list[i] = m_array[i];
    }
    return new_list;
}

void DynArr::extendList(int* list_to_add){

} 

void DynArr::reverseList(){
    int* new_list = new int[m_capacity];
    int* deletePtr = m_array;
    int count = 0;
    for(int i = (m_size-1); i >= 0; i--){
        new_list[count] = m_array[i];
    }
    m_array = new_list;
    delete [] deletePtr;
}

void DynArr::sortList(){

}

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

bool DynArr::isFull(){return (m_size == m_capacity);}

bool DynArr::isEmpty(){return (m_size == 0);}

void DynArr::menu(){
    bool select_on {true};
    int selection {0};
    int item{0};
    int index{0};
    int location{0};
    int amount{0};
    while(select_on){
        std::cout << "\n1. Append List.\n2. Remove Item.\n3. Insert Item.\n4. Count Item.\n5. Index Item\n6. Pop Item\n7. Print Array.\n8. Dev Options.\n9. Exit\n" << std::endl;
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
            printArr();
            break;

            case 8:
            break;

            case 9:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
        }    
    }
}