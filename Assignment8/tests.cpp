/* Christopher Hunt
 * CS260
 * driver.py
 */

#include "vertex.h"

void testNewNodeEmptyNeighbors(){
    std::cout << "\n**********************************\n" << std::endl;
    std::cout << "Testing new node with no neighbors." << std::endl;
    Vertex vert1("vert1");
    std::cout << "vert1.getName(): " << vert1.getName() << std::endl;
    std::cout << "vert1.getNeighbors(): " << vert1.getNeighbors() << std::endl;
    std::cout << vert1.to_string() << std::endl;
    std::cout << "\n**********************************\n" << std::endl;
}

void testNewNodeOneNeighbor(){
    std::cout << "\n**********************************\n" << std::endl;
    std::cout << "Testing new node with one neighbors." << std::endl;
    Vertex vert1("vert1");
    Vertex vert2("vert2");
    vert1.addNeighbor(&vert2, 5);
    std::cout << "vert1.getName(): " << vert1.getName() << std::endl;
    std::cout << "vert1.getNeighbors(): " << vert1.getNeighbors() << std::endl;
    std::cout << vert1.to_string() << std::endl;
    std::cout << "\n**********************************\n" << std::endl;
}

void testNewNodeTwoNeighbors(){
    std::cout << "\n**********************************\n" << std::endl;
    std::cout << "Testing new node with two neighbors." << std::endl;
    Vertex vert1("vert1");
    Vertex vert2("vert2");
    vert1.addNeighbor(&vert2, 5);
    Vertex vert3("vert3");
    vert1.addNeighbor(&vert3, 9);
    std::cout << "vert1.getName(): " << vert1.getName() << std::endl;
    std::cout << "vert1.getNeighbors(): " << vert1.getNeighbors() << std::endl;
    std::cout << vert1.to_string() << std::endl;
    std::cout << "\n**********************************\n" << std::endl;
}
int main(){ 

    testNewNodeEmptyNeighbors();
    testNewNodeOneNeighbor();
    testNewNodeTwoNeighbors();

    return 0;
}
