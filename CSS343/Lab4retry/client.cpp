#include "client.h"
#include "command.h"
#include "nodedata.h"
//----------------------------------------------------------------------------
// constructor
Client::Client() {
    for(int i = 0; i < MAX_BOOKS; i++) {
        cliHistory[i] = nullptr;
        bookArr[i] = nullptr;
    }
    firstName = "";
    lastName = "";
    id = -1;
}
//----------------------------------------------------------------------------
// deconstructor
Client::~Client() {
    for(int i = 0; i < MAX_COMMAND; i++) {
        delete cliHistory[i];
        cliHistory[i] = nullptr;
    }
}
//----------------------------------------------------------------------------
// setData
void Client::setData(istream& infile) {
        infile >> id;
        if(infile.eof()) {
            return;
        } // check if reached end of file
        if(id > 9999 || id < 0) { // check for valid id
            cout << "Faulty ID for client: " << id << endl; 
        }       
        infile >> lastName >> firstName;
}

//----------------------------------------------------------------------------
// display 
// output
void Client::displayHistory() {
    cout << endl;
    cout << id << "  "<< lastName << ", " << firstName << endl;
    for(int i = 0; i < indexCommands; i++) { 
        cliHistory[i]->display(); 
    }
}

//----------------------------------------------------------------------------
// addHistory
// keeps track of all checkouts and returns a client has done
bool Client::addHistory(Command* command) {
    if(indexCommands < MAX_COMMAND) {
         cliHistory[indexCommands++] = command;
         return true;
    }
    cout << "Not allowed to do more commands" << endl;
    return false;
}
//----------------------------------------------------------------------------
// addToCheckedOutList
// adds books to clients data to make sure client is returning 
// the correct book
bool Client::addToCheckedOutList(NodeData* book) {
    if(indexBooks < MAX_BOOKS) { // if more space in bookArr
        bookArr[indexBooks++] = book;
        return true;
    }  
    cout << "Not allowed to check out more than" 
    << MAX_BOOKS << " books" << endl;
    return false;
    
}
//----------------------------------------------------------------------------
// hasBook 
// returns whether or not the client has the book
bool Client::hasBook(NodeData* book) {
    for(int i = 0; i < indexBooks; i++) { //iterate through checkedout books
        if(bookArr[i] == book) {
            return true;
        }
    }
    cout << "Client does not have the book" << endl;
    return false;
}
//----------------------------------------------------------------------------
// deleteBook
// deletes data of book from client after returning
bool Client::deleteBook(NodeData* book) {
    for(int i = 0; i < indexBooks; i++) {
        if(bookArr[i] == book) {
            bookArr[i] == nullptr; 
            return true;
        }
    }
    indexBooks--;
    return false;
}
//----------------------------------------------------------------------------
// getID
int Client::getID() const {
    return id;
}