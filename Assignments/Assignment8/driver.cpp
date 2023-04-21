/* Christopher Hunt
 * CS260
 * driver.cpp
 */

#include "graph.h"

int main(){
    Graph graph;
    
    // Build out graph
    graph.addVertex("a"); // 0
    graph.addVertex("b"); // 1
    graph.addVertex("c"); // 2
    graph.addVertex("d"); // 3
    graph.addVertex("e"); // 4
    graph.addVertex("f"); // 5
    graph.addVertex("g"); // 6
    graph.addVertex("h"); // 7
    graph.addVertex("i"); // 8
    
    graph.addEdge("a", "b", 4, 1);
    graph.addEdge("a", "h", 8, 1);
    graph.addEdge("b", "c", 8, 1);
    graph.addEdge("b", "h", 11, 1);
    graph.addEdge("c", "i", 2, 1);
    graph.addEdge("c", "d", 7, 1);
    graph.addEdge("c", "f", 4, 1);
    graph.addEdge("f", "d", 14, 1);
    graph.addEdge("d", "e", 9, 1);
    graph.addEdge("e", "f", 10, 1);
    graph.addEdge("h", "i", 7, 1);
    graph.addEdge("h", "g", 1, 1);
    graph.addEdge("g", "i", 6, 1);
    graph.addEdge("g", "f", 2, 1);

    graph.menu();
    
    return 0;
}
