#include <iostream> 
using namespace std; 
#include<string>
bool myFunc(string str)
{
int len = str.length();
cout << len; 
if (len<=1)
{
return true;
}
else
{
return str[0]==str[len-1] && myFunc(str.substr(1,len-2));
}
}
int BinarySearch(const int value, const int arr[], const int index1, const int index2)
{
if (value == arr[index1])
{
return index1;
}
else if (value == arr[index2])
{
return index2;
}
else if (index2 <= index1 + 1)
{
return -1;
}
else
{
int midpoint = (index1 + index2) / 2;
if (arr[midpoint] > value)
{
return BinarySearch(value, arr, index1, midpoint);
}
else
{
return BinarySearch(value, arr, midpoint, index2);
}
}
}
int main() 
{
    cout << myFunc("ABCDEA");
    
}