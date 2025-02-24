#include "graphm.h"
//----------------------------------------------------------------------------
// Constructor, destructor 
// Constructor sets the adjaceny matrix of all possible edges and sets 
// visited for each node to false
// destrutor does the same thing resetting the adjaceny matrix and visited 
// nodes
GraphM::GraphM() {
    for(int i = 0; i < MAXNODESM; i++) {
        for(int j = 0; j < MAXNODESM; j++) {
            matrix[i][j] = 0;
        }
        visited[i] = false;
    }
}

GraphM::~GraphM() {
    size = 0; 
    for(int i = 0; i < MAXNODESM; i++) {
        for(int j = 0; j < MAXNODESM; j++) {
            matrix[i][j] = 0; 
        }
        visited[i] = false; 
    }
}
//----------------------------------------------------------------------------
// buildGraph 
// Inputs adjacency list with cost up to 100 nodes 
// Assumption: file has correct input
void GraphM::buildGraph(istream& infile) {
    int fromNode, toNode; //link between two nodes(edge)
    infile >> size; // number of nodes
    if(infile.eof()) return;

    string s; 
    getline(infile,s);
   
   //this for loop reads the data about each node
    for(int i = 1; i <=size;i++) {
        data[i].setData(infile);
    }
    
    //add all edges to adjaceny matrix
    for(;;) {
        infile >> fromNode >> toNode;
        if(fromNode == 0) return;
        matrix[fromNode][toNode] = 1;
    }
}
//----------------------------------------------------------------------------
// displayGraph
// displays to console a list of all edges from nodes
void GraphM::displayGraph() {
    cout <<  "Graph: " << endl;

    //iterating through all nodes in graph
    for(int i = 1; i < size + 1; i++) {    
        cout << "Node " << i << "   " << data[i] << " " << endl;
        for(int j = 0; j < size + 1; j++) {
            //outputting data of each edge coming out of each node
            if(matrix[i][j] == 1) {
                cout << "edge " << i << " " << j << endl; 
            }
        }
    }
}
//----------------------------------------------------------------------------
// depthFirstSearch, dfsHelper
// preforms the depth first search algorithm and outputs results to console
// dfsHelper: recursively implements dfs
// Assumption: We are given a correct adjaceny matrix
void GraphM::depthFirstSearch() {
    cout << "Depth First Ordering: ";
    
    // as long as we haven't visited the current node yet, we follow
    // the node to the last edge
    for(int i = 1; i < size; i++) {
        if(visited[i] == false) {
              dfsHelper(i);
        }
    }
}

void GraphM::dfsHelper(int fromNode) {
    visited[fromNode] = true; // visit current node
    cout << fromNode << " "; //output node to console

    for(int i = 1; i < size + 1; i++) {
        //if the edge exsist and not been visited yet, call helper again
        if(matrix[fromNode][i] == 1 && visited[i] == false) {
            dfsHelper(i);
        }
    }
}