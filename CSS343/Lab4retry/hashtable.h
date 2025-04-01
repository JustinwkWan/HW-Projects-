//////////////////////////////  HashTable.h file  ///////////////////////////////
// Incomplete implementation of HashTable. Used for stored clients
#ifndef HASHTABLE_H 
#define HASHTABLE_H 
#include <iostream>
#include <istream>
#include <string>
using namespace std;
class Library; 
#include "client.h"
//----------------------------------------------------------------------------
// Implementation and assumptions 
// An array of 10000 that store clients ids one to one to the array
// assume that clients ids are between 0 and 9999
//----------------------------------------------------------------------------
const int MAX_ID = 10000;
class HashTable {
    public: 
    HashTable();
    ~HashTable();

    int hashFunction(int) const;
    //int hashFunction2(int) const;
    void insert(Client*);
    Client* search(int key);
    void display(); 
    private: 
        Client* clientArr[MAX_ID];
};
#endif