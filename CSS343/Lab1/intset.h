// A intset holds a boolean value of a set of integer

#ifndef IntSet_H
#define IntSet_H
#include <iostream> 
using namespace std;
//---------------------------------------------------------------------------
//Interger Set: represents a mathematical 
//set of non-negative integers that includes 0. 
//EX: {1, 3, 15}, {0, 1, 2, 3}
class IntSet
{
private: 
    bool *set;  //The array
    int size;   //size of array 
public: 
    IntSet();
    //Args constructor initalizes up to 5 integers
    IntSet(int first = -1, int second = -1, int third = -1,
     int fourth = -1, int fifth = -1);
    //Copy constructor 
    IntSet(const IntSet &other);
    ~IntSet();
    
    //modification operators
    bool isEmpty();
    bool isInSet(int num);
    bool insert(int num);
    bool remove(int num);
    
    //boolean comparision operators
    bool operator==(const IntSet &other) const; 
    bool operator!=(const IntSet &other) const; 

    // overloaded input and output operators
    friend ostream& operator<<(ostream &os, const IntSet &list);
    friend istream& operator>>(istream &, IntSet &);
    
    //Arithmatic operators
    IntSet operator+(const IntSet &) const; 
    IntSet operator*(const IntSet &) const; 
    IntSet operator-(const IntSet &) const; 

    //boolean operators 
    IntSet& operator=(const IntSet &other); 
    IntSet& operator+=(const IntSet &other); 
    IntSet& operator*=(const IntSet &other); 
    IntSet& operator-=(const IntSet &other); 
    
    //helper methods
    int min(int const, int const) const; 
    int max(int const, int const) const; 
};

#endif