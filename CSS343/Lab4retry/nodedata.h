#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further
class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
    NodeData(); // default constructor, data is set to an empty string
    virtual ~NodeData(); // virtual destructor
    virtual bool setData(istream&) = 0; // sets data  
    virtual bool setSortingData(istream&) = 0; // sets sorting data 
    virtual NodeData* create() const = 0; // creates a nodedata
    bool isAvalible();
    bool increment();
    bool decrement();
    //Sorting fuctions
    virtual bool operator==(const NodeData &) const = 0; //lhs == rhs
    virtual bool operator<(const NodeData &) const = 0; // lhs < rhs
    virtual bool operator>(const NodeData &) const = 0; // lhs > rhs
    virtual void display() const = 0; //displays nodedata to console
     // displays heading for each pubtype
    virtual void displayHeading() const = 0;
    //displays info about each pubtype
    virtual void displayInfo() const = 0;  
    protected: 
    string data;
    int count; 
};

#endif
