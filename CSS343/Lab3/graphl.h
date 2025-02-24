//////////////////////////////  graphl.h file  ///////////////////////////////
// an incomplete graphl class that implements diakstras algorithm without 
// adding edges, removing edges, or graph comparisons
#ifndef GraphL_H
#define GraphL_H
#include <iostream>
#include <climits>
#include <fstream>
#include "nodedata.h"
#include <sstream>
#include <vector>
#include <list>
using namespace std;

// ADT Graph: A data structure representing a graph with nodes and edges
// Implemented Dijkstra's algorithm for finding shortest paths between nodes
//
// Implementation and Assumptions:
// -- Implemented as an adjacency list representation of a graph
// -- Nodes are numbered from 1 to size
// -- Each node can have multiple edges connecting it to other nodes
// -- Edges are directional and have associated costs
// -- The graph is stored in an array of GraphNode objects (graphNodeArrry)
// -- Each GraphNode contains a list of edges (outgoing connections)
// -- A 2D array T is used to store distance and path information
// -- The findShortestPath method implements Dijkstra's algorithm
// -- The minDistance method is a helper function for Dijkstra's algorithm
// -- Assumes the graph is connected (all nodes are reachable)
// -- Does not handle negative edge weights
// -- The graph structure is static once initialized 
// (no dynamic node/edge addition/removal)
//----------------------------------------------------------------------------
static const int MAXNODES = 100;

struct Edge { 
int toNode, cost; // adjacent node of edge, value of the edge
};
struct GraphNode { // structs for simplicity (has no functions)
    list<Edge> edges;// list of edges (edge nodes), the adjacent graph nodes
    NodeData data; // information on the graph node
};
class GraphL {
public: 
    //Constructor and Destructor
    GraphL(); 
    ~GraphL();

     //grabs input from file, assumes all data is correct
    void buildGraph(istream& );
    void findShortestPath(); //implements diakstras algorithms
    void displayAll() const; //displays all paths from each node
    void display(int, int) const; //displays path of fromNode to toNode
    void printPath(int, int) const; //helper to get path
private:
    struct TableType {
        bool visited; // whether node has been visited
        int dist; // currently known shortest distance from source
        int path; // previous node in path having min distance

    };

    //finds shortest paths for all nodes to all nodes and saves all data in T
    int minDistance(int const);
    int const inf = INT_MAX;

    int size; // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES]; // stores Dijkstra information
    GraphNode graphNodeArrry[MAXNODES]; // adjaceny list of graphNodes
};
#endif