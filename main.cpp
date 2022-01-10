#include <iostream>
#include "headers/Edge.h"
#include "headers/Node.h"
#include "headers/Graph.h"

using namespace std;
//this is my relational database :)
int main()
{
    //this program creates and manipulates the graph
    cout << "Hello World" << endl;
    Graph* db = new Graph();
    //stuck at 1
    //indexes rn are memeory addresses and not fixed numbers
    Node node1 = Node(db, 5);
    Node node2 = Node(db, 5);
    Edge e1 = Edge(&node1, &node2, false);
    db->addNode(&node1);
    db->addNode(&node2);
    db->display();
}