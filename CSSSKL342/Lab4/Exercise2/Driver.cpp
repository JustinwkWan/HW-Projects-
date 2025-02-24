/*
 * Driver for simple int Square class.
 *
 * Author: Kelvin Sung
 * Date: Oct 2018
 */

#include <iostream>
#include "Square.h"

using namespace std;
template<class W>
void MySwap(W &x, W &y)
{
    W temp = x;
    x = y;
    y = temp;   
}
template<class W>
void MyBubbleSort(W *data, int size) {
    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size-1-i; j++) {
            if (data[j] < data[j+1])
                MySwap(data[j], data[j+1]);
        }
    }
}
template<class W>
void printArray(string msg, W *data, int size) {
    cout << msg << endl;
    for (int i = 0; i<size; i++) {
        cout <<  data[i] << " ";
    }
    cout << endl;
}



int main(int argc, char** argv)
{
   cout << "testing myswap" << endl; 
    int a = 10;
    int b = 20; 
    char c = 'C';
    char d = 'D';
    cout << "a before swap: " << a << " b before swap: " << b << endl;
    MySwap<int>(a,b);
    cout << "a after swap: " << a << " b after swap: " << b << endl;
    MySwap<char>(c,d); 
    cout << "c before swap: " << c << " d before swap: " << d << endl;
    cout << "c after swap: " << c << " d after swap: " << d << endl;

    Square<char> c1, c2;
    c1.setSize('1');
    c2.setSize('9');

    Square<int> s1, s2;

    s1.setSize(5);
    s2.setSize(3);

    cout << "S1 is: " << s1 << endl;
    cout << "S2 is: " << s2 << endl;

    if (s1 < s2) 
        cout << "s1 is smaller" << endl;
    else 
        cout << "s2 is smaller" << endl;

    s1 = s2;
    cout << "after assignment" << endl;
    cout << "s1 is:" << s1 << endl;
    cout << "s2 is:" << s2 << endl;
    
    // do bubble sort
    int  num[10] = {10, 9, 8, 1, 0, 7, 20, 14, 2, 4};
    Square<int> sArray[10];  // call initialize by default constructors
    for (int i = 0; i<10; i++) {
        sArray[i].setSize(num[i]);
    }

    printArray("Array before sorting:", sArray, 10);
    MyBubbleSort(sArray, 10);
    printArray("Array after sorting:", sArray, 10);

    MyBubbleSort(num, 10);
    printArray("num after", num, 10);
}
