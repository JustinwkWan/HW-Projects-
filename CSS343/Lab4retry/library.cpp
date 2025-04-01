
#include "library.h"
//----------------------------------------------------------------------------
// constructor
Library::Library() { }

//----------------------------------------------------------------------------
// deconstructor
Library::~Library() { }

//----------------------------------------------------------------------------
// buildLibrary
// creates publications and inputs them into one of the pubtypes 
// Assumes input file has data in correct order
// Iterates through the file until reaching end of file
void Library::buildLibrary(istream &infile) {
    char key; //pubtype
    NodeData* p; // pointer to publication
    bool success;
    for(;;) { // while there are more publications
        infile >> key; // input publication
        if(infile.eof()) break; // checks if we've reach the end of file

        // going to factory and create a publication object
        // if the publication is valid, we add it to the binary tree to be 
        // stored and sorted 
        p = pubFactory.createPublication(key);
        if(p != nullptr) { // if valid pubtype
            success = p->setData(infile);
            if(success){ // if valid publication data
                pubTrees[key - 'A'].insert(p);
        
            } else { // print that publication data is non-valid
                delete p;
                cout << "faulty publication data for : "
                 << key << " type" << endl;
                cout << "not inserting. Continue" << endl;
            }
        } else { // print that publication is non-valid
            cout << "faulty publication type: " << key << endl;
            string s;
            getline(infile, s); // skip line so we can read next line
        }
    }
}
//----------------------------------------------------------------------------
// buildClient
// creates a new client and inputs into the HashTable 
// each client has an ID asscoiated with them 
void Library::buildClient(istream& infile) {
    //While there are more clients in file
    for(;;) {
        Client* client = new Client();
        client->setData(infile); 
        if(infile.eof()) {
            delete client;
            break;
        }
        // valid id and now inserting into hashTable
        clientTable.insert(client);
    }
}

//----------------------------------------------------------------------------
// performCommands
// preforms all commands that users have such as checkout return
// and display history
// if there is a faulty input, we move onto the next command
void Library::performCommands(istream& infile) {
    char key; //Command type
    Command* c; // pointer to command
    bool success;

    // While more commands 
    for(;;) { 
        infile >> key; // grabbing command
        if(infile.eof()) break; // break out of loop if end of file
        c = comFactory.createCommand(key);
        if(c == nullptr) { 

            // If a faulty command, we grab the rest of the line 
            // and output to the console which command is faulty 
            cout << "Faulty command type: " << key << endl;
            string s;
            getline(infile, s); 
            continue;
        }
        success = c->performTask(*this, infile);
        if(!success) {
            delete c;
        }
    }
}

//----------------------------------------------------------------------------
// displayCollection 
// outputs library of publication type 
void Library::displayCollection() {

    for(int i = 0; i < 26; i++) {
        if(!pubTrees[i].isEmpty()) {        
            char key = i + 'A';
            NodeData* p = pubFactory.createPublication(key);    
            p->displayHeading();
            pubTrees[i].display();
            delete p;
        }
    }
}
//----------------------------------------------------------------------------
// destroyCollection
// deletes memory of all publications
void Library::destroyCollection() {
    for(int i = 0; i < 26; i++) { pubTrees[i].makeEmpty(); }
}
//----------------------------------------------------------------------------
// getHashTable
// returns a pointer to client HashTable 
HashTable* Library::getHashTable() {
    return &clientTable;
}
//----------------------------------------------------------------------------
// getPubTrees 
// returns a pointer to the publication tree types
BinTree* Library::getPubTrees() {
    return pubTrees;
}
//----------------------------------------------------------------------------
//getPubFactory 
// returns a pointer to the publication factory
PublicationFactory* Library::getPubFactory() {
    return &pubFactory;
}