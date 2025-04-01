#include "display.h"
#include "library.h"
//----------------------------------------------------------------------------
// deconstructor
Display::~Display() { }
 
//----------------------------------------------------------------------------
// create 
// creates a new display object for command factory
Command* Display::create() const {
    return new Display;
}

//----------------------------------------------------------------------------
// outputs to console 
void Display::display() const {
    
}

//----------------------------------------------------------------------------
// performTask
// displays the collections of publications to the console
bool Display::performTask(Library& lib, istream& infile) {

    lib.displayCollection();
    return false;
}