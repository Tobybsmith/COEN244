#include "headers/Node.h"
#include "headers/Edge.h"
#include "headers/Graph.h"
#include <vector>
#include <iostream>



Node::Node()
{
    //Default should be value of 0 (int), index of the next index in the list, and no edges
    //which is tricky :(
}
Node::Node(Graph *g)
{
    std::vector<Edge*> list;
    Node(g->nextAvaliableIndex(), list, 0);
}
Node::Node(Graph *g, int val)
{
    std::vector<Edge*> list;
    std::cout<<g->nextAvaliableIndex()<<std::endl;
    Node(g->nextAvaliableIndex(), list, val);
}
Node::Node(Graph *g, std::vector<Edge*> edgeListIn)
{
    Node(g->nextAvaliableIndex(), edgeListIn, 0);
}
Node::Node(int indexIn, std::vector<Edge*> edgeListIn, int valueIn)
{
    edgeList = edgeListIn;
    index = indexIn;
    value = valueIn;
    std::cout<<index<<" "<<value<<std::endl;
}
std::vector<Edge*> Node::getEdgeList()
{
    return edgeList;
}
int Node::getIndex()
{
    return index;
}
int Node::getValue()
{
    return value;
}