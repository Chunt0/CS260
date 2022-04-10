#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string>

class Bag{
    private:    
   
    struct Marble{
        int id;
        std::string color;
        Marble* next;
    };

    Marble* head;
    Marble* current;
    Marble* temp;
    int num_of_marbles;
    int id;

    public:
    
    // Constructor - Set default values
    Bag(); 

    // Destructor
    ~Bag();

    // Methods
    void addMarble();
    void rmMarble();
    void printList();
    void numOfMarbs();
    void selectionLoop();
};

#endif