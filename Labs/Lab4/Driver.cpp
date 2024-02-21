#include <iostream> 
#include "LinkedList.h"
using namespace std; 

int main()
{
    LinkedList *test;


    test = new LinkedList();

    int a = 5;
    int* ptr = &a;
    int b = 10;
    int c = 15;
    test->insert(&c);   
    test->insert(&b);
    test->insert(&a);
  
    

    test->printList();
    //test->DeleteList();
    if(test->isEmpty())
    {
        cout << "List is deleted" << endl;
    }
    test->printList();
    delete test;

    return 0; 


}
