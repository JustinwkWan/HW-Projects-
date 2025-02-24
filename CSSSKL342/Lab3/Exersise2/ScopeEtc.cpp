/*
 * ScopeEtc.cpp
 *
 * Code to show some things about scope, variable lifespan, and lvalues.
 *
 * Created by Michael Stiber
 * Modified by Yang Peng on 01/12/18
 */

#include <iostream>
#include "SuperInt.h"
#include "SuperSuperInt.h"

using namespace std;

static SuperInt var(0, "global");

int main()
{
  cout << "At start of main()" << endl;

  cout << "var's value is " << var.theValue() << endl << endl;
  //int *x = var.theValue;
  //Exersise2 Question1: We can usually return the value to a variable but here, we 
  // are returning the refrence, not the number
  //var.theValue = 5;
  //Since the function theValue is const, we are unable to change the value
  // and or address 
  SuperInt var2(1, "Main");
  var2.theValue() = 5; 
  cout << "var2's value is " << var2.theValue() << endl << endl;


  cout << "Entering top block" << endl;
  {
    SuperInt var2(2, "block");
    cout << "var2's value is " << var2.theValue() << endl << endl;
  }
  cout << "Exiting top block" << endl << endl;;


  cout << "Entering bottom block" << endl;
  {
    static SuperInt var2(2, "static");
    cout << "var2's value is " << var2.theValue() << endl << endl;
  }
  cout << "Exiting bottom block" << endl << endl;

  int i = var2.theValue();

  SuperInt* pvar = new SuperInt(3, "dynamic");
  
   cout << "Entering SuperSuperInt" << endl;
   {
     SuperSuperInt var3(5, "SuperSuperInt");
     //int theValue() = 10;
     //Doesn't work on left hand side assignment
     int testFunction = var3.theValue();
     cout << "Number in testFunction is " << testFunction << endl; 
     var3.theValue();
     cout << "var3's value " << var3.theValue();
   }
  cout << "At end of main()" << endl;
}
