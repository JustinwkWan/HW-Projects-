#include "hashtable.h"

//----------------------------------------------------------------------------
// constructor
HashTable::HashTable() {
    for(int i = 0; i < MAX_ID; i++) {
        clientArr[i] = nullptr;
    }
}

//----------------------------------------------------------------------------
// deconstructor
HashTable::~HashTable() {
    for(int i = 0; i < MAX_ID; i++) {
        delete clientArr[i];
        clientArr[i] = nullptr;
    }
}

//----------------------------------------------------------------------------
// hashFunction
// map id to arr 1 to 1
int HashTable::hashFunction(int key) const {
    return key % MAX_ID;
}

//----------------------------------------------------------------------------
// insert 
// insert client into arr based on id 
void HashTable::insert(Client* client) {
    int key = client->getID();
    clientArr[key] = client;
}

//----------------------------------------------------------------------------
// search 
// returns client with their id
Client* HashTable::search(int key) {
    return clientArr[key];
}

//----------------------------------------------------------------------------
// display 
// displays clients information
void HashTable::display() {
    for(int i = 0; i < MAX_ID; i++) {
        if(clientArr[i] != nullptr) {
            clientArr[i]->displayHistory();
        }
    }
}

