#include "history.h"
#include "library.h"
//----------------------------------------------------------------------------
// destructor
History::~History() { }

//----------------------------------------------------------------------------
// create
// returns a new History command to command factory
Command* History::create() const {
    return new History;
}

//----------------------------------------------------------------------------
// print
// output to command to console
void History::display() const {

}

//----------------------------------------------------------------------------
// performTask 
// returns the history of clients commands, excludes called history command
bool History::performTask(Library& lib, istream& infile) {
    string s;
    infile >> id; // read in id and retrieve client 

    client = lib.getHashTable()->search(id);
    if(client == nullptr) { 

        // if no client, error, getline(), return false 
        cout << "client with id: " << id << " doesn't exist." << endl;
        
        getline(infile, s);
        return false;
    }
    client->displayHistory();
    return false;
}