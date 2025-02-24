#include <iostream> 
using namespace std; 

string const DIGIT = "0123456789ABCDEF";
void PrintHexa(int n);
// test: 179912 = (2BEC8)16
int main()
{
int n;
cout << "Type a positive integer: ";
cin >> n;
cout << "The number " << n << " in hexadecimal is ";
PrintHexa(n);
cout << endl;
}

void PrintHexa(int n)
{
if (n<16)
{
// base case
cout << DIGIT[n];
}
else
{
PrintHexa(n / 16);
cout << DIGIT[n % 16];
}
}

