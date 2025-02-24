#ifndef CHILDREN_H
#define CHILDREN_H
#include "publication.h"
using namespace std;
class Children : public Publication {
    public:
        virtual Publication* create() const {return new Children;}
        virtual bool operator==(const Publication&) const;
        virtual bool operator>(const Publication&) const;
        virtual bool operator<(const Publication&) const;
};

#endif