//////////////////////////////  checkout.h file  /////////////////////////////
// Checks out a book from the library to the client. 
#ifndef CHECKOUT_H
#define CHECKOUT_H 
#include "command.h"
#include <string>
class Client; 
class NodeData; 
class PublicationFactory; 

//----------------------------------------------------------------------------
// Implementation and assumptions
// Inherited methods from command class
// We assume that the library has the correct publications and clients 
// include of library to access their data members
//
//----------------------------------------------------------------------------
class CheckOut : public Command {
    private: 
        int ID; 
        Client* client;
        NodeData* book;
    public: 
        virtual ~CheckOut(); // destructor
        // factory create of checkout command
        virtual Command* create() const; 
        virtual void display() const; // output to console
        virtual bool performTask(Library&, istream&); // checkout book
};
#endif