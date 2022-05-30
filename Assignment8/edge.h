/* Christopher Hunt
 * CS260
 * edge.h
 */

#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Vertex;

struct Edge{
    Vertex *m_src;
    Vertex *m_dst;
    int m_weight;

    Edge(Vertex *src, Vertex *dst, int weight){
        m_src = src;
        m_dst = dst;
        m_weight = weight;
    }
};

#endif