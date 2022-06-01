/* Christopher Hunt
 * CS260
 * graph.cpp
 */

#include "graph.h"

using GraphMap = std::unordered_map<std::string, Vertex*>;

Graph::Graph(){
    GraphMap m_vertices;
}


Graph::~Graph(){
    m_vertices.erase(m_vertices.begin(), m_vertices.end());    
}

bool Graph::vertexInGraph(std::string name){
    bool is_in = false;
    if(m_vertices[name]){
        is_in = true;
    }
    return is_in;
}

void Graph::addVertex(std::string name){
    Vertex* vert = new Vertex(name);

    if(!vertexInGraph(name)){
        m_vertices.emplace(name, vert); // Add new vertex to graph
    }
}

void Graph::removeVertex(std::string name){
    if(vertexInGraph(name)){
        m_vertices.erase(name);
    }
    else{
        std::cout << name << " is not in this Graph." << std::endl;
    }
}

void Graph::shortestPath(Vertex *src, Vertex *dst){}

void Graph::minSpanTree(){}

void Graph::printGraphTraversal(){
    for(auto& elem : m_vertices){
        std::cout << elem.first << " : " << elem.second->to_string() << std::endl;
    }
}

std::string Graph::to_string(std::string sep){
    std::string result = "";
    for (auto elem : m_vertices){
        result += elem.second->to_string(" ") + sep;
    } 
    return result;
}

void Graph::menu(){
    bool select_on {true};
    int selection = 0;
    std::string name;
    while(select_on){
        std::cout << "\n1. Add Vertex\n2. Remove Vertex\n3. Print Graph Vertices\n4. Exit\n" << std::endl;
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
