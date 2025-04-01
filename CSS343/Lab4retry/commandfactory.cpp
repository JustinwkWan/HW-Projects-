#include "commandfactory.h"
//----------------------------------------------------------------------------
// constructor
// iniltlizes the hashtable we are using to create commands 
// any char we are not using is set to nullptr
CommandFactory::CommandFactory() {
    for(int i = 0; i < 26; i++) {
        comFactory[i] = nullptr;
    }

    comFactory['H' - 'A'] = new History;
    comFactory['D' - 'A'] = new Display;
    comFactory['C' - 'A'] = new CheckOut;
    comFactory['R' - 'A'] = new Return;
}
//----------------------------------------------------------------------------
// deconstructor
// deletes all commands and sets to nullptr
CommandFactory::~CommandFactory() {
    for(int i = 0; i < 26; i++) {
        delete comFactory[i];
        comFactory[i] = nullptr;
    }
}

//----------------------------------------------------------------------------
// createCommand
// checks if input is a valid command type
// if valid, return the command 
Command* CommandFactory::createCommand(const char& comType) {
    if(comType < 'A' || comType > 'Z' ) {return nullptr;}
    int subscript = hash(comType);
    if(comFactory[subscript] == nullptr) {return nullptr;}
    return comFactory[subscript]->create();
}
