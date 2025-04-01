//////////////////////////////  history.h file  /////////////////////////////
// returns the checkout and return history of a client
#ifndef HISTORY_H
#define HISTORY_H
#include "command.h"
#include <string>
class Client;
class Library;
class PublicationFactory;
//----------------------------------------------------------------------------
// Implementation and assumptions
// calls the clients displayHistory to output to console
// Since we do not want history commands in the history, 
// we return performtask as false so it gets deleted before getting inserted
// into the array
// we assume that client will have data to output
//----------------------------------------------------------------------------
class History: public Command {
    private: 
    int id;
    Client* client;
    public:
        virtual ~History();
        virtual Command* create() const;
        virtual void display() const;
        virtual bool performTask(Library&, istream&);
};
#endif