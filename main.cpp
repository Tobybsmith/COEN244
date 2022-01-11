#include <iostream>
#include "headers/Edge.h"
#include "headers/Node.h"
#include "headers/Graph.h"
#include <string>

//TODO
//-remove deletion, links can be deleted but not nodes
//-start using files with key-value pairs to make database
//-actually do something with direction
//-from a node, list all paths from that node
//-display all paths on a graph
//-gain the index of a node from it's val

using namespace std;
//this is my relational database :)
int main()
{
    //this program creates and manipulates the graph
    //Graph* db = new Graph();
    Graph *db;
    cout << "Welcome to bongoDB!" << endl;
    cout << "type HELP for information on usage" << endl <<"> ";
    //USER MUST ADD NODE BEFORE CREATING NEXT ONE OR INDEXES SCREW UP
    while(true)
    {
        
        string command;
        cin >> command;
        if(command == "NEW")
        {
            int val;
            cin >> val;
            Node *n = new Node(db, val);
            db->addNode(n);
        }
        else if(command == "CREATE")
        {
            string name;
            cout << "Enter a database Name" << endl;
            cin >> name;
            bool dir;
            char in;
            cout << "Should the database be directed? [y,N]" << endl;
            //if 'y', then database is bidirectional
            //anything else makes it single direction.
            dir = in == 'y'
            ? true
            : false;
            db = new Graph(name, dir);
        }
        else if(command == "DISPLAY")
        {
            db->display();
        }
        else if(command == "LINK")
        {
            //should check for already existing link
            int head;
            int tail;
            cin >> head >> tail;
            Edge *e = new Edge(db->getNodeList().at(head), 
                db->getNodeList().at(tail), db->getDirectionality());
            db->addEdge(e);
        }
        else if(command == "UNLINK")
        {
            //works perfectly
            int head;
            int tail;
            cin >> head;
            cin >> tail;
            pair<int, int> target = make_pair(head, tail);
            for(int i = 0; i < db->getEdgeList().size(); i++)
            {
                if(db->getEdgeList().at(i)->getPairOfIndexes() == target)
                {
                    db->remove(target);
                }
            }
        }
        else if(command == "QUERYN")
        {
            int index;
            cin >> index;
            db->display(db->getNodeList().at(index));
        }
        else if(command == "QUERYE")
        {
            //do stuff
        }
        else if(command == "MOD")
        {
            int index;
            int val;
            cin >> index >> val;
            db->getNodeList().at(index)->setValue(val);
        }
        else if(command == "QUIT")
        {
            break;
        }
        else if(command == "HELP")
        {
        cout << "syntax to create a new node is NEW value" << endl;
        cout << "to view nodes and links, type DISPLAY" << endl;
        cout << "to link two nodes, type LINK index1 index2" << endl;
        //cout << "to create a new database type CREATE name" << endl;
        cout << "to unlink two nodes, type UNLINK index1 index2" << endl;
        cout << "to delete a node type DEL index" << endl;
        cout << "to query the informantion about a node type QUERYN index" << endl;
        cout << "to query information about a link type QUERYL index1 index2" << endl;
        cout << "to change information about a node, type MOD index new_value" << endl;
        cout << "to quit, type QUIT" << endl;
        }
        else
        {
            cout << "Invalid Command, use HELP to see a list of commands and their usages."<<endl;
        }
        
    }
    db->display();
}