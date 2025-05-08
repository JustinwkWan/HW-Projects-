#include <iostream> 
using namespace std; 

int findBlocks(int n)
{
    if(n == 2 || n == 1)
    {
        return 1;
    }
    else 
    {
        return findBlocks(n-1) + findBlocks(n-2);
    }
}
int findBlocks2(int n)
{
    if(n == 0) 
    {
        return 1;
    } 
    else if(n < 0)
    {
        return 0;
    }
    else
    {
        return findBlocks2(n-1) + findBlocks2(n-2);
    }
}
int main()
{
    cout << "Findblocks 5 = " << findBlocks(5) << endl;
     cout << "Findblocks2 5 = " << findBlocks2(5) << endl;
    return 0; 
}