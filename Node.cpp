#include "headers/Node.h"
#include "headers/Edge.h"
#include "headers/Graph.h"
#include <vector>
#include <iostream>
#include <string>

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
    name = std::to_string(index);
}
Node::Node(Graph *g, std::string n)
{
    //works
    index = g->nextAvaliableIndex();
    //no edgelist
    name = n;
    std::fstream file(name+".bongo");
    std::cout<<name<<std::endl;
}
Node::Node(Graph *g, std::vector<Edge*> edgeListIn)
{
    index = g->nextAvaliableIndex();
    edgeList = edgeListIn;
}
Node::Node(int indexIn, std::vector<Edge*> edgeListIn, int val)
{
    edgeList = edgeListIn;
    index = indexIn;
}
std::vector<Edge*> Node::getEdgeList()
{
    return edgeList;
}
int Node::getIndex()
{
    return index;
}
std::string Node::getName()
{
    return name;
}
void Node::setName(std::string n)
{
    name = n;
}
void Node::setIndex(int toSet)
{
    index = toSet;
}
void Node::writeLink(Node* destination)
{
    file.open(name + ".bongo", std::ios_base::app);
    file << destination->getIndex() << " ";
    file.close();
}
void Node::writePair(std::pair<std::string, std::string> keyval)
{
    //key should look like name?type where type is one char
    //based on whatever i want:
    //i for int, l for long, u for ulong, s for string, c for char, b for bool
    //an example of a keyvalue with name PlayerName and type string:
    //<PlayerName?s, Elijas Pettersson>
    //Represented in Player.bongo as:
    //PlayerName?s: "Elijas Petterson"
    std::string key = keyval.first;
    std::string value = keyval.second;
    //get the char type from the last char in the key string
    char type = key.at(key.length() - 1);
    //deletes the type character
    file.open(name + ".bongo", std::ios_base::app);
    file << key <<":"<<"\""<<value<<"\""<<"\n";
    file.close();
}
Node::~Node()
{
    file.flush();
    file.close();
    delete this;
}