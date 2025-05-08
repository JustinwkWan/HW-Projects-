/*
 *  Square.h
 *  Class-example
 *
 */
/*
Answer to question: There is no need to overload assignment operators
because xyz
*/
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>

class Square 
{
   /**
    * Can't get the ostream to work
   */
   //friend ostream& operator<<(ostream &outStream, const Square &square);
   //friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
public:
   Square();
   Square(int size);
   void setSize(int newSize);
   int getSize(void) const;
   Square& operator = (const Square&);
   bool operator < (const Square&);
private:
   int theSize;
   
};

#endif
