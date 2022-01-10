#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
#include "Graph.h"
class Node;
class Graph;
class Edge{
    private:
    //makes sense as a way to represent it;
    std::pair<int, int> edgeIndexes;
    std::pair<Node*, Node*> edgeNodes;
    bool bi;
    public:
    //just does nothing
    Edge();
    //a constructor to add an edge between a specified node and the most recent one (Highest index)
    Edge(Node*, Graph*);
    //edge between nodes
    Edge(Node*, Node*);
    //same as above two but for direction
    Edge(Node*, Node*, bool);
    Edge(Node*, Graph*, bool);
    std::pair<Node*, Node*> getPairOfNodes();
    std::pair<int,int> getPairOfIndexes();
    bool getDirectionality();
    //delete node
    void remove(Graph);
};
#endif