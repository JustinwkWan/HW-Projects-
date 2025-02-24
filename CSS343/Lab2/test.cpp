// I will test your BinTree class using either this main or
// a very similar one, and this buildTree.  
// You will want to do thorough testing on your own, 
// which is done by altering the data.

// Windows and unix store files slightly differently. Windows does not
// always store an end-of-line char on the last line, where unix does.
// On windows/mac, to mimic the way linux stores files, always make sure 
// the cursor is on the line after the last line of data.

// presumably bintree.h includes nodedata.h so the include is not needed here
#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){

    BinTree test1;
    NodeData notND("not");
    NodeData andND("and");
    NodeData sssND("sss");
    NodeData eND("e");
    NodeData mND("m");
    NodeData tND("t");
    NodeData* ptr = new NodeData(notND);
    test1.insert(ptr);
    cout << "testing insert and << " << endl; 
    cout << test1 << endl; 
    return 0; 
}