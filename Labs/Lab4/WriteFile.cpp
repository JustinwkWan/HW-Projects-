#include <iostream>  
#include <fstream> 
using namespace std; 

int main()
{
    ofstream myfile; 
    myfile.open("output.txt");
    for(int i = 100; i > 0; i--)
    {
        myfile << i << "\n";
     }
     myfile.close();
     return 0;  
 }