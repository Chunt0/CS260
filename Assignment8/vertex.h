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

class Edge;

class Vertex{
    private:
        std::string m_name;
        std::vector<Edge*>* m_neighbors; 

    public:
        Vertex(std::string name);
        Vertex(std::string name, std::vector<Edge*> *neighbors);
        ~Vertex();

        std::string getName();
        std::vector<Edge*>* getNeighbors();

        void addNeighbor(Vertex *new_vertex, int weight);

        std::string to_string(std::string sep = " ");
};

#endif
