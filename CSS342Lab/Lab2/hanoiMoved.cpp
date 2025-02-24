#include <iostream>
using namespace std; 
#include "sys/time.h"

int counter = 0; 
int printMoves; 
void hanoiMoves(int n, string left, string right, string middle);

struct timeval startTime, endTime;

int elapsed(timeval &startTime, timeval &endTime)
{
    return ((endTime.tv_sec - startTime.tv_sec)*1000000 + endTime.tv_usec - startTime.tv_usec);
}

int main() 
{
     for(int i = 1; i < 16; i++) 
     {
        printMoves = i; 
        int start = gettimeofday(&startTime, 0);
        counter = 0;
        hanoiMoves(i, "A", "C","B");
        cout << i << " takes " << counter << " moves" << endl;
        int end = gettimeofday(&endTime, 0);
        cout << "Time elasped: " << elapsed(startTime, endTime) << " microseconds"<< endl;
    }
    return 0;
}
void hanoiMoves(int n, string left, string right, string middle) 
{
    
    if(n == 0) 
    {
        return; 
    }
    hanoiMoves(n - 1, left, middle, right); 
    if(printMoves <= 3) 
    {
        cout << "Move disk " << n << " from " << left << " to " << right << endl; 
    }
    counter++;
    hanoiMoves(n - 1, middle, right, left);
}