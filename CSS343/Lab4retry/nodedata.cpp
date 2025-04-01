#include "nodedata.h"

//----------------------------------------------------------------------------
// constructors/destructor  

NodeData::NodeData() { data = ""; }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly

//----------------------------------------------------------------------------
// operator==,!= 

bool NodeData::operator==(const NodeData& rhs) const {
   return data == rhs.data;
}

//----------------------------------------------------------------------------
// operator<,>,<=,>= 

bool NodeData::operator<(const NodeData& rhs) const {
   return data < rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
   return data > rhs.data;
}

//----------------------------------------------------------------------------
// setData 
// returns true if the data is set, false when bad data, i.e., is eof

bool NodeData::setData(istream& infile) { 
   getline(infile, data);
   return !infile.eof();       // eof function is true when eof char is read
}

bool NodeData::isAvalible() {
    return count > 0;
}

bool NodeData::increment() {
    count++;
    return true;
}

bool NodeData::decrement() {
    if(count > 0) {
        count--; 
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
// operator<< 

ostream& operator<<(ostream& output, const NodeData& nd) {
   output << nd.data;
   return output;
}

