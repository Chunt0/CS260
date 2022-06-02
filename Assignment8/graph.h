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
    int m_num_vertices;
    int m_num_edges;

    // Private Getters
    Vertex* getVert(std::string name);
    
    public:
    // Constructor and Deconstructor
    Graph();
    ~Graph();

    // Getters
    GraphMap* getVert();
    int getVertCount();
    int getEdgeCount();

    // Public Methods
    bool vertexInGraph(std::string name);
    bool vertsConnected(std::string src_name, std::string dst_name);
    void addVertex(std::string name);
    void addEdge(std::string src_name, std::string dst_name);
    void removeVertex(std::string name);
    void removeEdge(std::string src_name, std::string dst_name);
    void shortestPath(Vertex* src, Vertex* dst);
    void minSpanTree();
    void printGraphTraversal();
    std::string toString(std::string sep=" ");
    void menu();

};

#endif
