#include "checkout.h"
#include "library.h"
//----------------------------------------------------------------------------
// destructor
CheckOut::~CheckOut() { }

//----------------------------------------------------------------------------
// create 
// creates a new checkout object for commandfactory
Command* CheckOut::create() const {
    return new CheckOut;
}

//----------------------------------------------------------------------------
// display 
// prints the checkout object to be displayed in history
void CheckOut::display() const {
    cout << "CheckOut   ";
    book->displayInfo();

}

//----------------------------------------------------------------------------
// performTask
// checks out a book for a client and if the book is valid, 
// we will add this checkout command to the history of the client
// C 1111 C H Danny Dunn & the Homework Machine, Williams Jay,
bool CheckOut::performTask(Library& lib, istream& infile) {
    string s;
    int id; 
    bool success; 
    char key;
    NodeData* target;
    infile >> id; // read in id and retrieve client 
    client = lib.getHashTable()->search(id);

    if(client == nullptr) { 

        // if no client
        cout << "client with id: " << id << " doesn't exist." << endl;
        getline(infile, s);
        return false;
    }

    infile >> key;                       //read pub type
     // go to factory and get pub
    target = lib.getPubFactory()->createPublication(key);
    
    if(target != nullptr) {
        // read in publication and call setsortingdata
        success = target->setSortingData(infile);
        if(success) {
            // now retrieve book from pubTrees
            BinTree* treeArr = lib.getPubTrees();

            // now retrieve book from pubTrees

            success = treeArr[key - 'A'].retrieve(*target, book);

            // unsuccesfully retreieved book
            if(success) {
                 if(book->isAvalible()) {
                    book->decrement();
                } else {
                // if all books are check out tell client and return false
                    book->display(); 
                    cout << " are all checked out" << endl;
                    delete target;
                    return false;
                }
            } else {
                // if book not found
                delete target;
                cout << "Clients book is not in the library" << endl;
                return false;
            }
        } else {
            delete target;
            cout << "Publication sorting data has bad format" << endl;
            return false;
        }
    } else {
        // if not valid
        getline(infile, s);
        return false;
    }
    // add this client history
    delete target;
    client->addHistory(this);
    client->addToCheckedOutList(book);
    return true;
}
