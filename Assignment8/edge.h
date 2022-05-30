/* Christopher Hunt
 * CS260
 * edge.h
 */

#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge{
    private:
        Vertex *m_src;
        Vertex *m_dst;
        int m_weight;

    public:
        Edge();
        Edge(Vertex *src, Vertex *dst, int weight);
        ~Edge();

        Vertex* getSrc();
        Vertex* getDst();
        int getWeight();
};

#endif
