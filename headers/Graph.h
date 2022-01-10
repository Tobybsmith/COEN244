#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
class Node;
class Edge;
class Graph{
    private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    bool bi;
    public:
    Graph();
    Graph(std::vector<Edge*>, std::vector<Node*>);
    Graph(std::vector<Edge*>, std::vector<Node*>, bool);
    int nextAvaliableIndex();
    Node* getNodeByIndex(int);
    Edge* getEdgeByNodes(Node*, Node*);
    Edge* getEdgeByIndexes(int, int);
    std::vector<Node*> getNodeList();
    std::vector<Edge*> getEdgeList();
    bool getDirectionality();
    void addNode(Node*);
    void display();
    void printPair(std::pair<int, int>);
};
#endif