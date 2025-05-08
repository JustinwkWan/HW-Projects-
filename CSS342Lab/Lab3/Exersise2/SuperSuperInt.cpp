#include "SuperSuperInt.h"
#include <iostream>

using namespace std; 

SuperSuperInt::SuperSuperInt(int init, const char *name): SuperInt(init, name)
{
  cout << "Created a SuperSuperInt called SuperSuperInt" << endl;
}
SuperSuperInt::~SuperSuperInt()
{
}
const int& SuperSuperInt::theValue() 
{
  return SuperInt::theValue();
}
