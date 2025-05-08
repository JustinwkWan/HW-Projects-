/*
 *  B.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#include "B.h"
#include <iostream>

using namespace std;

B::B() : testDataB(0)
{
  cout << "Inside B::B() for object " << getN() << "with the int " << testDataB << endl;
}

B::B(string name, int data, int data2, int dataB) 
: A(name, data, data2) , testDataB(dataB)
{
  cout << "Inside B::B(string, data, data2, dataB) for object " << name << getN() <<  endl;
}


B::~B()
{
  cout << "Inside B::~B() for object " << getN() << endl;
}

