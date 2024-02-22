#include <iostream>
#include <fstream> 
using namespace std; 
void Test(string name)
{
    ifstream inFile;
    inFile.open(name);
    if(inFile)
    {
        while(!inFile.eof())
        {
            string item; 
            inFile >> item;
            cout << item << endl;
        }
        inFile.close(); 
    }
    else 
    {
        cout << "File: " << name << "was not opened" << endl;
    }
}
int main()
{
    Test("output.txt");
    return 0; 
}
