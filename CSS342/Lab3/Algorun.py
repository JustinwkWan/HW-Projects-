from subprocess import call

SortName = ["BubbleSort", "MBubbleSort","M2BubbleSort", "InsertionSort", "QuickSort", "MergeSort", "ShellSort"]
nums = [100, 1000, 5000, 10000, 50000, 100000, 250000, 500000]
call(["g++", "Sorter.cpp", "-o", "Sorter"])

for i in range(len(SortName)) :
    print(SortName[i])
    for j in range(len(nums) - 7):
        print("Number of elements:", nums[j])
        call(["./Sorter", str(SortName[i]), str(nums[j]), "NO"])