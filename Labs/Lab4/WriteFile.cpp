#include <iostream>  
#include <fstream> 
using namespace std; 

int main()
{
    ofstream myfile; 
    myfile.open("out.txt");
    for(int i = 0; i < 100; i++)
    {
        myfile << "I am number " << i << "\n";
    }
    myfile << "UW Bothell\n";
    myfile.close();
    return 0;  
}