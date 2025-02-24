#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SortImpls2.cpp"
#include <sys/time.h>
using namespace std;

void InitArray(vector<int> &array, int randMax)
{
    for (int i = 0; i < randMax; i++) array.push_back(i);
    randMax = array.size();
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

void OrderedArray(vector<int> &items, int size)
{
    for (int i = 0; i < size; i++) items.push_back(i);
}

void ReverseOrderedArray(vector<int> &items, int size)
{
    for (int i = size - 1; i >= 0; i--) items.push_back(i);
}

// 1/2 of the values in the list are swapped
void PartiallyOrderedArray(vector<int> &items, int size)
{
    for (int i = 0; i < size; i++) items.push_back(i);
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0 && i <= (size - 3))
        {
            int temp = items[i];
            items[i] = items[i+2];
            items[i+2] = temp;
        }
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

void PrintArray(vector<int> items, string sortName, bool printOut, int size)
{
    if (printOut)
    {
        cout << "Initial:" << endl;
        PrintArrayDetails(items, string("items"));
    }
    struct timeval startTime, endTime;
    gettimeofday(&startTime, 0); // Linux
    if (sortName == "BubbleSort1")
    {
        BubbleSort1(items);
    }
    if (sortName == "BubbleSort2")
    {
        BubbleSort2(items);
    }
    if (sortName == "BubbleSort3")
    {
        BubbleSort3(items, 0, size - 1);
    }
    if (sortName == "InsertionSort")
    {
        InsertionSort(items, 0, size - 1);
    }
    if (sortName == "MergeSort")
    {
        MergeSort(items, 0, size - 1);
    }
    if (sortName == "QuickSort")
    {
        QuickSort(items, 0, size - 1);
    }
    if (sortName == "ShellSort")
    {
        ShellSort(items, 0, size - 1);
    }
        gettimeofday(&endTime, 0);
    if (printOut)
    {
        cout << "Sorted:" << endl;
        PrintArrayDetails(items, string("item"));
    }
    int elapsedSecs = elapsed(startTime,endTime);
    cout << "Time (ms): " << elapsedSecs << endl;
}

/*
Rerun with only random sort
*/
int main(int argc, char *argv[])
{
    int size = 0;
    string sortName = "";
    bool printOut = true;
    if ((argc != 3) && (argc != 4))
    {
        cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
        return -1;
    }
    sortName = string(argv[1]);
    size = atoi(argv[2]);
    if (size <= 0)
    {
        cerr << "Array size must be positive" << endl;
        return -1;
    } 
    if (argc == 4)

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
    string orderType[4] = {"Ordered", "Reversed", "Partially", "Random"};
    for(int i = 0; i < 1; i++)
    {
        items.clear();
        if(i == 0) OrderedArray(items, size);
        if(i == 1) ReverseOrderedArray(items, size);
        if(i == 2) PartiallyOrderedArray(items, size);
        if(i == 3) InitArray(items, size);
        cout << orderType[i] << " - " << size << endl;
        for(int j = 0; j < 3; j++)
        {
            PrintArray(items, sortName, printOut, size);
        }
    }
    return 0;
}
