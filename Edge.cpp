#include "headers/Edge.h"
#include "headers/Node.h"
#include "headers/Graph.h"

Edge::Edge()
{
    //do nothing
}
Edge::Edge(Node *n, Graph *g)
{
    //Add an edge to the latest node in graph and the node n
    //default should be bidirectional
            //Graph.Vector_Of_Nodes.Node_At_End
    
}
Edge::Edge(Node *head, Node *tail)
{
    edgeNodes = std::make_pair(head, tail);
    edgeIndexes = std::make_pair(head->getIndex(), tail->getIndex());
}
Edge::Edge(Node *n, Graph *g, bool dir)
{
    edgeNodes = std::make_pair(n, g->getNodeList().at(g->getNodeList().size()-1));
    edgeIndexes = std::make_pair(n->getIndex(), g->getNodeList().at(g->getNodeList().size()-1)->getIndex());
}
Edge::Edge(Node *head, Node *tail, bool dir)
{
    edgeNodes = std::make_pair(head, tail);
    edgeIndexes = std::make_pair(head->getIndex(), tail->getIndex());
    bi = dir;
}
std::pair<Node*, Node*> Edge::getPairOfNodes()
{
    return edgeNodes;
}
std::pair<int, int> Edge::getPairOfIndexes()
{
    return edgeIndexes;
}
bool Edge::getDirectionality()
{
    return bi;
}
Edge::~Edge()
{
    delete this;
}