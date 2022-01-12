#include "headers/Node.h"
#include "headers/Edge.h"
#include "headers/Graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

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
    std::ifstream file(name + ".bongo");
    std::ofstream fileIn(name + ".bongo");
    fileIn << "&";
    fileIn.close();
    file.close();
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
    //file.open(name + ".bongo", std::ios_base::app);
    //file << destination->getIndex() << " ";
    //file.close();
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
    std::ifstream file(name+".bongo");
    std::ofstream fileOut(name+".temp.bongo");
    while(file.peek() != EOF)
    {
        std::string str;
        std::getline(file, str);
        if(file.peek() == '&')
        {
            fileOut << key << value << std::endl;
        }
        fileOut << str << std::endl;
    }
    file.close();
    fileOut.close();
    //delete the old and replace the temp with the old
    std::remove((name+".bogo").c_str());
    std::rename((name+".temp.bongo").c_str(), (name+".bongo").c_str());
}
Node::~Node()
{
    file.close();
    //All nodes have to be new nodes
    delete this;
}