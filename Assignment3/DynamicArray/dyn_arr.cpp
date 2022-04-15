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
    int value {0};
    int item{0};
    while(select_on){
        std::cout << "\n1. Append List.\n2. Remove Item.\n3. Print Array.\n4. Dev Options\n5. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter value to store [must be an integer]: ";
            std::cin >> item;
            appendList(item);
            item = 0;
            break;
            
            case 2:
            std::cout << "Enter value to store [must be an integer]: ";
            std::cin >> item;
            removeItem(item);
            item = 0;
            break;

            case 3:
            printArr();
            break;

            case 4:
            std::cout << "sizeof(m_array): " << sizeof(m_array) << std::endl;
            break;

            case 5:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
        }    
    }
}