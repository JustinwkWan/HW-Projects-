/*
 *  C.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#include "C.h"
#include <iostream>

using namespace std;

C::C()
: B("unnamed C", 0, 0, 0), testDataC(0.0)
{
  cout << "Inside C::C() for object " << getN() << endl;
}

C::C(string name, int data, int data2, int dataB, double dataC)
: B(name, data, data2, dataB), testDataC(dataC)
{
  
  cout << "Inside C::C(string, int, int, int, double) for object " << getN() << endl;
}


C::~C()
{
  cout << "Inside C::~C() for object " << getN() << endl;
}


