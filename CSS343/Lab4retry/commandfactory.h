//////////////////////////////  CommandFactory.h file  ///////////////////////
// A factory that creates commands
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include "checkout.h"
#include "return.h"
#include "display.h"
#include "history.h"
//----------------------------------------------------------------------------
// Implementation and Assumptions
// Implements the factory design method to create command objects 
// Implements 4 commands but has the ability to go up to 26 based on the 
// letter coming in. 
// All unused command slots will not initiaze and set to nullptr
//----------------------------------------------------------------------------
class CommandFactory {
    public:
        CommandFactory();        //constructor
        ~CommandFactory();       //deconstructor 
        Command* createCommand(const char&); //returns the command of comtype
    private: 
        Command* comFactory[26]; 
        int hash(char ch) const {return ch-'A'; }
};
#endif