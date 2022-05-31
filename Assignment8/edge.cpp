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


std::string Edge::to_string(){
    return "(" + m_src->getName() + ", " + m_dst->getName() + ", " + std::to_string(m_weight) + ")";
}
