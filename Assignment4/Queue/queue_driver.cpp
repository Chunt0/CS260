/*
Christopher Hunt
CS 260
*/

#include <string>
#include "queue.hpp"

int main(){
    Queue<int> queue1;
    Queue<float> queue2;
    Queue<char> queue3;
    Queue<std::string> queue4;
    int selection{0};
    std::cout << "\n1. int\n2. float\n3. char\n4. string\n\n";
    std::cin >> selection;
    std::cout << "\n\n";
    switch(selection){
        case 1:
            queue1.menu();
            break;

        case 2:
            queue2.menu();
            break;

        case 3:
            queue3.menu();
            break;

        case 4:
            queue4.menu();
            break;
    }

    return 0;
}
