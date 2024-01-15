//
// Created by jwan4 on 1/10/2024.
//
#ifndef LAB1_TIMESPAN_H
#define LAB1_TIMESPAN_H
#endif //LAB1_TIMESPAN_H
#include <iostream>
#include <cmath>
using namespace std;
class TimeSpan 
{
    //Implementing StreamIO 
    friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
    friend istream& operator>>(istream & inStream, TimeSpan &time);

private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    //Helper Methods
    bool checkIfTimePositive() const;
    bool reduce(double h, double m, double s);
public:
    //Constructor
    TimeSpan();
    TimeSpan(double h, double m, double s);
    TimeSpan(double m, double s);
    explicit TimeSpan(double s);

    //Getters and setters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool setTime(int hours, int minutes, int seconds);

    //Addition and Subtration
    TimeSpan operator-(const TimeSpan &time) const;
    TimeSpan& operator-=(const TimeSpan &time);

    TimeSpan operator+(const TimeSpan &time) const;
    TimeSpan operator +=(const TimeSpan &time);

    //Unary Negation
    TimeSpan operator-() const;

    //Equals
    bool operator== (const TimeSpan& time) const;
    bool operator!= (const TimeSpan& time) const;
};