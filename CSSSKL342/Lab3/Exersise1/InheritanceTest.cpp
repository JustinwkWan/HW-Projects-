/*
 *  InheritanceTest.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
*/
/**
 * Questions to ask Professor/TA
 * My code is running in debugger but not in the main terminal? 
 * Not printing for unnamed classes
*/
/**
 * Answers to questions: 
 * I observe that child classes can also have child classes, but they are all derived from the 
 * orignal parent class. C is a child of B and B is a child of A. A is the parent of all classes. 
 * The destructor starts with brackets showing that 
*/
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) {
    // We put everything inside a nested block so that we can put a
    // breakpoint on the return in Visual Studio and still see all
    // of the destructor.
    {
        cout << "Creating an unnamed A." << endl;
        A a1();

        cout <<endl << "Creating an unnamed B." << endl;
        B b1();
        cout <<endl << "Creating an unnamed C." << endl;
        C c1();
        
        cout << endl << "Creating a named A." << endl;
		A a2("a2", 3, 5);
        cout << endl << "Creating a named B." << endl;
		B b2("b2",10, 10, 50);
        cout << endl << "Creating a named C." << endl;
		C c2("c2", 10, 15, 20, 30.1);

        cout << endl;
    }
    return 0;
}