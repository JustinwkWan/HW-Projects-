//////////////////////////////  library.h file  ///////////////////////////////
// The manager class of all classes. Connector between clients, publication, 
// and commands.
#ifndef Library_H
#define Library_H
#include <iostream>
#include <istream>
#include <string>
#include "bintree.h"
#include "publicationfactory.h"
#include "hashtable.h"
#include "client.h" 
#include "commandfactory.h"
//----------------------------------------------------------------------------
// Class Library 
// Implementation and Assumptions
// All publications are stored as a nodedata which is sorted by a binary tree
// Clients are stored one to one id their id into a hashTable 
// Publications and Commands are created through factories so we do not 
// violate open closed principles.
// We assume that data will have the correct format but deal with 
// errors within the code. 
// no duplicates are allowed in publications
// clients are not allowed to have the same id
//----------------------------------------------------------------------------

class Library {
    public:
        Library(); // constructor
        ~Library(); // desturctor
        void buildLibrary(istream&); // builds librarys of publications
        void displayCollection(); //outputs librarys of pubtype
        void destroyCollection(); // destroys librarys of pubtype
        void buildClient(istream&); // builds hashtable of clients
        HashTable* getHashTable(); // hashtable getter 
        BinTree* getPubTrees(); // publicationtree getter
        PublicationFactory* getPubFactory();
         // preforms specified command from client
        void performCommands(istream& );
    private:
    BinTree pubTrees[26]; // HashTable implementation to sort pubtypes
    HashTable clientTable; // HashTable implementation to sort clients
    PublicationFactory pubFactory; 
    CommandFactory comFactory;
};
#endif