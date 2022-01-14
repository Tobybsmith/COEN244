#include <iostream>
#include "headers/Edge.h"
#include "headers/Node.h"
#include "headers/Graph.h"
#include <string>
#include <fstream>

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
    cout << "type HELP for information on usage" << endl;
    //USER MUST ADD NODE BEFORE CREATING NEXT ONE OR INDEXES SCREW UP
    while(true)
    {
        cout << ">  ";
        string command;
        cin >> command;
        //this will all get redone
        //to be better
        if(command == "NEW")
        {
            cout << "You must post information to the "
            << "node in order to save it using POST"
            << ". Empty files will not be saved by the sytem."<<endl;
            cout << "Enter a node name: "<<endl;
            string name;
            cin >> name;
            Node *n = new Node(db, name);
            db->addNode(n);
            ofstream dbFile;
            //opens the file to append it instead of overwrite it
            dbFile.open(db->getPath()+db->getName() + ".bongodb", ios_base::app);
            dbFile << n->getName() << " ";
            //CouldntCreateNode
        }
        else if(command == "LOAD")
        {
            cout << "Enter name of database to be loaded" << endl;
            string dbName;
            cin >> dbName;
            db = new Graph(dbName);
            db->loadGraphFromFile(dbName);
            //search for file named: name.bongodb
            //which will have a list of all files and links related
            //to the directory and can be loaded using the list 
            //based constructors for a graph.
            //alternate solution is to learn how to make new directories
            //and have each graph be one directory.
            //either way must iterate though files to find and load all
            //nodes and edges into the dir object being created since
            //Graph's aren't stored between launches of the program.

            //CouldntLoadDatabase
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
            ofstream file;
            file.open(db->getPath()+name+".bongodb");
            //CouldntCreateDatabase
            continue;
        }
        else if(command == "POST")
        {
            cout << "Enter index of node to be modified" << endl << ">  ";
            int index;
            cin >> index;
            cout << "Enter name of key" << endl << ">  ";
            string keyName;
            cin >> keyName;
            cout << "Enter type of data" << endl << ">  ";
            char type;
            cin >> type;
            cout << "Enter value" << endl << ">  ";
            string value;
            cin >> value;
            keyName = keyName + "?" + type;
            pair<string, string> keyval = make_pair(keyName, value);
            db->getNodeByIndex(index)->writePair(keyval);
            //CouldntFindNode
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
            //need to specify directionality of link
            db->getNodeByIndex(head)->writeLink(db->getNodeByIndex(tail), 'b');
            db->getNodeByIndex(tail)->writeLink(db->getNodeByIndex(head), 'b');
            //needs to go to the two nodes in the edge (head and tail), and write
            //the fact that it exists into their files. (indexes not names)
            //this shows this file is linked to nodes 0 and 1.
            //0 name_of_link
            //1 name_of_link
            //CouldntLinkNodes
        }
        else if(command == "UNLINK")
        {
            //will, in future, need to remove links from
            //the associated files
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
            //CouldntUnlinkNodes
        }
        //QUERY <name/index> (Standard Query) - Very Easy
        //returns the name, index, and any links
        //QUERYKV <name/index> and <key> (Query Key Value) - Moderately Easy
        //returns value from keyval pair, and -1 if no keyval pair exists
        //QUERYE <name/index> <name/index> (Query Edge) - Very Easy
        //returns whether the two nodes are linked or not
        //QUERYP <name/index> (Query Path) - Moderately Hard
        //returns all links from this node, and all links from the node's
        // it is linked to.
        //QUERYV <value> (Query Value) - Very Hard
        //returns the name of the node, and the key of that kv pair
        //if it exists at all in the database
        else if(command == "QUERYN")
        {
            int index;
            cin >> index;
            db->display(db->getNodeList().at(index));
            //CouldntFindNode
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
            //db->getNodeList().at(index)->setValue(val);
        }
        else if(command == "QUIT")
        {
            break;
        }
        else if(command == "HELP")
        {
            //outdated, must update.
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