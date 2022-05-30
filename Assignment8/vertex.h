/* Christopher Hunt
 * CS260
 * vertex.h
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "edge.h"
#include <string>
#include <vector>

class Vertex{
    std::string name;
    std::vector<Edge*> neighbors; 
};

#endif
