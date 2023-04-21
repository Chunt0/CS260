#include "bag.h"

// Constructor

Bag::Bag(){
    head = NULL;
    current = NULL;
    temp = NULL;
    num_of_marbles = 0;
    id = 0;
}

// Destructor

Bag::~Bag(){
    while(head != NULL){
        current = head;
        head = head->next;
        delete current;
    }
}

// Methods

/*****************************************************
 [*] Function: Bag::addMarble()
 [*] Description: Adds a marble to the bag via a linked list method.
 [*] Parameters: None.
 [*] Pre-Conditions: Must be selected via the selection loop. 
 [*] Post-Conditions: Marble is linked to the list.
 *****************************************************/
void Bag::addMarble(){
    Marble* m = new Marble;
    num_of_marbles++;
    id++;

    std::string color;
    std::cout << "What color marble are you adding?  ";
    std::cin >> color;
    std::cout << std::endl;


    // Assign data to marble
    m->id = id;
    m->color = color;
    m->next = NULL;

        
    // Link marble into list

    if (head != NULL) { 
        // Looping until you reach the last node in the list
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        // Linking marble to the list
        current->next = m;
    }
    
    else{
        head = m;
    }
}


/*****************************************************
 [*] Function: Bag::rmMarble()
 [*] Description: User chooses a marble from the bag to remove.
 [*] Parameters: None.
 [*] Pre-Conditions: Must be selected via the selection loop.
 [*] Post-Conditions: If the marble id matches one in the linked list
 it is removed, if the id number matches none the user is prompted.
 *****************************************************/
void Bag::rmMarble(){
    Marble* deletePtr = NULL;
    
    int num;
    std::cout << "\nWhat's the ID of the marble you want removed? ";
    std::cin >> num;
    std::cout << std::endl;

    // Move all my pointer tools to the head of the list
    temp = head;
    current = head;

    // Find the marble that matches the inputed ID
    while(current != NULL && current->id != num){
        temp = current;
        current = current->next;
    }

    // If it is NULL, prompt, else delete the node and make 
    // a choice on how to delete the node and fix the list.
    if(current == NULL){
        std::cout << "The marble you want removed was not in the bag!\n" << std::endl;
    }
    else{
        deletePtr = current;
        if(deletePtr != head){
            current = current->next;
            temp->next = current;
            delete deletePtr;
        }
        // If node to be removed is head, remove this way.
        else{
            head = head->next;
            temp = NULL;
            current = NULL;
            delete deletePtr;
        }
        num_of_marbles--;
        std::cout << "The marble " << num << " has been removed!\n" << std::endl;
    }
}


/*****************************************************
 [*] Function: Bag::printList()
 [*] Description: Prints the ID and the color of the marble.
     Cycles through the list starting from the head until it reachs NULL
 [*] Parameters: None.
 [*] Pre-Conditions: Must be selected via the selection loop
 [*] Post-Conditions: The current linked list of marbles data is printed.
 *****************************************************/
void Bag::printList(){
    current = head;
    if(current != NULL){
        while(current != NULL){
            std::cout << "Marble: " << current->id << " #### Color: " << current->color << std::endl;
            current = current->next;
        }
    }
    else{
        std::cout << "You seem to have lost your marbles..." << std::endl;
    }
}

/*****************************************************
 [*] Function: Bag::numOfMarbs()
 [*] Description: Prints the number of marbles in the bag.
 [*] Parameters: None.
 [*] Pre-Conditions: Must be selected via the selection loop
 [*] Post-Conditions: The current number of marbles is printed.
 *****************************************************/
void Bag::numOfMarbs(){
    std::cout << "Amount of marbles in the bag: " << num_of_marbles << std::endl;
}

/*****************************************************
 [*] Function: Bag::selectionLoop()
 [*] Description: A while loop that allows the user to choose a Bag
 class function or exit the program.
 [*] Parameters: None.
 [*] Pre-Conditions: Is called in the main function.
 [*] Post-Conditions: Program is exited.
 *****************************************************/
void Bag::selectionLoop(){
    bool select_on {true};
    int selection {0};
    while(select_on){
        std::cout << "\n1. Add Marble.\n2. Remove marble from bag by marble ID\n3. Print contents of bag.\n4. Print number of marbles.\n5. Exit\n" << std::endl;
        std::cin >> selection;
        std::cout << "\n\n";
        switch(selection){
            case 1:
            addMarble();
            break;
            
            case 2:
            rmMarble();
            break;

            case 3:
            printList();
            break;

            case 4:
            numOfMarbs();
            break;

            case 5:
            std::cout << "Bye Bye!\n" << std::endl;
            select_on = false;
        }    
    }
}
