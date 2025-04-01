//////////////////////////////  Command.h file  ///////////////////////////////
// Abstract class. Parent class of all commands that a client can call. 
#ifndef COMMAND_H
#define COMMAND_H
#include "command.h"
class Library;
using namespace std;
#include <iostream>
#include <string>
//----------------------------------------------------------------------------
// Implementation and Assumptions
// Made functions pure virtual that have to be implemented by each child
// Assumes that children will all have a task to perform
//---------------------------------------------------------------------------- 
class Command {
    public:
        Command() { } // constructor
        virtual ~Command() { } // virtual destrcutor
        virtual Command* create() const = 0; // commandfactory create 
        virtual void display() const = 0; // output to console
        // task that is done inside each command
        virtual bool performTask(Library&, istream&) = 0; 
};
#endif