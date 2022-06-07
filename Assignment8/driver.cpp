/* Christopher Hunt
 * CS260
 * driver.cpp
 */

#include "graph.h"

int main(){
    Graph graph;
    
    // Build out graph
    graph.addVertex("0");
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    graph.addVertex("5");
    graph.addVertex("6");
    graph.addVertex("7");
    graph.addVertex("8");
    
    graph.addEdge("0", "1", 4, 1);
    graph.addEdge("0", "7", 8, 1);
    graph.addEdge("1", "2", 8, 1);
    graph.addEdge("1", "7", 11, 1);
    graph.addEdge("2", "8", 2, 1);
    graph.addEdge("2", "3", 7, 1);
    graph.addEdge("2", "5", 4, 1);
    graph.addEdge("5", "3", 14, 1);
    graph.addEdge("3", "4", 9, 1);
    graph.addEdge("4", "5", 10, 1);
    graph.addEdge("7", "8", 7, 1);
    graph.addEdge("7", "6", 1, 1);
    graph.addEdge("6", "8", 6, 1);
    graph.addEdge("6", "5", 2, 1);

    graph.menu();
    
    return 0;
}
