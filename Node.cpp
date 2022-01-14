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
    path = g->getPath() + name;;
    std::ifstream file(path + ".bongo");
    std::ofstream fileIn(path + ".bongo");
    //CouldntCreateFile
    fileIn << "\n&";
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
void Node::writeLink(Node* destination, char d)
{
    std::ofstream fileOut;
    std::ofstream fileOutDest;
    //CouldntFindFile
    fileOut.open(path + ".bongo", std::ios_base::app);
    fileOutDest.open(destination->getPath() + ".bongo", std::ios_base::app);
    if(d == 'd')
    {
        fileOutDest<<"<"<<destination->getIndex()<<">"<<std::endl;
    }
    else if(d == 'b')
    {
        fileOutDest<<'<'<<this->getIndex()<<","
            <<destination->getIndex()<<">"<<std::endl;
    }
    //link format is <getter>
    //LINK 2 1
    //linking nodes 2 and 1 directionally would look like:
    //node1.bongo:
    //<2>
    //node2.bongo:
    //nothing
    //bidirectionally would look like:
    //node1.bongo:
    //<2,1>
    //node2.bongo:
    //<2,1>
    fileOutDest.close();
    fileOut.close();
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
    //CouldntFindFile
    std::ifstream file(path + ".bongo");
    std::ofstream fileOut(path + ".temp.bongo");
    //highly broken, must work on
    while(file.peek() != EOF)
    {
        std::string str;
        std::getline(file, str);
        if(file.peek() == '&')
        {
            fileOut << key << value << std::endl;
            //fileOut << "HOW DID WE GET HERE" << std::endl;
            //never reaches here on file with only one &
            //and nothing else.
        }
        fileOut << str << std::endl;
    }
    //BadFileFormatting
    file.close();
    fileOut.close();
    //delete the old and replace the temp with the old
    std::remove((path +".bongo").c_str());
    std::rename((path +".temp.bongo").c_str(), (path +".bongo").c_str());
}
std::string Node::getPath()
{
    return path;
}
Node::~Node()
{
    file.close();
    //All nodes have to be new nodes
    delete this;
}