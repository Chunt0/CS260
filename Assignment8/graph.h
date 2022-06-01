/* Christopher Hunt
 * CS260
 * graph.h
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <unordered_map>

using GraphMap = std::unordered_map<std::string, Vertex*>;

class Graph{
    private:
    GraphMap m_vertices;
    
    public:
    Graph();
    ~Graph();

    bool vertexInGraph(std::string name);
    void addVertex(std::string name);
    void removeVertex(std::string name);
    void shortestPath(Vertex* src, Vertex* dst);
    void minSpanTree();
    void printGraphTraversal();
    std::string to_string(std::string sep=" ");
    void menu();

};

#endif
