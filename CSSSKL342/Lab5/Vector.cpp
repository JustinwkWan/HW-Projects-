#include <iostream> 
#include <vector>
#include <random>

using namespace std;

void bubbleSort(vector<int>& a)
{
      bool swap = true;
      while(swap){
        swap = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swap = true;
            }
        }
    }
}
int main() 
{
    vector<int> first{6, 32, 4, 18, 14};

    vector<int>::iterator ptr; 
    cout << "Elements in the array are " << endl;
    for(ptr = first.begin(); ptr < first.end(); ptr++) 
    {
        cout << *ptr << " ";
    }
    
    first.push_back(37);
    first.push_back(41);
    first.push_back(3);
    first.push_back(15);
    first.push_back(21);
    cout << endl;
    cout << "Elements in array are ";
    vector<int>::iterator ptr2; 
    cout << endl;
    for(ptr2 = first.begin(); ptr2 < first.end(); ptr2++) 
    {
        cout << *ptr2 << " ";
    }
    cout << "Size of the vector is " << first.size() << endl;

    cout << "Elements in array after sorting" << endl; 
    bubbleSort(first); 
    vector<int>::iterator ptr3; 
    cout << endl;
    for(ptr3 = first.begin(); ptr3 < first.end(); ptr3++) 
    {
        cout << *ptr3 << " ";
    }

    return 0; 
}