/* Christopher Hunt
 * CS260
 * vertex.cpp
 */

#include "vertex.h"

////////////////////////////////////////////////////////////////////////////////

/* Function: Vertex(std::string name)
 * Description: Constructor of Vertex object
 * Analysis: O(1)
 */
Vertex::Vertex(std::string name){
    m_name = name;
    m_neighbors = new std::vector<Edge*>();
}

////////////////////////////////////////////////////////////////////////////////

/* Function: Vertex(std::string name, std::vector<Edge*> *neighbors)
 * Description: Constructor of Vertex object.
 * Analysis: O(1)
 */
Vertex::Vertex(std::string name, std::vector<Edge*> *neighbors){
    m_name = name;
    m_neighbors = neighbors;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: ~Vertex()
 * Description: Deconstructor of Vertex object.
 * Analysis: O(n)
 */
Vertex::~Vertex(){
    std::vector<Edge*>::iterator edge_it;

    // Iterate over the vector m_neighbors
    for(edge_it = m_neighbors->begin(); edge_it != m_neighbors->end(); ++edge_it){
        delete *edge_it;
    }
    delete m_neighbors;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: getName()
 * Description: Returns Vertex object's attribute m_name. 
 * Analysis: O(1)
 */
std::string Vertex::getName(){
    return m_name;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: getNeighbors()
 * Description: Returns Vertex object's attribute m_neighbors.
 * Analysis: O(1)
 */
std::vector<Edge*>* Vertex::getNeighbors(){
    return m_neighbors;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: addNeighbor(Vertex *dst, int weight)
 * Description: Creates a new Edge object with current vertex as source and dst
 *     as the adjacent vertex. A weight can be applied. Edge *new_edge is pushed 
 *     to the back of m_neighbors vector.
 * Analysis: O(1)
 */
void Vertex::addNeighbor(Vertex *dst, int weight){
    Edge *new_edge = new Edge(dst, weight);

    m_neighbors->push_back(new_edge);
}

////////////////////////////////////////////////////////////////////////////////

/* Function: toString(std::string sep)
 * Description: Stringifies the Vertex object.
 * Analysis: O(n)
 */
std::string Vertex::toString(std::string sep){
    std::string result = m_name + ": Neighbors: ";
    for (auto elem : *m_neighbors){
        result += elem->toString() + sep;
    }

    return result;
}

