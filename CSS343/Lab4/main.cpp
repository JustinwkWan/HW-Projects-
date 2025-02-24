using namespace std; 
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#include "library.h"
#include "publication.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    ifstream infile("book4pub.txt");
    if(!infile) {
        cout << "File could not be opened" << endl;
    }        
    Library L;
    L.buildLibrary(infile);
    cout << "Hello" << endl; 
}
