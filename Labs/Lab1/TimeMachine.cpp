//
// Created by jwan4 on 1/10/2024.
//
#include <iostream>
#include "TimeSpan.h"
using namespace std;
void TestingPrints();
int main() 
{
    TestingPrints();
    return 0;
}
void TestingPrints() 
{
    cout << "Testing all TimeSpan Constructors:" << endl;
    const TimeSpan test{45};
    cout << test << endl;

     TimeSpan test2{15,15.9};
    cout << test2 << endl;

    const TimeSpan test3{1.5,4,-10};
    cout << test3 << endl;

    const TimeSpan test4{1.5, -45, 8};
    const TimeSpan test6{1,1,1};

    cout << "testing setTime method" << endl; 
    test2.setTime(1,2,3);
    cout << test2 << endl;  

    cout << "testing a faulty constructor" << endl; 
    const TimeSpan test5{-1,3,3}; 
    cout << test5 << endl; 
    

    cout << test4 << endl;
    cout << test6 << endl;

    cout << "testing addition" << endl;
    cout << test6 + test4 << " While expected is Hours: 1 Minutes: 46" << endl;

    cout << "testing subtraction " << endl;
    cout << test6 - test4 << " While excepted is Minutes: 15 Seconds: 53"<< endl;

    const TimeSpan test7{1,2,3};
    cout << "Testing negative unary negation" << endl;
    cout << test7 << endl;
    cout << -test7 << endl;

    cout << "testing == and != comparison statements" << endl;
    const TimeSpan test8{3,3,3};
    const TimeSpan test9{3,3,3};
    const TimeSpan test10{4,3,3};
    cout << "Comparing Hours: 3 , Minutes: 3, Seconds: 3 to Hours: 3 , Minutes: 3, Seconds: 3" << endl;
    if(test8 == test9) {
        cout << " == works" << endl;
    } else {
        cout << " == doesn't work" << endl;
    }
    cout << "Comparing Hours: 3 , Minutes: 3, Seconds: 3 to Hours: 4 , Minutes: 3, Seconds: 3" << endl;
    if(test8 != test10) {
        cout << " != works" << endl;
    } else {
        cout << " != doesn't work" << endl;
    }

    cout << "Testing for input (ceer)" << endl;
    int inputHours, inputMinutes, inputSeconds;
    cout << "Enter Hours, Minutes, Seconds seperated by space";
    cin >> inputHours >> inputMinutes >> inputSeconds;
    const TimeSpan test11{static_cast<double>(inputHours),static_cast<double>(inputMinutes),static_cast<double>(inputSeconds)};
    cout << test11 << endl;
}
