//////////////////////////////  BinTree.h file  ///////////////////////////////
// A binary search tree using Node as left and right child
#ifndef BinTree_H
#define BinTree_H
#include <iostream>
#include "nodedata.h"
#include <sstream>
using namespace std;

//----------------------------------------------------------------------------
// Class BinTree
//ADT BST: A top down data structure that keeps data sorted from smallest
// on lhs of tree to largest on rhs
// Implemented insertion, deletion, and standard search operations
//
// Implementation and Assumptions:
// --Implemented as a Binary Search Tree with each node having two children
// -- left subtree only has nodes smaller than root
// -- right subtree only has nodes larger than root
// -- no duplicated are allowed, if you try to insert a duplicate,
// the node doesn't get inserted 
// The tree doesn't self balance so it may be unbalanced depending on root
// insert deletes node incoming node if incoming NodeData is a duplicate
// Node only holds data from nodedata
//
// ----------------------------------------------------------------------------

class BinTree { 
public:
    BinTree();                //constructor
    BinTree(const BinTree &); //copy constructor
    ~BinTree();               //destructor, calls makeEmpty()

    bool isEmpty() const;     //is list Empty?
    void makeEmpty();         // delete all memory so isEmpty() returns true

    BinTree& operator=(const BinTree &);    //lhs = rhs
    bool operator==(const BinTree &) const; //true if two BST are equal
    bool operator!=(const BinTree &) const; //true if two BST are not equal
    
    //Inserts a NodeData object as long as there are no duplicates
    //returns wheather successfuly inserted
    bool insert(NodeData*);  
    //Retrieve checks if Node is in BST, returns if successfully found
    bool retrieve(const NodeData&, NodeData*&) const;
    //Removes Node if inside tree, returns false if node not in BST
    //returns wheather successfully removed
    bool remove(const NodeData &, NodeData*&);

    void displaySideways() const; // displays the tree sideways, root is leftmost
    //Transfers BST to an inorder Array, leaves BST empty
    void bstreeToArray(NodeData* []); 
    //Transfers Array to an inorder BST
    void arrayToBSTree(NodeData* []);

    //gets the sibling of Node if in BST
    //returns if node successfully is found and if it has a sibling
    bool getSibling(const NodeData&, NodeData&) const;
    //gets the parent of Node if in BST
    //returns if node is successfully found, if target is root is false
    bool getParent(const NodeData&, NodeData&) const; 

    friend ostream& operator<<(ostream &os, const BinTree &tree);
private:
struct Node {
    NodeData* data; // pointer to data object
    Node* left; // left subtree pointer
    Node* right; // right subtree pointer
};
Node* root = nullptr; // root of the tree

// utility functions
//----------------------------------------------------------------------------
// recursive helper for operator<<
void inorderHelper( ostream&, const Node* ) const; 

void sidewaysHelper(Node*, int) const; // recursive helper for displaySideways
// recursive helper for operator== 
bool equalHelper(const Node*,const Node*) const; 
// recursive helper for remove
bool removeHelper(Node*& current, const NodeData& target, NodeData* &); 
// recursive helper for makeEmpty
void deleteArrHelper(Node*);
// recursive helper for both copy constructor and operator=
void copyHelper(Node* &, const Node*);
// deletes current node and replaces node if it has kids
void deleteCurrent(Node*&,  NodeData* &);
// helper to delete a node with two children
NodeData* findAndDeleteJustBigger(Node*&);
// recursive helper for getParent
bool parentHelper(const Node*, const NodeData& , NodeData&) const; 
// recursive helper for getSibling
bool siblingHelper(const Node*, const NodeData& , NodeData&) const; 
// recursive helper for bstreeToArray to transfer NodeData 
// from BST to Array and leaves BST empty
void inOrderBSTToArr(int&, Node* &, NodeData* []);
//recursive helper for arrayToBSTree to transfer NodeData
// from array to a balanced BST
Node* inOrderArrToBSTreeHelper(NodeData* [], int, int );
};

#endif