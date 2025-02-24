#ifndef Children_H
#define Children_H
#include "publication.h"
#include <string>
using namespace std;

class Children : public Publication {
    public: 
        //virtual Stuff* create() const {return new Children;}
        Children(const string&, const string&, const int);
        virtual bool operator==(const Publication&) const;
        virtual bool operator>(const Publication&) const;
        virtual bool operator<(const Publication&) const;
    protected:
        string author; 
        string title; 
        int year;
};
#endif