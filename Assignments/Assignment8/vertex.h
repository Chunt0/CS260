/* Christopher Hunt
 * CS260
 * vertex.h
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "edge.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Edge;

class Vertex{
    private:
        std::string m_name;
        std::vector<Edge*>* m_neighbors; 

    public:
        // Constructor and Deconstructor
        Vertex(std::string name);
        Vertex(std::string name, std::vector<Edge*> *neighbors);
        ~Vertex();
        
        // Getters
        std::string getName();
        std::vector<Edge*>* getNeighbors();
        
        // Public Methods
        void addNeighbor(Vertex *new_vertex, int weight);
        std::string toString(std::string sep = " ");
};

#endif
