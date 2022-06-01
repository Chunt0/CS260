/* Christopher Hunt
 * CS260
 * edge.cpp
 */

#include "edge.h"

////////////////////////////////////////////////////////////////////////////////

/* Function: Edge(Vertex *src, Vertex *dst, int weight)
 * Description: Constructor of Edge object.
 * Analysis: O(1)
 */
Edge::Edge(Vertex *src, Vertex *dst, int weight){
    m_src = src;
    m_dst = dst;
    m_weight = weight;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: toString()
 * Description: Stringifies Edge object attributes.
 * Analysis: O(1)
 */
std::string Edge::toString(){
    return "(" + m_src->getName() + ", " + m_dst->getName() + ", " + std::to_string(m_weight) + ")";
}
