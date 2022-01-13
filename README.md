# BongoDB
This is my database for my COEN244 project. It is supposed to be a graph database using nodes and edges.

//TODO
- ~~Files dont get created by constructor.~~
- ~~Be able to load a database from it's .bongobd file~~
- Be able to write key-val pairs to a node's file
- Be able to load key-val pairs from node's .bongo file
- - Need to write change to file before a &
- - Need to create temp copy and rename after
- - Way to copy nodes with or without copying links
- Be able to use links to access content from other linked .bongo files
- Make the UX not garbage
- Make it not crash and warn user instead when bad things happen
- Revamp commands and functionality
- Find a way to create directories and use them to store databases in their own directories
# Long Term Goals
//TODO
- More features like copying nodes, deleting nodes maybe, and showing links between nodes
- Types need to work, but why
- Database needs to be better and have some way to access it via code
# Commands
- CREATE <name> 
- - Creates a new empty database with name <name>
- NEW <name>
- - Creates a new node with name <name> and auto-assigned index
- INSERT <name> <key> <type> <value>
- - Creates a new key-value pair in the node <node>
- - Type must be specified, default type is string
- LINK <name> <name>
- - Links two nodes together, can optionally be specified as either directional or bi-directional
- - Linked nodes have access to eachother through a special data type in the underlying document
- UNLINK <name> <name>
- - Unlinks the two named nodes
- - Removes any instances of data from the linked node in the other node's underlying document
- LOAD <name>
- - Loads a database, all the nodes, and all the links into the current working database
- HELP
- - Lists all the commands and args
- QUIT
- - Saves and quits the database and ends the program
- LQUIT <name>
- - Saves and quits the current database and loads the named database
- QUERY <name>
- - Lists the name, internal index, file path, and any links of the selected node
- QUERYKV <name> <key>
- - Lists the value from the key in the named node
