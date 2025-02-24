#include <iostream> 
using namespace std; 
#include <cmath>
#include <vector>

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
void MBubbleSort(vector<int>& nums, int n)
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

void M2BubbleSort(vector<int>& nums, int index1 = 0, int index2 = -1)
{
    if(index2 = -1)
    {
        index2 = nums.size();
    }
    bool swapping = false;
    int loops = 0; 
    for(int i = index1; i < index2; i++)
    {
        for(int j = index1; j < index2 - loops - 1; j++)
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
        loops++; 
    }
     

}
void InsertionSort(vector<int>& nums, int n)
{
    for(int i = 1; i < n; ++i)
    {
        int value = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > value)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = value;
    }
}
void merge(vector<int>& nums, int const start, int const mid, int const end)
{
    int array1 = mid - start + 1;
    int array2 = end - mid; 
    vector<int> vector1(array1), vector2(array2); 
    for(int i = 0; i < array1; i++)
    {
        vector1[i] = nums[start + i];
    }
    for(int j = 0; j < array2; j++)
    {
        vector2[j] = nums[mid + 1 + j];
    }
    int index1 = 0, index2 = 0, indexMerged = start; 

    while(index1 < array1 && index2 < array2)
    {
        if(vector1[index1] <= vector2[index2])
        {
            nums[indexMerged] = vector1[index1];
            index1++;
        } else 
        {
            nums[indexMerged] = vector2[index2];
            index2++;
        }
        indexMerged++;
    }

    while(index1 < array1) 
    {
        nums[indexMerged] = vector1[index1];
        indexMerged++;
        index1++;
    }
    while(index2 < array2) 
    {
        nums[indexMerged] = vector2[index2];
        indexMerged++;
        index2++;
    }    
  }

void MergeSort(vector<int>& nums, int start, int end) 
 {
     if(start < end)
     {
        int mid = start + (end - start) / 2;

        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
     }
 }



int partition(vector<int>& nums, int low, int high) {
    int middle = low + (high - low) / 2;
    int pivotValue = nums[middle];

    swap(nums[middle], nums[high]);

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (nums[j] < pivotValue) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void QuickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int p = partition(nums, low, high);
        
        QuickSort(nums, low, p - 1);
        QuickSort(nums, p + 1, high);
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

