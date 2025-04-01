#include "return.h"
#include "library.h"
//----------------------------------------------------------------------------
// destructor
Return::~Return() { } 

//----------------------------------------------------------------------------
// create 
// creates a new checkout object for commandfactory
Command* Return::create() const {
    return new Return;
}

//----------------------------------------------------------------------------
// prints the checkout object to be displayed in history
void Return::display() const {
    cout << "Return     ";
    book->displayInfo();
}
//----------------------------------------------------------------------------
// performTask
// returns a book that a client has previously checked out
// will give an error message if client tries to return a nonchecked out book
bool Return::performTask(Library& lib, istream& infile) {
    string s;
    int id; 
    bool success; 
    char key;
    NodeData* target;
    infile >> id; // read in id and retrieve client 
    client = lib.getHashTable()->search(id); 
    if(client == nullptr) { 

        // if no client 
        cout << "client with id: " << id << " doesn't exist" << endl;

        getline(infile, s);
        return false; 
    }
    infile >> key;            // read pub type
    //go to factory and get pub
    target = lib.getPubFactory()->createPublication(key);

    if(target == nullptr) {

        // if not valid
        getline(infile, s);
        return false;
    }
    success = target->setSortingData(infile);

    if(!success) {
        // if unable to sort data
        delete target;
        cout << "Publication sorting data has bad format" << endl;
        return false;
    }

    // now retreieve book from pubTrees 
    BinTree* treeArr = lib.getPubTrees();
    success = treeArr[key - 'A'].retrieve(*target, book);
    if(!success) {
        // if book not found
        delete target;
        cout << "Can not return bad book" << endl;
        return false;
        }

    // check if client actually has book
    if(client->hasBook(book)) {
        target->increment();
    } else {
        // book not found, return false
        delete target;
        cout << "Trying to return a not yet checked out book" << endl;
        return false;
    }
    delete target;
    client->deleteBook(book);
    client->addHistory(this);
    return true;
}