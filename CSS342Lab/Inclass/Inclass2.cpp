#include <iostream>
using namespace std;
#include <sys/time.h>

int count = 0; 

string PrintStringReversal(string input) {
    count++;
    if(input.size() == 1) {
        return input; 
    }
    char last = input[input.size() -1];
    return last + PrintStringReversal(input.substr(0,input.size() - 1));
}


struct timeval startTime, endTime;

int elapsed(timeval &startTime, timeval &endTime)
{
    return ((endTime.tv_sec - startTime.tv_sec)*1000000 + endTime.tv_usec - startTime.tv_usec);
}


int main() 
{
string test = "Iphone";

int start = gettimeofday(&startTime, 0);
cout << PrintStringReversal(test) << endl;
int end = gettimeofday(&endTime, 0);
cout << "Time elasped: " << elapsed(startTime, endTime) << " microseconds"<< endl;
cout << "Number of steps is " << count << endl;  
}