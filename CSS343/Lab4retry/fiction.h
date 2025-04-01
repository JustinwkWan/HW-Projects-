//////////////////////////////  Fiction.h file  ///////////////////////////////
// A publication type. Fiction books
#ifndef FICTION_H
#define FICTION_H
#include "publication.h"
class Library;
//----------------------------------------------------------------------------
// Implementation and assumptions 
// Inherits from publication class 
// Represents fiction books inside the library
// Sorts fiction by author then title 
// Assumes that the set Data and set Sorting data come in a specific order 
//----------------------------------------------------------------------------
class Fiction : public Publication { 
    public: 
        Fiction(); // constructor
        virtual ~Fiction(); //destructor
        virtual bool setData(istream&); // sets data 
        virtual bool setSortingData(istream&); //sets only sorting data
        virtual NodeData* create() const; // creates new Fiction object
        // true if two books are equal 
        virtual bool operator==(const NodeData&) const;
        virtual bool operator>(const NodeData&) const; // lhs > rhs 
        virtual bool operator<(const NodeData&) const; // lhs < rhs
        virtual void display() const; // display children object information
        virtual void displayInfo() const; //displays info about pubtype 
        virtual void displayHeading() const;
    private: 
    string author, title;
    int year;
    
};
#endif