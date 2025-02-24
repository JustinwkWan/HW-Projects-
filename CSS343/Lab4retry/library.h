#ifndef Library_H
#define Library_H
#include <iostream>
#include <istream>
#include <string>
#include "bintree.h"
#include "publicationfactory.h"

class Library {
    public:
        Library();
        ~Library();
        void buildCollection();
        void buildLibrary(istream&);
        void displayCollection();
        void destroyCollection();

    private:

    BinTree myTree;
    PublicationFactory factory;
    char pubType[26];
};

#endif