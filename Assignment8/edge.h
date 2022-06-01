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
        Vertex *m_src;
        Vertex *m_dst;
        int m_weight;

    public:
        Edge(Vertex *src, Vertex *dst, int weight = 1);
        std::string toString();
};

#endif
