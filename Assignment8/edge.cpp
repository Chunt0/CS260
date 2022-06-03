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
Edge::Edge(Vertex *dst, int weight){
    m_dst = dst;
    m_weight = weight;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: getDst()
 * Description: Gets m_src.
 * Analysis: O(1)
 */
Vertex* Edge::getDst(){
    return m_dst;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: getWeight()
 * Description: Gets weight.
 * Analysis: O(1)
 */
int Edge::getWeight(){
    return m_weight;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: toString()
 * Description: Stringifies Edge object attributes.
 * Analysis: O(1)
 */
std::string Edge::toString(){
    return "(" + m_dst->getName() + ", " + std::to_string(m_weight) + ")";
}
