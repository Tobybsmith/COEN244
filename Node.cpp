#include "headers/Node.h"
#include "headers/Edge.h"
#include "headers/Graph.h"
#include <vector>
#include <iostream>

//CONTAINS
/*
    - int index
    - int value
    - vector<Edge*> edgeList
*/

Node::Node()
{
    //Default should be value of 0 (int), index of the next index in the list, and no edges
    //which is tricky :(
}
Node::Node(Graph *g)
{
    //works
    index = g->nextAvaliableIndex();
    //no edgelist, no value
    value = 0;
}
Node::Node(Graph *g, int val)
{
    //works
    index = g->nextAvaliableIndex();
    //no edgelist
    value = val;
}
Node::Node(Graph *g, std::vector<Edge*> edgeListIn)
{
    index = g->nextAvaliableIndex();
    edgeList = edgeListIn;
    value = 0;
}
Node::Node(int indexIn, std::vector<Edge*> edgeListIn, int val)
{
    edgeList = edgeListIn;
    index = indexIn;
    value = val;
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
void Node::setValue(int toSet)
{
    value = toSet;
}
void Node::setIndex(int toSet)
{
    index = toSet;
}
Node::~Node()
{
    delete this;
}