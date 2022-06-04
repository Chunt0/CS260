/* Christopher Hunt
 * CS260
 * graph.cpp
 */

// This is an undirected graph

#include "graph.h"



////////////////////////////////////////////////////////////////////////////////

/* Function: Graph()
 * Description: Constructors a Graph object.
 * Analysis: O(1)
 */
Graph::Graph(){
    m_vertices = new GraphMap;
    m_num_vertices = 0;
    m_num_edges = 0;
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

/* Function: vertsConnected(std::string src_name, std::string dst_name)
 * Description: Checks to see if vertices are connected
 * Analysis: O(E) -> where E is the number of Edge's in edge list.
 */
bool Graph::vertsConnected(std::string src_name, std::string dst_name){
    bool is_connected = false;
    Vertex *src_vert = getVert(src_name);
    std::vector<Edge*>::iterator edge_it;

    // src_vert->getNeighbors()->begin() returns an iterator over sources edge list
    for(edge_it = src_vert->getNeighbors()->begin(); edge_it != src_vert->getNeighbors()->end(); ++edge_it){

        // Checks the sources edge list. If an Edge objects destination matches dst_name
        // then the Vertices are connected.
        if((*edge_it)->getDst()->getName() == dst_name){ 
                is_connected = true;
        }        
    }
    return is_connected;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: vertexInGraph(std::string name)
 * Description: Checks the map if a particular key is stored in the graph, returns bool. 
 * Analysis: O(1)
 */
bool Graph::vertexInGraph(std::string name){
    bool is_in = false;

    // If name is in the map .find() will return an iterator to the pair, is_in = true.
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
    Vertex *vert = new Vertex(name);

    if(vertexInGraph(name) == false){
        m_vertices->emplace(name, vert); // Add new vertex to graph
        
        m_num_vertices++;
        std::cout << name << " has been added to the Graph." << std::endl;
    }
    else{
        delete vert;
        std::cout << name << " is already in the Graph." << std::endl;
    }
}


////////////////////////////////////////////////////////////////////////////////

/* Function: addEdge(std::string name)
 * Description: Adds an Edge between two Vertices.
 * Analysis: O(1)
 */
void Graph::addEdge(std::string src_name, std::string dst_name, int weight, int undirected){
    Vertex *src_temp = getVert(src_name);
    Vertex *dst_temp = getVert(dst_name);
    if(src_temp != nullptr && dst_temp != nullptr && !vertsConnected(src_name, dst_name) && src_name != dst_name){
        src_temp->addNeighbor(dst_temp, weight); // Add a new edge to Vertex's edge list
        if(undirected == 1){
            dst_temp->addNeighbor(src_temp, weight); // Add a edge to destination Vertex if graph is undirected
        }
        m_num_edges++;
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: removeVertex(std::string name)
 * Description: Checks to see if key is in Graph. If so the Vertex object is deleted,
 *     and the key/value pair is erased from the Graph.
 * Analysis: O(E) -> where E is the number of edges the vertex has.
 */
void Graph::removeVertex(std::string name){
    if(vertexInGraph(name) == true){
        std::vector<Edge*>::iterator edge_it;
        std::vector<Edge*> *dst_edges = nullptr;
        std::vector<Edge*> *edges = (*m_vertices)[name]->getNeighbors(); // Get vector of Edges
        
        // Go through vector of Edges, deleted the dst vertex connection.
        // For each Edge the Vertex has, go to the destination vertex and delete
        // the corresponding Edge in it's edge list.
        for(int i = 0; i < edges->size(); ++i){
            dst_edges = (*edges)[i]->getDst()->getNeighbors(); 
            for(edge_it = dst_edges->begin(); edge_it != dst_edges->end(); ++edge_it){
                if((*edge_it)->getDst()->getName() == name){
                    delete *edge_it; // Delete the Edge object of the destination.
                    dst_edges->erase(edge_it); // Remove it from the edge list
                    break;
                }
            }
        }
        delete (*m_vertices)[name]; // Delete the Vertex from memory
        m_vertices->erase(name); // Remove that entry from the graph's vertices map
        m_num_vertices--;
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
 * Analysis: O(E1*E2) -> where E1 is the number of edges in src's edge list and 
 *     E2 is the number edges in dst's edge list.
 */
void Graph::removeEdge(std::string src_name, std::string dst_name, int undirected){
    std::vector<Edge*> *src = (*m_vertices)[src_name]->getNeighbors();
    std::vector<Edge*> *dst = (*m_vertices)[dst_name]->getNeighbors();
    std::vector<Edge*>::iterator edge_it;
    
    // Get src's edge list and search for the edge connected to dst, delete and remove.
    for(edge_it = src->begin(); edge_it != src->end(); ++edge_it){
        if((*edge_it)->getDst()->getName() == dst_name){
            delete *edge_it;
            src->erase(edge_it);
            break;
        }
    }

    // Get dst's edge list and search for the edge connected to src, delete and remove.
    if(undirected == 1){
        for(edge_it = dst->begin(); edge_it != dst->end(); ++edge_it){
            if((*edge_it)->getDst()->getName() == src_name){
                delete *edge_it;
                dst->erase(edge_it);
                m_num_edges--;
                break;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: shortestPath(Vertex *src, Vertex *dst)
 * Description: Finds the shortest path from a source Vertex to a destination Vertex. 
 * Analysis:
 */
DijMap* Graph::dijShortestPath(std::string src_name, std::string dst_name){
    if(vertexInGraph(src_name) && vertexInGraph(dst_name)){
        int min = INT_MAX;
        Vertex *src = (*m_vertices)[src_name];
        Vertex *dst = (*m_vertices)[dst_name];

        // Build min path map
        GraphMap::iterator graph_it;
        DijMap *verts = new DijMap; // unordered_map<Vertex*, pair<int, Vertex*>> 
        for(graph_it = m_vertices->begin(); graph_it != m_vertices->end(); ++graph_it){
            if(graph_it->second == src){
                verts->emplace(graph_it->second, std::make_pair(0, nullptr)); // Set source as zero
            }
            else{
                verts->emplace(graph_it->second, std::make_pair(min, nullptr)); // Setting every other vertex to INT_MAX
            }
        }
        
        // BEGIN ALGO
        DijSet visited, unvisited; // unordered_set<Vertex*> 
        for(graph_it = m_vertices->begin(); graph_it != m_vertices->end(); ++graph_it){
            unvisited.insert(graph_it->second); // Copy all Vertices to unvisited set
        }

        Vertex *current = src, *neighbor = nullptr;
        int old_weight, new_weight;
        std::pair<int, Vertex*> *update = nullptr;
        std::vector<Edge*>::iterator edge_it;
        while(unvisited.empty() == false){
            std::vector<Edge*> *edge_list = current->getNeighbors(); // Get current vertex's edge list
            for(edge_it = edge_list->begin(); edge_it != edge_list->end(); ++edge_list){
                neighbor = (*edge_it)->getDst(); 
                old_weight = (*edge_it)->getWeight(); // Get the sum of shortest weights to get to current vertex 
                if(unvisited.find(neighbor) != unvisited.end()){
                    new_weight = (*verts)[current].first + old_weight; // Get new weight by adding previous weight with weight along edge.
                    if(new_weight < old_weight){
                        // Swap out the old weight for the new weight and add current as this vertex's predecessor
                        update = new std::pair<int, Vertex*>(new_weight, current);
                        (*verts)[neighbor].swap(*update);
                        delete update;
                    }
                }
            }
            // Move Vertex to visited set
            visited.insert(current);
            unvisited.erase(current);
        }    

        return verts;
        
    }
    else{
        DijMap *null = nullptr;
        std::cout << "Source or Destination is not in graph." << std::endl;
        return null;
    }
}

////////////////////////////////////////////////////////////////////////////////

/* Function: minSpanTree()
 * Description: 
 * Analysis:
 */
void Graph::krusMinSpanTree(){

}

////////////////////////////////////////////////////////////////////////////////

/* Function: printGraphTracersal()
 * Description: Iterates over GraphMap and prints all Vertices and their adjacency lists.
 * Analysis: O(n)
 */
void Graph::printGraphTraversal(){
    std::cout << "\tVertices: " << m_num_vertices << " | Edges: " << m_num_edges << std::endl;
    //for(auto elem : *m_vertices){
    //    std::cout << "\tVertex: " << elem.second->toString() << std::endl;
    //}
    std::cout << toString() << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: toString()
 * Description: Stringifies Graph object.
 * Analysis: O(1)
 */
std::string Graph::toString(){
    std::string result = "";
    for (auto elem : *m_vertices){
        result += "\t" + elem.second->toString() + "\n";
    } 
    return result;
}

////////////////////////////////////////////////////////////////////////////////

/* Function: menu()
 * Description: Allows user to test Graph objects methods.
 */
void Graph::menu(){
    bool select_on {true};
    int selection = 0, weight = 1, undirected = 0;
    std::string name, src_name, dst_name;
    while(select_on){
        std::cout << "\n************************************************\n" << std::endl; 
        std::cout << "\n1. Add Vertex\n2. Add Edge\n3. Remove Vertex\n4. Remove Edge\n5. Print Graph Vertices\n6. Exit\n" << std::endl;
        std::cout << "\n************************************************\n" << std::endl; 
        std::cin >> selection;
        switch(selection){
            case 1:
                std::cout << "~~~~Add Vertex~~~~\n" << std::endl;
                std::cout << "Enter Vertex Keystring : ";
                std::cin >> name;
                addVertex(name);
                printGraphTraversal();
                break;

            case 2:
                std::cout << "~~~~Add Edge~~~~\n" << std::endl;
                printGraphTraversal();
                std::cout << "Enter Source Vertex keystring: ";
                std::cin >> src_name;
                std::cout << "Enter Destination Vertex keystring: ";
                std::cin >> dst_name;
                std::cout << "Enter a weight (must be an integer): ";
                std::cin >> weight;
                std::cout << "If your graph is undirected -> enter 1: ";
                std::cin >> undirected;
                addEdge(src_name, dst_name, weight, undirected);
                printGraphTraversal();
                break;

            case 3:
                std::cout << "~~~~Remove Vertex~~~~\n" << std::endl;
                std::cout << "Enter Vertex Keystring : ";
                std::cin >> name;
                removeVertex(name);
                printGraphTraversal();
                break;

            case 4:
                std::cout << "~~~~Remove Edge~~~~\n" << std::endl;
                printGraphTraversal();
                std::cout << "Enter Source Vertex keystring: ";
                std::cin >> src_name;
                std::cout << "Enter Destination Vertex keystring: ";
                std::cin >> dst_name;
                std::cout << "If your graph is undirected -> enter 1: ";
                std::cin >> undirected;
                removeEdge(src_name, dst_name, undirected);
                printGraphTraversal();
                break;

            case 5:
                std::cout << "Printing Graph..." << std::endl;
                printGraphTraversal();
                break;

            case 6:
                std::cout << "\nBye Bye\n" << std::endl;
                select_on = false;
                break;
        }
    }
}
