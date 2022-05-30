/* Christopher Hunt
 * CS260
 * driver.py
 */

#include "vertex.h"

int main(){
    Vertex *vert1 = new Vertex("vert1");
    Vertex *vert2 = new Vertex("vert2");
    Vertex *vert3 = new Vertex("vert3");

    vert1->addNeighbor(vert2, 1);
    vert1->addNeighbor(vert3, 5);
    vert2->addNeighbor(vert1,1);
    vert2->addNeighbor(vert3, 5);
    std::cout << "vert1->getName(): " << vert1->getName() << std::endl;
    std::cout << "vert1->getNeighbors(): " << vert1->getNeighbors() << std::endl;
    std::cout << "vert2->getName(): " << vert2->getName() << std::endl;
    std::cout << "vert2->getNeighbors(): " << vert2->getNeighbors() << std::endl;
    std::cout << "vert1->to_string(): " << vert1->to_string();
    std::cout << "vert2->to_string(): " << vert2->to_string();

    return 0;
}
