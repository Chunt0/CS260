/* Christopher Hunt
 * CS260
 * edge.h
 */

#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

struct Edge{
    Vertex *m_src;
    Vertex *m_dst;
    int m_weight;
};

#endif
