#include "dyn_arr.h"


DynArr::DynArr(){
    m_array = nullptr;
    m_size = 0;
    m_init_size = 10;
    resize = 1;
}

DynArr::~DynArr(){
    delete m_array;
}

void DynArr::appendList(int item){
    if(isEmpty()){
        m_array = new int[m_init_size];
        m_array[m_size] = item;
        ++m_size;
    }
    else if(!isFull()){
        m_array[m_size] = item;
        ++m_size;
    }
    else{
        int *deletePtr = m_array;
        int *new_array = new int[2*m_init_size];
        ++resize;
     
        for(int i = 0; i < (m_size-1); i++){
            new_array[i] = m_array[i];
        }
     
        new_array[m_size] = item;
        ++m_size;
        m_array = new_array;
        delete deletePtr;
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
        std::cout << "List is already empty." << std::endl;
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

bool DynArr::isFull(){return (m_size == m_init_size*resize);}

bool DynArr::isEmpty(){return (m_size == 0);}

void DynArr::menu(){
    bool select_on {true};
    int selection {0};
    int value {0};
    int item{0};
    while(select_on){
        std::cout << "\n1. Append List.\n2. Remove Item.\n3. Print Array.\n4. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            std::cout << "Enter item to value to store [must be an integer]: ";
            std::cin >> item;
            appendList(item);
            item = 0;
            break;
            
            case 2:
            std::cout << "Enter item to store [must be an integer]: ";
            std::cin >> item;
            removeItem(item);
            item = 0;
            break;

            case 3:
            printArr();
            break;

            case 4:
            std::cout << "#########################\n" << std::endl;
            select_on = false;
        }    
    }
}