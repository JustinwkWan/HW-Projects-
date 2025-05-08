#include <iostream>
#include <vector>
#include <string>
#include "SortImpls.cpp"
#include <sys/time.h>
//#include <windows.h>
using namespace std;
void InitArray(vector<int> &, int);
void InitArrayMid(vector<int> &, int);
void InOrder(vector<int> &, int);
void reverseOrder(vector<int> &, int);
void partiallyOrdered(vector<int> &, int);
void PrintArrayDetails(const vector<int> &, string);
int elapsed( timeval &startTime, timeval &endTime);
void runAlgorithms(string, vector<int> &, int, bool printOut);
int main(int argc, char *argv[])
{
    int size = 0;
    string sort_name = "";
    bool printOut = true;

    if ((argc != 3) && (argc != 4))
    {
        cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
        return -1;
    }

    sort_name = string(argv[1]);
    size = atoi(argv[2]);
    if (size <= 0)
    {
        cerr << "Array size must be positive" << endl;
        return -1;
    } if (
        argc == 4)
    {
        
    string printArr = string(argv[3]);
    if (printArr == "NO")
    {
        printOut = false;
    }
    else if (printArr == "YES")
    {
        printOut = true;
    }
    else
    {
        cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
        return -1;
    }
    }
    srand(1);
    vector<int> items(size);
    //cout << "InOrder" << endl;
    for(int i = 0; i < 3; i++)
    {
        InOrder(items, size);
        runAlgorithms(sort_name, items, size, printOut);
    }
    // cout << "ReverseOrder" << endl;
    // for(int i = 0; i < 3; i++) 
    // {
    //     reverseOrder(items,size);
    //     runAlgorithms(sort_name, items, size, printOut);
    // }
    // cout << "Random" << endl;
    // for(int i = 0; i < 3; i++) 
    // {
    //     InitArrayMid(items, size);
    //     runAlgorithms(sort_name, items, size, printOut);
    // }
    // cout << "Partially Sorted" << endl; 
    // for(int i = 0; i < 3; i++)
    // {
    //     partiallyOrdered(items,size);
    //     runAlgorithms(sort_name, items, size, printOut);
    // }
    return 0;
//End of main
}

void runAlgorithms(string sort_name, vector<int>& items, int size, bool printOut) 
{
    
    if (printOut)
    {

        cout << "Initial:" << endl;
        PrintArrayDetails(items, string("items"));
    }
    struct timeval startTime, endTime;
    gettimeofday(&startTime, 0); // Linux

    if (sort_name == "BubbleSort")
    {
        BubbleSort(items, size - 1);
    }

    if(sort_name == "MBubbleSort")
    {
        MBubbleSort(items,size-1);
    }

    if(sort_name == "M2BubbleSort")
    {
        M2BubbleSort(items, 0, size - 1);
    }
    if (sort_name == "InsertionSort")
    {
        InsertionSort(items, size - 1);
    }
    if (sort_name == "MergeSort")
    {
        MergeSort(items, 0, size - 1);
    }
    if (sort_name == "QuickSort")
    {
        QuickSort(items, 0, size - 1);
    }
    if (sort_name == "ShellSort")
    {
        ShellSort(items, size - 1);
    }
    gettimeofday(&endTime, 0);
    if (printOut)
    {
        cout << "Sorted:" << endl;
        PrintArrayDetails(items, string("item"));
    }
        int elapsed_secs = elapsed(startTime,endTime);
        cout << "Time (ms): " << elapsed_secs << endl;
}
void InOrder(vector<int> &items, int n) 
{
    items.clear();
    for(int i = 0; i < n; i++)
    {
        items.push_back(i);
    }
}
void reverseOrder(vector<int> &items, int n)
{
    items.clear();
    for(int i = n; i >= 1; i--)
    {
        items.push_back(i);
    }
    
}
void partiallyOrdered(vector<int> &items, int n)
{
     items.clear();
     for(int i = 0; i < n; i++)
     {
        items.push_back(i);
     }
     for(int i = 0; i < n; i++)
     {
        if(i % 4 == 0 && i <= (n - 5)) 
        {
            swap(items[i], items[i + 4]);
        }
        
     }
}
void InitArray(vector<int> &array, int randMax)
{
    array.clear();
        if (randMax < 0)
    {
        return;
    }

    vector<int> pool(randMax);
    for (int i = 0; i < randMax; i++)
    {
        pool[i] = i;
    }
    int spot;
    for (int i = 0; i < randMax; i++)
    {
        spot = rand() % (pool.size());
        array[i] = pool[spot];
        pool.erase(pool.begin() + spot);
    }
}
void InitArrayMid(vector<int> &array, int randMax)

{
    if (randMax < 0)
    {
        return;
    }
    vector<int> pool(randMax);
    for (int i = 0; i < randMax; i++)
    {
        pool[i] = i;
        array[i] = i;
    }
    int spot;
    int i1 = 0.01*randMax;
    int i2 = 0.99*randMax;
    for (int i = i1; i < i2; i++)
    {
        spot = rand() % (pool.size());
        array[i] = pool[spot];
        pool.erase(pool.begin() + spot);
    }
}
void PrintArrayDetails(const vector<int> &array, string name)
{
    int size = array.size();
    for (int i = 0; i < size; i++)
    cout << name << "[" << i << "] = " << array[i] << endl;
}
// Function to calculate elapsed time if using gettimeofday (Linux)
int elapsed( timeval &startTime, timeval &endTime )
{
    return ( endTime.tv_sec - startTime.tv_sec ) * 1000000 + ( endTime.tv_usec -
    startTime.tv_usec );
}