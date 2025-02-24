#ifndef BinTree_H
#define BinTree_H
#include <iostream>
#include "nodedata.h"
#include <sstream>
using namespace std;
//Methods I still need to do: Remove, <<, getsibling, get parent, bstarray, arraytobstree
class BinTree { // you add class/method comments and assumptions/implementation
public:
    BinTree();
    BinTree(const BinTree &);
    ~BinTree(); // calls makeEmpty()
    bool isEmpty() const;
    void makeEmpty(); // delete all memory so isEmpty() returns true
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;
    bool insert(NodeData*);
    bool retrieve(const NodeData&, NodeData*&) const;
    bool remove(const NodeData &, NodeData*&);
    void displaySideways() const; // displays the tree sideways, root is leftmost
    void bstreeToArray(NodeData* []);
    friend ostream& operator<<(ostream &os, const BinTree &tree);

    bool getSibling(const NodeData&, NodeData&) const; 
    bool getParent(const NodeData&, NodeData&) const; 


private:
struct Node {
    NodeData* data; // pointer to data object
    Node* left; // left subtree pointer
    Node* right; // right subtree pointer
};
Node* root; // root of the tree

// utility functions
void inorderHelper( ostream&, const Node* ) const; // recursive helper for operator<<
void sidewaysHelper(Node*, int) const;
bool equalHelper(const Node*,const Node*) const; 
bool removeHelper(Node*& current, const NodeData& target, NodeData* &);
void deleteArrHelper(Node*);
void copyHelper(Node* &, const Node*);
void deleteCurrent(Node*&,  NodeData* &);
NodeData* findAndDeleteJustBigger(Node*&);
};

#endif