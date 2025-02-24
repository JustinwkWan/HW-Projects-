#ifndef PERIODICAL_H
#define PERIODICAL_H
using namespace std; 
#include "publication.h"
class Periodical : public Publication { 
    public: 
        virtual Publication* create() const {return new Periodical;}
        virtual bool operator==(const Publication&) const;
        virtual bool operator>(const Publication&) const;
        virtual bool operator<(const Publication&) const;

};
#endif