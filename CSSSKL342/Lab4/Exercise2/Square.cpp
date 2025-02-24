/*
 *  Square.cpp
 *  Class-example
 *
 */

#include <iostream>
#include "Square.h"

using namespace std;

template <class W> 
void Square<W>::setSize(W newSize)
{
	theSize = newSize;
}
template<class W>
W Square<W>::getSize(void) const
{
	return theSize;
}
template <class W>
Square<W> & Square<W>::operator=(const Square<W>& other)
{
	theSize = other.getSize();
	return *this;
}
template <class W>
ostream& operator<<(ostream &os, const Square<W> &c)
{
	os << c.getSize();
	return os;
}
template <class W>
bool Square<W>::operator<(const Square<W>& other)
{
	return theSize < other.getSize();
}