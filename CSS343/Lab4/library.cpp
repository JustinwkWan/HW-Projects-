#include "library.h"
using namespace std;
class PublicationFactory;
Library::Library() {

}

void Library::buildLibrary(istream& infile) {
    string pubType, author, title;
    int year;
    PublicationFactory pubF;
    for(;;) {
        infile >> pubType;

        if(infile.eof()) {return;}
        infile.get();
        getline(infile, author, ',');
        infile.get();
        getline(infile, title, ',');
        infile.get();
        
        infile >> year;
        //publication pub = new pubF();
    }
}