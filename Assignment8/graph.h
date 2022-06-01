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
    GraphMap *m_vertices;
    
    public:
    // Constructor and Deconstructor
    Graph();
    ~Graph();

    // Getters
    GraphMap* getVerts();
    int getVertCount();
    int getEdgeCount();

    // Public Methods
    bool vertexInGraph(std::string name);
    void addVertex(std::string name);
    void removeVertex(std::string name);
    void shortestPath(Vertex* src, Vertex* dst);
    void minSpanTree();
    void printGraphTraversal();
    std::string toString(std::string sep=" ");
    void menu();

};

#endif
