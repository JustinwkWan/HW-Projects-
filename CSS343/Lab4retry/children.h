//////////////////////////////  Children.h file  ///////////////////////////////
// A publication type. Childrens books
#ifndef CHILDREN_H
#define CHILDREN_H
#include "publication.h"
//----------------------------------------------------------------------------
// Class Children
// Implementation and Assumptions
// Inherits from publication class
// Represents Childrens book inside the library
// Sorts children by title then author
// Assumes that the set Data and set Sorting data come in a specific order 
//----------------------------------------------------------------------------
class Children : public Publication {
    public:
        Children(); // constructor
        virtual ~Children(); // destructor
        virtual bool setData(istream&); // sets data 
        virtual bool setSortingData(istream&); //sets only sorting data
        virtual NodeData* create() const; // creates new Children object
        // true if two books are equal 
        virtual bool operator==(const NodeData&) const;
        virtual bool operator>(const NodeData&) const; // lhs > rhs 
        virtual bool operator<(const NodeData&) const; // lhs < rhs
        virtual void display() const; // display children object information
        virtual void displayInfo() const; //displays info about children book
        virtual void displayHeading() const; // displays heading 
    private: 
    string title, author;
    int year;
};

#endif