/* Christopher Hunt
 * CS260
 * edge.cpp
 */

#include "edge.h"

Edge::Edge(Vertex *src, Vertex *dst, int weight){
    m_src = src;
    m_dst = dst;
    m_weight = weight;
}

Edge::~Edge(){}



