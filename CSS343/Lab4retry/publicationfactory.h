///////////////////////  PublicationFactory.h file  ///////////////////////////
// A factory that creates book
#ifndef PublicationFactory_H
#define PublicaitonFactory_H

#include "publication.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"

//----------------------------------------------------------------------------
// Implementation and Assumptions
// Implements the factory design method to create command objects 
// Implements 4 commands but has the ability to go up to 26 based on the 
// letter coming in. 
// All unused command slots will not initiaze and set to nullptr
//----------------------------------------------------------------------------
class PublicationFactory {
public: 
    PublicationFactory();               
    ~PublicationFactory();
    NodeData* createPublication(const char&);
    private: 
        NodeData* pubFactory[26]; 
        int hash(char ch) const {return ch-'A'; }
};
#endif