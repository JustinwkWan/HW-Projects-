#include <iostream> 
using namespace std;

void PrintBinary(int n)
{
if (n<2)
{
cout << n; // base case
}
else
{
PrintBinary(n / 2);
cout << n % 2;
}
}

int main( ) 
{
    PrintBinary(1);
    cout << endl;
    PrintBinary(2);
    cout << endl;
    PrintBinary(3);
    cout << endl;
    PrintBinary(4);
    cout << endl;
    return 0;
}