#ifndef Fiction_H
#define Fiction_H
#include "publication.h"
#include <string>
using namespace std;
class Fiction : public Publication {
    public: 
    Fiction(const string&, const string&, const int);
    virtual bool operator==(const Publication&) const;
    virtual bool operator>(const Publication&) const;
    virtual bool operator<(const Publication&) const;
    protected: 
    string author; 
    string title; 
    string year;
    
};
#endif
