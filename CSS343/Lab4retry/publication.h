//////////////////////////////  Publication.h file  //////////////////////////
// A Child of Nodedata. Parent of Children, Fiction, and Periodical. 
// A pure virtual class
#ifndef Publication_H
#define Publication_H
#include <iomanip>
#include <iostream>
#include "nodedata.h"
//----------------------------------------------------------------------------
// Implementation and Assumptions
// Every book that is create inherits from publication which 
// is also inherited from nodedata.
// When printing out data, sets the max length of each title to 30
//----------------------------------------------------------------------------

const int TITLE_MAX_LENGTH = 22;
class Publication : public NodeData{
    public: 
        Publication() { }
        virtual ~Publication() { }
};
#endif