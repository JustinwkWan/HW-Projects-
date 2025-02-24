//////////////////////////////  graphm.h file  ///////////////////////////////
// an incomplete graphm class that implements depth first search algorithm 
#ifndef GraphM_H
#define GraphM_H
#include <iostream>
#include <climits>
#include <fstream>
#include "nodedata.h"
#include <sstream>
#include <vector>
#include <list>

//----------------------------------------------------------------------------
// Class GraphM
// ADT Graph: A data structure representing an unweighted, undirected graph 
// with nodes and edges
// Implements depth-first search traversal of the graph
//
// Implementation and Assumptions:
// -- Uses an adjacency matrix representation of the graph
// -- Nodes are numbered from 0 to size-1 (maximum MAXNODESM-1)
// -- Each node contains data stored in a NodeData object
// -- Edges are undirected and unweighted 
// (represented by boolean values in the matrix)
// -- Graph is stored in a 2D array 'matrix' of size MAXNODESM x MAXNODESM
// -- NodeData array 'data' stores information for each node
// -- Boolean array 'visited' is used for depth-first search traversal
// -- Assumes input data for buildGraph is correct
// -- Graph structure is static once initialized 
// (no dynamic node/edge addition/removal)
// -- Does not implement weighted edges or directed edges
//----------------------------------------------------------------------------
static const int MAXNODESM = 100;
class GraphM {
    public:
    // constructor and destructor
        GraphM();
        ~GraphM();
        // -- buildGraph constructs the graph from input data
        void buildGraph(istream&); 
        // -- displayGraph shows the current state of the graph
        void displayGraph();
        // -- depthFirstSearch performs a depth-first traversal of the graph
        void depthFirstSearch();
    private:
        void dfsHelper(int); // recursive helper that iterates till end nodes
        NodeData data[MAXNODESM]; // graph node data information, at most 100 nodes
        bool visited[MAXNODESM]; // for depth-first, whether visited
        int matrix[MAXNODESM][MAXNODESM]; // adjacency matrix for edges
        int size; // number of nodes in the graph
};
#endif