#include <iostream> 
using namespace std; 
#include <cmath>
#include <vector>

void printVector(vector<int> vec) 
{
    for(int i : vec)
    {
        cout <<  i << ", ";
    }
}
void BubbleSort(vector<int>& nums, int n)  
{
    for(int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++) 
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}
void ModifiedBubbleSort(vector<int>& nums, int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        bool swapping = false; 
        for(int j  = 0; j < i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                swapping = true;
            }
        }
        if(swapping == false)
        {
            break; 
        }
    }
}

void InsertionSort(vector<int>& nums, int n)
{
    for(int i=1; i < n; i++)
    {
        int v = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > v)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = v;
    }
}
void merge(vector<int>& nums, int const start, int const mid, int const end)
{
    int const subArrayFirst = mid - start + 1;
    int const subArraySecond = end - start + 1; 
    vector<int> firstVector;
    vector<int> secondVector; 

    for(int i = 0; i < subArrayFirst; i++)
    {
        firstVector[i] = nums[i];
    }
    for(int i = 0; i < subArraySecond; i++)
    {
        secondVector[i] = nums[i];
    }

    int indexFirstVector = 0, indexSecondVector = 0; 
    int indexMergedArray = start; 

    while(indexFirstVector < subArrayFirst && indexSecondVector < subArraySecond)
    {
        if(firstVector[indexFirstVector] <= secondVector[indexSecondVector])
        {
            nums[indexMergedArray] = firstVector[indexFirstVector];
            indexFirstVector++;
        } else 
        {
            nums[indexMergedArray] = secondVector[indexSecondVector];
            indexSecondVector;
        }
        indexMergedArray++;
    }

    while(indexFirstVector < subArrayFirst) 
    {
        nums[indexMergedArray] = firstVector[indexFirstVector];
        indexMergedArray++;
        indexFirstVector++;
    }

    while(indexSecondVector < subArraySecond) 
    {
        nums[indexMergedArray] = secondVector[indexSecondVector];
        indexMergedArray++;
        indexSecondVector++;
    }    
}

void MergeSort(vector<int>& nums, int const start, int const end) 
{
    if(start >= end)
    {
        return; 
    }
    int mid = start + (end - start) / 2;
    MergeSort(nums, start, mid);
    MergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

int partition(vector<int> nums, int low, int high)
{
    int pivot = nums[high];

    int i = low; 

    for(int j = low; j < high; j++)
    {
        if(nums[j] <= pivot)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[high]);
    return i+1;
}

void QuickSort(vector<int>& nums, int low, int high)
{
    if(low<high)
    {
        int p = partition(nums, low, high);
        QuickSort(nums,low, p-1);
        QuickSort(nums, p+1, high);
    }
}

void ShellSort(vector<int>& nums, int n)
{
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i += 1)
        {
            int temp = nums[i];
            int j; 
            for(j = i; j >= gap && nums[j - gap] > temp; j -= gap)
            {
                nums[j] = nums[j - gap];
            }
            nums[j] = temp; 
        }
    }
}
