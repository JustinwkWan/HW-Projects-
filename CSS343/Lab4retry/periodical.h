//////////////////////////////  Periodical.h file  ///////////////////////////////
// A publication type. Periodical books
#ifndef PERIODICAL_H
#define PERIODICAL_H
#include "publication.h"
//----------------------------------------------------------------------------
// Implementation and Assumptions
// Inherits from Publication class 
// Sorts data from year data then title
// Represents periodical books in the library
// Assumes that the set Data and set Sorting data come in a specific order 
//----------------------------------------------------------------------------
class Periodical : public Publication { 
    public: 
        Periodical(); // constructor
        virtual ~Periodical(); // destructor
        virtual bool setData(istream&); // sets data 
        virtual bool setSortingData(istream&); //sets only sorting data
        virtual NodeData* create() const; // creates new Periodical object
        // true if two books are equal 
        virtual bool operator==(const NodeData&) const;
        virtual bool operator>(const NodeData&) const; // lhs > rhs 
        virtual bool operator<(const NodeData&) const; // lhs < rhs
        virtual void display() const; // display periodical object information
        //display periodical info to display command
        virtual void displayInfo() const; 
        virtual void displayHeading() const; // displays heading
    private: 
    string title;
    int month, year;
};
#endif