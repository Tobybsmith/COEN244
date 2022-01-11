#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <string>
class Node;
class Edge;
class Graph{
    private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    std::string name;
    bool bi;
    public:
    Graph(std::string, bool);
    Graph(std::vector<Edge*>, std::vector<Node*>, std::string);
    Graph(std::vector<Edge*>, std::vector<Node*>, bool, std::string);
    int nextAvaliableIndex();
    Node* getNodeByIndex(int);
    Edge* getEdgeByNodes(Node*, Node*);
    Edge* getEdgeByIndexes(int, int);
    std::vector<Node*> getNodeList();
    std::vector<Edge*> getEdgeList();
    bool getDirectionality();
    void addNode(Node*);
    void addEdge(Edge*);
    void display();
    void display(Node*);
    void printPair(std::pair<int, int>);
    void remove(std::pair<int, int>);
    void remove(int);
};
#endif