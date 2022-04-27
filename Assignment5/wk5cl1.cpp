/*
 * Christopher Hunt
 * CS260
 */


#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string a;
    std::vector<int> b;

    a = "Hello world";

    std::cout << a << std::endl;
    
    for(int i = 0; i < 5; i++){
        b.push_back(i);
    }
    for(int i = 0; i <5; i++){
        std::cout << b[i] << std::endl;
    }
    return 0;



}



