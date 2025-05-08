#include <iostream>
#include "Square.h"
#include "SquareContainer.h"

using namespace std;

int main (int argc, char * const argv[]) {
   cout << "Testing Sqaure < Operator" << endl; 
   Square s(10);
   Square s2(20);

   if(s < s2) {
      cout << "s2 is bigger" << endl;
   } else {
      cout << "s is bigger" << endl; 
   }
   /**
    * The square class does need an overloaded assignment operator because 
    * a sqaure isn't a primitive type that has assignments connect to each variable. 
    * Although it only holds one int right now, we can add more which will cause 
    * the assignments to change, and we as developers will change them to how see fit. 
   */



   SquareContainer c;
   
   for (int i = 0; i < 20; i++) {
      Square s;
      s.setSize(i);
      c.insertNext(s);
   }
   SquareContainer d(c); // copy
   SquareContainer e = d; // assignment

   SquareContainer testcopying;
   testcopying = c; 
   
      try {
      for (int i = 0; i < 20; i++) {
         cout << "Square " << i << " size is " 
         << c.deleteLast().getSize() << endl;
      }
   }
   catch (SquareContainerException sqe) {
      cerr << sqe.what();
   }   
   try {
      for (int i = 0; i < 20; i++) {
         cout << "testcopySquare " << i << " size is " 
         << testcopying.deleteLast().getSize() << endl;
      }
   }
   catch (SquareContainerException sqe) {
      cerr << sqe.what();
   }   
   //Off by one error fix
    return 0;
}
