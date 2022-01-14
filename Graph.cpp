//Actual graph code goes here
/*
    Some needed functionality:
    - Constructors (Default, and with list of nodes + edges)
    - Some way to add nodes and remove nodes
    - Some way to access an individual node (By Index)
    - Some way to access an individual edge (By it's Nodes)
    - A way to list the graph
    - Directionality VS Undirectionality (Boolean + Inherited Edge Class)
*/
#include "headers/Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
Graph::Graph(std::string n)
{
    name = n;
    bi = true;
}
Graph::Graph(std::string n, bool dir)
{
    //done, creates and empty graph
    name = n;
    bi = dir;
    path = name;
    std::filesystem::create_directory(path);
    path = path + "\\";
}
Graph::Graph(std::vector<Edge*> edgeList, std::vector<Node*> nodeList, std::string n)
{
    //default to a bi-directional graph
    edges = edgeList;
    nodes = nodeList;
    bi = true;
    name = n;
}
Graph::Graph(std::vector<Edge*> edgeList, std::vector<Node*> nodeList, bool dir, std::string n)
{
    //going from one vector of pointers to another 
    edges = edgeList;
    nodes = nodeList;
    bi = dir;
    name = n;
}
int Graph::nextAvaliableIndex()
{
    return nodes.size();
}
Node* Graph::getNodeByIndex(int i)
{
    //vector of pointers
    return nodes.at(i);
}
Edge* Graph::getEdgeByNodes(Node *h, Node *t)
{
    std::pair<Node*, Node*> target;
    target = std::make_pair(h, t);
    //iterate through edges on the head node looking for the edge: (head, tail)
    for(int i = 0; i < h->getEdgeList().size(); i++)
    {
        //node.vector_of_EdgeObjects.Edge_Object.pair<>
        if(h->getEdgeList().at(i)->getPairOfNodes() == target)
        {
            //Node.vector_of_Edges.EdgeObject
            return h->getEdgeList().at(i);
        }
    }
}
Edge* Graph::getEdgeByIndexes(int h, int t)
{
    std::pair<int, int> target;
    target = std::make_pair(h, t);
    for(int i = 0; i < nodes.size(); i++)
    {
        for(int j = 0; j < nodes.at(i)->getEdgeList().size(); j++)
        {
            //Node.vector_of_Edge.Edge.pair<>
            if(nodes.at(i)->getEdgeList().at(i)->getPairOfIndexes() == target)
            {
                //Node.vector_of_Edge.Edge
                return nodes.at(i)->getEdgeList().at(i);
            }
        }
    }
}
bool Graph::getDirectionality()
{
    return bi;
}
void Graph::addNode(Node *n)
{
    //adds the new node to the node list of the graph
    nodes.push_back(n);
    for(int i = 0; i < n->getEdgeList().size(); i++)
    {
        //adds all the edges the node has to the master graph
        edges.push_back(n->getEdgeList().at(i));
    }
}
void Graph::addEdge(Edge *e)
{
    edges.push_back(e);
}
void Graph::display()
{
    std::cout<<"Nodes:"<<std::endl;
    for(int i = 0; i < nodes.size(); i++)
    {
        std::cout << "Node Name: " << nodes.at(i)->getName() << 
            ". Node Index: " << nodes.at(i)->getIndex() << std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Links:"<<std::endl;
    for(int i = 0; i < edges.size(); i++)
    {
        printPair(edges.at(i)->getPairOfIndexes());
        std::cout<<std::endl;
    }
}
void Graph::display(Node *n)
{
    int index = n->getIndex();
    std::cout << 
    "Name of node is: " << n->getName() 
        << ". Index of node is: " << index << std::endl;
}
void Graph::printPair(std::pair<int, int> p)
{
    std::cout << "<" << p.first << ", " << p.second << ">";
}
std::vector<Node*> Graph::getNodeList()
{
    return nodes;
}
std::vector<Edge*> Graph::getEdgeList()
{
    return edges;
}
void Graph::remove(std::pair<int, int> indexes)
{
    for(int i = 0; i < edges.size(); i++)
    {
        if(edges.at(i)->getPairOfIndexes() == indexes)
        {
            edges.erase(edges.begin() + i);
        }
    }
}
void Graph::remove(int i)
{
    nodes.erase(nodes.begin() + i);
    //must reindex all the other nodes
    for(int i = 0; i < nodes.size(); i++)
    {
        nodes.at(i)->setIndex(i);
    }
}
std::string Graph::getName()
{
    return name;
}
int Graph::getIndexFromName(Node *n)
{
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes.at(i)->getName() == n->getName())
        {
            return n->getIndex();
        }
    }
}
//works somehow
void Graph::loadGraphFromFile(std::string n)
{
    file.open(n+".bongodb");
    std::string listOfNodes;
    getline(file, listOfNodes);
    std::cout<<listOfNodes<<std::endl;
    std::istringstream iss(listOfNodes);
    do {
        std::string token;
        iss >> token;
        Node *n = new Node(this, token);
        nodes.push_back(n);
    } while(iss);
    file.close();
}
std::string Graph::getPath()
{
    return path;
}