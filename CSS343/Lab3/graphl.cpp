#include "graphl.h"

//----------------------------------------------------------------------------
// constructor
// initailzes a graph with default values
GraphL::GraphL() {

    //Initalizing all nodes up to maxnodes(100)
    for(int i = 1; i < MAXNODES; i++) {

        //For all possible edges, set default values
        for(int j = 0; j < MAXNODES; j++) {
            T[i][j].visited = false; //Node is unvisited
            T[i][j].dist = inf; //Distance is infinity
            T[i][j].path = 0; //no path
        }
          graphNodeArrry[i].data;
    }
 }

 //----------------------------------------------------------------------------
 // destructor:no dynamic memory so no need to do anything
GraphL::~GraphL() {}

//----------------------------------------------------------------------------
// buildgraph
// Assume that incoming data is correct, 0 0 0 breaks out of file
void GraphL::buildGraph(istream& infile) {
   int fromNode, toNode, value;   // from, to node ends and value of edge

   infile >> size;                // read the number of nodes
   if (infile.eof()) return;      // stop reading if no more data

   string s;                      // used to read to end of line holding size
   getline(infile, s);         // essentially throw away chars after size

   // read graph node information
   for (int i=1; i <= size; i++) {  
    graphNodeArrry[i].data.setData(infile);
   }

   // adds all self edges
    for(int i = 1; i <= size; i++) {
        Edge inEdge; 
        inEdge.toNode = i;
        inEdge.cost = 0;
        graphNodeArrry[i].edges.push_back(inEdge);
    }
   // read the edge data and add to the adjacency list
   for (;;) {
      infile >> fromNode >> toNode >> value;
      if (fromNode == 0) return;    // end of edge data
      Edge inEdge;
      inEdge.toNode = toNode;
      inEdge.cost = value;
      // if valid, put into the adjacency edge STL list for fromNode
      if(inEdge.cost > 0 && toNode <= size) {
        graphNodeArrry[fromNode].edges.push_back(inEdge);
      }
   }

}

//----------------------------------------------------------------------------
// displayAll 
// displays to console all shortest paths from each node if applicable
void GraphL::displayAll() const{
    cout << "Description\t\tFrom Node\tTo Node\tDijkstra's Path" << endl;
    for(int source = 1; source <= size; source++) {
        
        //for each node
        cout << graphNodeArrry[source].data << endl;
        for(int i = 1; i <= size; i++) {
            if(source == i) {continue;} //no need to output to itself 
            cout << "\t\t\t " << source << "\t\t " << i << "\t";
            if(T[source][i].dist == inf) { // dont print path if unaviable
                cout << "---" << endl;
            } else {
                
                //printing dijkstras number as well as path
                cout << T[source][i].dist << "\t   ";
                printPath(source, i);
                cout << endl;
            }
        }
    } 
}

//----------------------------------------------------------------------------
// printPath
// finds the path that dijkstra's algorithm took starting from the toNode
// backtracing until the fromNode is hit, printing out the path
void GraphL::printPath(int fromNode, int toNode) const {
    int path[MAXNODES]; 
    path[0] = toNode; //inital index
    int index = 1; 
    
    //if there exist a path and the path isn't equal to 0
    if(T[fromNode][toNode].dist != inf && T[fromNode][toNode].dist != 0 ) {
        while(toNode != fromNode) { //iterate though until all nodes are found
            path[index] = T[fromNode][toNode].path;
            toNode = path[index++];
        }
        for(int i = index - 1; i >= 0; i--) { // print path to console
            cout << path[i] << " ";
        }
    }
}

//----------------------------------------------------------------------------
// display 
// displays to console dijkstra's and path of dijkstras of the input nodes
void GraphL::display(int fromNode, int toNode) const{
    if(!T[fromNode][toNode].visited) { //if not valid
        cout << "No connection" << endl;
    } else { 
        //output dijkstas and path to console
        cout << fromNode << "\t" << toNode << "\t" 
        << T[fromNode][toNode].dist; 
        printPath(fromNode,toNode);

    }
}

//----------------------------------------------------------------------------
// findShortestPath
// implementation of dijkstras algorithm to find shortest path from each 
// node to the next. Updates the distance and path if a shorter way is found
void GraphL::findShortestPath() {
    
    //iterate though all nodes as source 
    for(int source = 1; source < size + 1; source++) {
        
        //setting distance from source to itself to 0
        T[source][source].dist = 0; 
        for(int i = 1; i < size + 1; i++) {
            //find a unvisted node with minimum distance from source
            int v = minDistance(source);
            if(v == -1) {continue;}
            T[source][v].visited = true;

            //for all edges adjacent to v
            for(Edge& edge: graphNodeArrry[v].edges) {              
                int w = edge.toNode;
                int cost = edge.cost;

                //if an adjacent node is both unvisited and has a shorter 
                //path, update the path and distance
                if(!T[source][w].visited &&
                 T[source][v].dist + cost < T[source][w].dist) {
                    T[source][w].dist = T[source][v].dist + cost;
                    T[source][w].path = v;
                }
            }
        }
   }
}

//----------------------------------------------------------------------------
// minDistance
// Helper function for Dijkstra's algorithm. Finds the unvisited node with the
// minimum distance from the source node. It also updates direct connections
// from the source if a shorter path is found.
// 
// @param source: The source node from which to find the minimum distance
// returns the index of the node with minimum distance, or -1 if none found
int GraphL::minDistance(int const source) {
    int min = inf; 
    int minIndex = -1;

     // Iterate through all edges from the source node
    for(Edge& edge : graphNodeArrry[source].edges) { 
        int toNode = edge.toNode;
        int cost = edge.cost;

        // Update distance if a shorter direct path is found
        if(T[source][toNode].dist > cost) {
            T[source][toNode].dist = cost;
            T[source][toNode].path = source;
        }

        // Find the unvisited node with minimum distance
        if(!T[source][toNode].visited && T[source][toNode].dist < min) {
            min = cost; 
            minIndex = toNode;
        }
    }
    // Return index of node with minimum distance, or -1 if none found
    return minIndex;
}