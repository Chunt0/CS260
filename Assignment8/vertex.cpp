/* Christopher Hunt
 * CS260
 * vertex.cpp
 */

#include "vertex.h"

Vertex::Vertex(std::string name){
    m_name = name;
    m_neighbors = new std::vector<Edge*>();
}

Vertex::Vertex(std::string name, std::vector<Edge*> *neighbors){
    m_name = name;
    m_neighbors = neighbors;
}

Vertex::~Vertex(){
    std::vector<Edge*>::iterator edge_it;
    for(edge_it = m_neighbors->begin(); edge_it != m_neighbors->end(); ++edge_it){
        delete *edge_it;
    }
    delete m_neighbors;
}

std::string Vertex::getName(){
    return m_name;
}

std::vector<Edge*>* Vertex::getNeighbors(){
    return m_neighbors;
}

void Vertex::addNeighbor(Vertex *new_vertex, int weight){
    Edge *new_edge = new Edge(this, new_vertex, weight);

    m_neighbors->push_back(new_edge);
}

