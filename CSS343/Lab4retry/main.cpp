#include "library.h"
// Questions to ask, how to get list of publications
// Where to keep track of avaliablity
//
using namespace std;
int main() {
    ifstream infile("data4pubs.txt");
    if(!infile) {
        cout << "File data4pubs.txt could not be opened" << endl;
    }
    ifstream infile2("data4clients.txt");
    if(!infile2) {
        cout << "File data4clients.txt could not be opened" << endl;
    }
    ifstream infile3("data4commands.txt");
    if(!infile3) {
        cout << "File data4command.txt  could not be opened " << endl;
    }

    Library L; 
    L.buildLibrary(infile);
    L.buildClient(infile2);
    L.performCommands(infile3);
    return 0;
}