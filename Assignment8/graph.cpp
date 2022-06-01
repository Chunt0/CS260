/* Christopher Hunt
 * CS260
 * graph.cpp
 */

#include "graph.h"

using GraphMap = std::unordered_map<std::string, Vertex*>;

Graph::Graph(){
    m_vertices = new GraphMap;
}

Graph::~Graph(){
    GraphMap::iterator graph_it;
    for(graph_it = m_vertices->begin(); graph_it != m_vertices->end(); ++graph_it){
        delete graph_it->second;
    }   
    delete m_vertices;
}

bool Graph::vertexInGraph(std::string name){
    bool is_in = false;
    if(m_vertices->find(name) != m_vertices->end()){
        is_in = true;
    }
    return is_in;
}

void Graph::addVertex(std::string name){
    Vertex *vert = new Vertex(name);

    if(vertexInGraph(name) == false){
        m_vertices->emplace(name, vert); // Add new vertex to graph
        std::cout << name << " has been added to the Graph." << std::endl;
    }
    else{
        std::cout << name << " is already in the Graph." << std::endl;
    }
}

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

void Graph::shortestPath(Vertex *src, Vertex *dst){}

void Graph::minSpanTree(){}

void Graph::printGraphTraversal(){
    for(auto elem : *m_vertices){
        std::cout << elem.second->to_string() << std::endl;
    }
    std::cout << std::endl;
}

std::string Graph::to_string(std::string sep){
    std::string result = "";
    for (auto elem : *m_vertices){
        result += elem.second->to_string() + sep;
    } 
    return result;
}

void Graph::menu(){
    bool select_on {true};
    int selection = 0;
    std::string name;
    while(select_on){
        std::cout << "\n************************************************\n" << std::endl; 
        std::cout << "\n1. Add Vertex\n2. Remove Vertex\n3. Print Graph Vertices\n4. Exit\n" << std::endl;
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
                std::cout << "Printing Graph..." << std::endl;
                printGraphTraversal();
                break;

            case 4:
                std::cout << "\nBye Bye\n" << std::endl;
                select_on = false;
                break;
        }
    }
}
