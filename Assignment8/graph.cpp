/* Christopher Hunt
 * CS260
 * graph.cpp
 */

// This is an undirected graph

#include "graph.h"

using GraphMap = std::unordered_map<std::string, Vertex*>;

////////////////////////////////////////////////////////////////////////////////

/* Function: Graph()
 * Description: Constructors a Graph object.
 * Analysis: O(1)
 */
Graph::Graph(){
    m_vertices = new GraphMap;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: ~Graph()
 * Description: Deconstructors a Graph object.
 * Analysis: O(n)
 */
Graph::~Graph(){
    GraphMap::iterator graph_it;

    // Iterates over unsorted_map object that contains all of Graph's data.
    for(graph_it = m_vertices->begin(); graph_it != m_vertices->end(); ++graph_it){
        delete graph_it->second;
    }   
    delete m_vertices;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: getVert(std::string name)
 * Description: Searchs Graph for Vertex, returns Vertex pointer to that Vertex object. 
 * Analysis: O(1)
 */
Vertex* Graph::getVert(std::string name){
    Vertex *vert = nullptr;
    if(vertexInGraph(name) == true){
        vert = (*m_vertices)[name];
    }
    else{
        std::cout << "Vertex " << name << " not in Graph." << std::endl;
    }

    return vert;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: vertexInGraph(std::string name)
 * Description: Checks the map if a particular key is stored in the graph, returns bool. 
 * Analysis: O(1)
 */
bool Graph::vertexInGraph(std::string name){
    bool is_in = false;
    if(m_vertices->find(name) != m_vertices->end()){
        is_in = true;
    }
    return is_in;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: addVertex(std::string name)
 * Description: Takes a string and turns it into a Vertex object and adds it to 
 *     the Graph.
 * Analysis: O(1)
 */
void Graph::addVertex(std::string name){
    int num;
    std::string dst_name;
    Vertex *temp, *vert = new Vertex(name);

    if(vertexInGraph(name) == false){
        m_vertices->emplace(name, vert); // Add new vertex to graph
        
        std::cout << name << " has been added to the Graph." << std::endl;
    }
    else{
        std::cout << name << " is already in the Graph." << std::endl;
    }
}


////////////////////////////////////////////////////////////////////////////////

/* Function: addEdge(std::string name)
 * Description: Adds an Edge between two Vertices.
 * Analysis: O(1)
 */
void Graph::addEdge(std::string src_name, std::string dst_name){
    Vertex *src_temp = getVert(src_name);
    Vertex *dst_temp = getVert(dst_name);
    if(src_temp != nullptr && dst_temp != nullptr){
        src_temp->addNeighbor(dst_temp, 1);
        dst_temp->addNeighbor(src_temp, 1);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: removeVertex(std::string name)
 * Description: Checks to see if key is in Graph. If so the Vertex object is deleted,
 *     and the key/value pair is erased from the Graph.
 * Analysis: O(1)
 */
void Graph::removeVertex(std::string name){
    if(vertexInGraph(name) == true){
        delete (*m_vertices)[name];
        m_vertices->erase(name);
        std::cout << name << " has been removed from the Graph." << std::endl;
    }
    else{
        std::cout << name << " is not in this Graph." << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: removeEdge(std::string src_name, std::string dst_name)
 * Description: Checks to see if key is in Graph. If so the Vertex object is deleted,
 *     and the key/value pair is erased from the Graph.
 * Analysis: O(1)
 */
void Graph::removeEdge(std::string src_name, std::string dst_name){
        Vertex* src, dst;

}

////////////////////////////////////////////////////////////////////////////////

/* Function: shortestPath(Vertex *src, Vertex *dst)
 * Description: Finds the shortest path from a source Vertex to a destination Vertex. 
 * Analysis:
 */
void Graph::shortestPath(Vertex *src, Vertex *dst){

}

////////////////////////////////////////////////////////////////////////////////

/* Function: minSpanTree()
 * Description: 
 * Analysis:
 */
void Graph::minSpanTree(){

}

////////////////////////////////////////////////////////////////////////////////

/* Function: printGraphTracersal()
 * Description: Iterates over GraphMap and prints all Vertices and their adjacency lists.
 * Analysis: O(n)
 */
void Graph::printGraphTraversal(){
    for(auto elem : *m_vertices){
        std::cout << "\t" << elem.second->toString() << std::endl;
    }
    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: toString()
 * Description: Stringifies Graph object.
 * Analysis: O(1)
 */
std::string Graph::toString(std::string sep){
    std::string result = "";
    for (auto elem : *m_vertices){
        result += elem.second->toString() + sep;
    } 
    return result;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: menu()
 * Description: Allows user to test Graph objects methods.
 */
void Graph::menu(){
    bool select_on {true};
    int selection = 0;
    std::string name, src_name, dst_name;
    while(select_on){
        std::cout << "\n************************************************\n" << std::endl; 
        std::cout << "\n1. Add Vertex\n2. Remove Vertex\n3. Add Edge\n4. Print Graph Vertices\n5. Exit\n" << std::endl;
        std::cout << "\n************************************************\n" << std::endl; 
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "Enter Vertex Keystring : ";
                std::cin >> name;
                addVertex(name);
                printGraphTraversal();
                break;

            case 2:
                std::cout << "Enter Vertex Keystring : ";
                std::cin >> name;
                removeVertex(name);
                printGraphTraversal();
                break;

            case 3:
                printGraphTraversal();
                std::cout << "Enter Vertex keystring: ";
                std::cin >> src_name;
                std::cout << "Enter Vertex keystring: ";
                std::cin >> dst_name;
                addEdge(src_name, dst_name);

            case 4:
                std::cout << "Printing Graph..." << std::endl;
                printGraphTraversal();
                break;

            case 5:
                std::cout << "\nBye Bye\n" << std::endl;
                select_on = false;
                break;
        }
    }
}
