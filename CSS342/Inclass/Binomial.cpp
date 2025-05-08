#include <iostream> 
using namespace std; 

int BinomialCoef(int k, int n)
{
if (k==0 || k==n)
{
return 1;
}
else
{
return BinomialCoef(k-1, n-1) + BinomialCoef(k,n-1);
}
}

int main() 
{
    cout << BinomialCoef(3,8) << endl;
    return 0;
}