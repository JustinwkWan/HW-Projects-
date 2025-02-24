#ifndef PublicationFactory_H
#define PublicaitonFactory_H

#include <string> 
#include "publication.h"
using namespace std;

class PublicationFactory {
public: 
    PublicationFactory();
    ~PublicationFactory();
    Publication* createPublication(const char&);
    private: 
    Publication* pubFactory[26]; 
    int hash(char ch) const {return ch-'A'; }
};
#endif