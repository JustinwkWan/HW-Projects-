/*
 *  Square.cpp
 *  Class-example
 *
 */

#include "Square.h"

Square::Square() {
   theSize = 0;
}

Square::Square(int size) : theSize(size)
{
}

void Square::setSize(int newSize)
{
   theSize = newSize;
}


int Square::getSize(void) const
{
   return theSize;
}

Square& Square::operator = (const Square& other)
{
	theSize = other.getSize();
	return *this;
}
bool Square::operator < (const Square& other)
{
   return this->theSize < other.theSize;
}