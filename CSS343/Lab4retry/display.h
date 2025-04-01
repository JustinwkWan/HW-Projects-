//////////////////////////////  Display.h file  ///////////////////////////////
// Child of Command. Displays all publications to client.
#ifndef DISPLAY_H
#define DISPLAY_H
#include "command.h"
//----------------------------------------------------------------------------
// Implmentation and assumptions
// Inherits pure virtutal methods from command class 
// Implements the display function of the library 
// Assumes that library has access to publications
//----------------------------------------------------------------------------
class Display : public Command {
    public: 
    virtual ~Display(); // deconstructor
    virtual Command* create() const; // commandfactory create of display
    virtual void display() const; // output to console
    // prints all publications 
    virtual bool performTask(Library&, istream&); 
};
#endif 