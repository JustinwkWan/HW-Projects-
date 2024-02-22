#include <iostream> 
#include "LinkedList.h"
using namespace std; 

int main()
{
    LinkedList *test = new LinkedList();

    int a = 5; int b = 10; int c = 15;
    int d; int e = 20; int f = 25; int z = 5;
    // test->Insert(&c);   
    // test->Insert(&b);           
    // test->Insert(&a); 
    // test->Insert(&e);
    // test->Insert(&f);     
    // test->Insert(&z);
    // test->PrintList();
    // test->Remove(5,d);
    // cout << "Result of remove is " << d << " " << endl;

    test->BuildList("output.txt");
    test->PrintList();
    test->DeleteList();
    delete test;
    return 0; 


}
