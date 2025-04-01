//////////////////////////////  return.h file  /////////////////////////////
// Returns out a book from the library to the client. 
#ifndef RETURN_H
#define RETURN_H 
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
//----------------------------------------------------------------------------
class Return : public Command {
    private: 
        int ID; 
        Client* client;
        NodeData* book;
    public: 
        virtual ~Return(); // destructor
        // factory create of return command
        virtual Command* create() const; 
        virtual void display() const; // output to console
        virtual bool performTask(Library&, istream&); // return book
};
#endif