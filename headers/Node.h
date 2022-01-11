#ifndef NODE_H
#define NODE_H
#include <vector>
#include "Edge.h"
#include "Graph.h"
#include <string>
#include <fstream>
class Edge;
class Graph;
class Node
{
    private:
    //dont ever change this
    int index;
    std::fstream file;
    std::vector<Edge*> edgeList; 
    std::string name;
    public:
    //default, index no value, index and edges no value, index edges value
    Node();
    Node(Graph*);
    Node(Graph*, std::string);
    Node(Graph*, std::vector<Edge*>);
    Node(int, std::vector<Edge*>, int);
    //getters, no need for setters
    int getIndex();
    void setIndex(int);
    std::string getName();
    void setName(std::string);
    std::vector<Edge*> getEdgeList();
    void writeLink(Node*);
    void writePair(std::pair<std::string, std::string>);
    ~Node();
};
#endif