/*
 *  C.h
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#ifndef C_H
#define C_H
#include "B.h"

class C : public B
{
public:
    C();
    C(string name, int data, int data2, int dataB, double dataC);
	~C();
    
    
private:
    double testDataC; 
};

#endif
