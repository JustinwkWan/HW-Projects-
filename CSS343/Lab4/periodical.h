#ifndef Periodical_H
#define Periodical_H
#include "publication.h"
using namespace std;
class Periodical : public Publication {
    public:
    Periodical(string&,string&,int);
    virtual bool operator==(const Publication&) const;
    virtual bool operator>(const Publication&) const;
    virtual bool operator<(const Publication&) const;
    protected:
    string author;
    string title; 
    int year; 
};
#endif