#ifndef Library_H
#define Library_H
#include <iostream>
#include <istream>
#include <string>
#include "bintree.h"
#include "publicationFactory.h"
#include "publication.h"

class publicationFactory;
class publication;
class Library {
    public:
        // Library();
        // void buildLibrary(istream&);
    private:

    BinTree array[26];
    
};

#endif