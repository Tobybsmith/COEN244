#ifndef NODE_H
#define NODE_H
#include <vector>
#include "Edge.h"
#include "Graph.h"
class Edge;
class Graph;
class Node
{
    private:
    //dont ever change this
    int index;
    int value;
    std::vector<Edge*> edgeList; 
    public:
    //default, index no value, index and edges no value, index edges value
    Node();
    Node(Graph*);
    Node(Graph*, int);
    Node(Graph*, std::vector<Edge*>);
    Node(int, std::vector<Edge*>, int);
    //getters, no need for setters
    int getIndex();
    int getValue();
    void setValue(int);
    void setIndex(int);
    std::vector<Edge*> getEdgeList();
    ~Node();
};
#endif