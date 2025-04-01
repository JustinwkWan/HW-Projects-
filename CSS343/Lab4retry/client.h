//////////////////////////////  Client.h file  ///////////////////////////////
// The user of the library. Are able to do commands such as checkout, 
// return and display history. 
#ifndef CLIENT_H
#define CLIENT_H
class Library; 
class Command;
class NodeData;
#include <string> 
#include <iostream> 
using namespace std;
//----------------------------------------------------------------------------
// Implementation and Assumptions
// Assumes that the books they check out are valid
// Assumes books are in stock
// Assumes that only valid commands are displayed in history and all non-valid
// are taken care of.
// Commands are stored in an Array and prints history when 
// displayHistory is called
// Processes commands for each client if valid
//----------------------------------------------------------------------------
const int MAX_COMMAND = 100;
const int MAX_BOOKS = 100;
class Client {
    private: 
    int indexCommands = 0;
    int indexBooks = 0;
    string firstName, lastName;
    int id;
    
    NodeData* bookArr[MAX_BOOKS];
    Command* cliHistory[MAX_COMMAND];
    public: 
        Client(); // constructor 
        ~Client(); // destructor 
        void setData(istream& ); // set data here and not in constructor
        void displayHistory(); // displays history of client
        bool addHistory(Command*); // keeps track of client history
        bool addToCheckedOutList(NodeData*); // inputs book into client 
        bool hasBook(NodeData*); // checks if client has book 
        bool deleteBook(NodeData*); //deletes book from bookArr
        int getID() const;

};
#endif