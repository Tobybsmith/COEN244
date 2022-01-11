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

Graph::Graph(std::string n, bool dir)
{
    //done, creates and empty graph
    name = n;
    bi = dir;
}
Graph::Graph(std::vector<Edge*> edgeList, std::vector<Node*> nodeList, std::string n)
{
    //default to a bi-directional graph
    edges = edgeList;
    nodes = nodeList;
    bi = true;
    name= n;
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
        Node current = *nodes.at(i);
        for(int j = 0; j < current.getEdgeList().size(); j++)
        {
            //Node.vector_of_Edge.Edge.pair<>
            if(current.getEdgeList().at(i)->getPairOfIndexes() == target)
            {
                //Node.vector_of_Edge.Edge
                return current.getEdgeList().at(i);
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
        std::cout << "Node Index: " << nodes.at(i)->getIndex() 
        << " Node Value: " << nodes.at(i)->getValue() << std::endl;
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
    std::cout << "Index of node is: " << index
    << ", Value of node is: " << n->getValue() << std::endl;
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