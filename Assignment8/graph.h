/* Christopher Hunt
 * CS260
 * graph.h
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <unordered_map>
#include <unordered_set>
#include <queue> // make a FIFO queue for Dijkstra's algo
#include <climits> // for INT_MAX
#include <utility> // for <pair> and make_pair()

using GraphMap = std::unordered_map<std::string, Vertex*>;
using DijMap = std::unordered_map<Vertex*, std::pair<int, Vertex*>>;
using DijSet = std::unordered_set<Vertex*>;

struct KrusEdges{
    int weight;
    Vertex* src;
    Vertex* dst;
};

class Graph{
    private:
    GraphMap *m_vertices;
    std::vector<KrusEdges*> *m_krus_edges;
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
    void addVertex(std::string name = "NewVertex");
    void addEdge(std::string src_name, std::string dst_name, int weight = 1, int undirected = 1);
    void removeVertex(std::string name);
    void removeEdge(std::string src_name, std::string dst_name, int undirected);
    DijMap* dijShortestPath(std::string src_name);
    void printDijShortestPath(DijMap* map, std::string dst_name);
    void krusMinSpanTree();
    void printGraphTraversal();
    std::string toString();
    void menu();

};

#endif
