#ifndef Publication_H
#define Publication_H
#include <iostream>
#include <string>
using namespace std;

class Publication {
    protected: 
        string author;
        string title; 
        int year;  
    public: 
        Publication() { }
        virtual ~Publication() { }
        void setData();
        virtual Publication* create() const = 0;
        virtual bool operator<(const Publication&) const = 0;
        virtual bool operator==(const Publication&) const = 0;
        virtual bool operator>(const Publication&) const = 0;
        

};
#endif