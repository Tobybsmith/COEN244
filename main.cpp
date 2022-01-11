#include <iostream>
#include "headers/Edge.h"
#include "headers/Node.h"
#include "headers/Graph.h"
#include <string>

using namespace std;
//this is my relational database :)
int main()
{
    //this program creates and manipulates the graph
    //Graph* db = new Graph();
    Graph *db;
    //USER MUST ADD NODE BEFORE CREATING NEXT ONE OR INDEXES SCREW UP
    while(true)
    {
        cout << "Welcome to bongoDB!" << endl;
        cout << "type HELP for information on usage" << endl;
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
        else if(command == "DEL")
        {
            //user should not be allowed to delete a node if it has links
            //user must take care of links first.
            int index;
            cin >> index;
            if(db->getNodeByIndex(index)->getEdgeList().size() == 0)
            {
                db->remove(index);
            }
            else
            {
                cout << "You're tyring to delete a node with active links."
                << " Please delete all links related to the node before deleting the node."
                << " Use UNLINK index1 index2 or UNLINKALL index and use HELP for more information";
            }
        }
        else if(command == "UNLINKALL")
        {
            int index;
            cin >> index;
            for(int i = 0; i < db->getNodeByIndex(index)->getEdgeList().size(); i++)
            {
                //get the pair of indexes that make an edge and remove them
                db->remove(db->getNodeByIndex(index)->getEdgeList().at(i)->getPairOfIndexes());
            }
        }
        else if(command == "QUERYN")
        {
            int index;
            cin >> index;
            db->display(db->getNodeList().at(index));
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