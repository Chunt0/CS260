/* Christopher Hunt
 * CS260
 * edge.h
 */

#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include <string>

class Vertex;

class Edge{
    private:
        Vertex *m_dst;
        int m_weight;

    public:
        // Constructor
        Edge(Vertex *dst, int weight = 1);
        
        // Getters
        Vertex* getDst();
        int getWeight();

        // Public Methods
        std::string toString();
};

#endif
