/*
 *  Square.h
 *  Class-example
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

template<class W>
class Square {
	template<class X>
	friend std::ostream& operator<<(std::ostream&, const Square<X>&);
public:
	Square & operator=(const Square<W>&);
	bool operator<(const Square<W>&);
	void setSize(W newSize);
	W getSize(void) const;

private:
	W theSize;
};
#include "Square.cpp"
#endif
