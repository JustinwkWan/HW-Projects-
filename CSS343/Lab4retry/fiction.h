#ifndef FICTION_H
#define FICTION_H
using namespace std; 
#include "publication.h"
class Fiction : public Publication { 
    public: 
        virtual Publication* create() const {return new Fiction;}
        virtual bool operator==(const Publication&) const;
        virtual bool operator>(const Publication&) const;
        virtual bool operator<(const Publication&) const;

};
#endif