#pragma once
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort1(vector<int> &nums)
{
    int high = nums.size();
    for (int i = 0; i < high; i++) 
    {
        for (int j = 0; j < high-i-1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void BubbleSort2(vector<int> &nums)
{
    int high = nums.size();
    bool swapped = false;
    for (int i = 0; i < high; i++) 
    {
        for (int j = 0; j < high-i-1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void BubbleSort3(vector<int> &nums, int low = 0, int high = -1)
{
    if (high == -1) high = nums.size();
    int iterations = 0;
    bool swapped = false;
    for (int i = low; i < high; i++) 
    {
        for (int j = low; j <= high-iterations-1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
        iterations++;
    }
}

void InsertionSort(vector<int> &nums, int low = 0, int high = 0)
{
    if (high == 0)
    {
        high = nums.size();
    }
    int key, j;
    for (int i = 1; i < high; i++) {
        key = nums[i];
        j = i - 1;
        
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

void Merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1; 
    int k = 0;

    while (i <= mid && j <= right) 
    {
        if (nums[i] <= nums[j]) 
        {
            temp[k] = nums[i];
            k += 1; i += 1;
        }
        else 
        {
            temp[k] = nums[j];
            k += 1; j += 1;
        }
    }

    while (i <= mid) 
    {
        temp[k] = nums[i];
        k += 1; i += 1;
    }
    while (j <= right) 
    {
        temp[k] = nums[j];
        k += 1; j += 1;
    }
    for (i = left; i <= right; i += 1) 
    {
        nums[i] = temp[i - left];
    }
}

void MergeSort(vector<int> &nums, int left = 0, int right = -1)
{
    if (right == -1) right = nums.size();
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }
}

int Partition(vector<int> &nums, int low, int high) 
{
    int p = 1 + (rand() % (high - low + 1));
    if (p != high) swap(nums[p], nums[high]);
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[high]);
    return i+1;
}

void QuickSort(vector<int> &nums, int low = 0, int high = -1)
{
    if (high == -1) high = nums.size();
    if (low < high)
    {
        int p = Partition(nums, low, high);
        QuickSort(nums, low, p-1);
        QuickSort(nums, p+1, high);
    }
}

void ShellSort(vector<int> &nums, int low = 0, int high = 0)
{
    if (high == 0) high = nums.size();
    int gap = 1;
    while(gap < high / 3) gap = (3*gap)+1; //3^k + 1
    for (gap; gap > 0; gap = (gap-1)/3)
    {
        for (int i = gap; i <= high; i++)
        {
            int temp = nums[i];
            int key;
            for (key = i; key >= gap && nums[key-gap] > temp; key -= gap)
            {
                nums[key] = nums[key-gap];
            }
            nums[key] = temp;
        }
    }
}
