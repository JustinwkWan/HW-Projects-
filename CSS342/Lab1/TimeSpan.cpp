//
// Created by jwan4 on 1/10/2024.
//



#include "TimeSpan.h"

ostream &operator<<(ostream &os, const TimeSpan& time)
{
    os << "Hours: " << time.hours << ", Minutes: "
    << time.minutes << ", Seconds: " << time.seconds;
    return os;
}

istream &operator>>(istream &is, TimeSpan& time) {
    double hrs, mins, secs;
    time.setTime(hrs, mins, secs);
    return is;
}

/*
 * CheckIfTimePostive
 --------------------
 *Discription: Check to see after reduction if the amount 
 * of time is negative and prints to the console that the TimeSpan is negative. 
*/
bool TimeSpan::checkIfTimePositive() const
{
    if (hours < 0 || minutes < 0 || seconds < 0)
    {
        cout << "Time for object has become negative" << endl;
        return false; 
    }
     return true;
}

/**
 *reduce 
 -------
 * Discription: The reduce function simplifys each TimeSpan
 * to be in terms of ints and makes sure the output is positve
 * @param h
 * @param m
 * @param s
 * @return
 */
bool TimeSpan::reduce(double h, double m, double s)
{
        int totalSeconds = 0;
        //Only need to cast seconds to int because hours and minutes round close enough after multiplying
        totalSeconds = h * 3600 + m * 60 + static_cast<int>(round(s));
        hours = totalSeconds / 3600;

        totalSeconds = totalSeconds % 3600;
        minutes = totalSeconds / 60;

        totalSeconds = totalSeconds % 60;
        seconds = totalSeconds;

        return checkIfTimePositive();
}

TimeSpan::TimeSpan()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

TimeSpan::TimeSpan(double h, double m, double s)
{
    reduce(h, m, s);
}

TimeSpan::TimeSpan(double m, double s)
{
    reduce(0,m,s);
}

TimeSpan::TimeSpan(double s)
{
    reduce(0,0,s);
}

int TimeSpan::getHours() const
{
    return this->hours;
}

int TimeSpan::getMinutes() const
{
    return this->minutes;
}

int TimeSpan::getSeconds() const
{
    return this->seconds;
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
    if(60 < seconds || -60 > seconds || 60 < minutes || -60 > minutes || 0 > hours)
    {
        cout << "Trying to set numbers out of bounds. Keep minutes and seconds within -60 and 60 and hours positive" << endl;
        return false;
    }
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    return true;
}

TimeSpan &TimeSpan::operator-=(const TimeSpan &time)
{
    hours = this->hours - time.hours;
    minutes = this->minutes - time.minutes;
    seconds = this->seconds - time.seconds;
    reduce(hours, minutes, seconds);
    return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &time) const
{
    TimeSpan result = *this;
    result -= time;
    return result;
}

TimeSpan TimeSpan::operator+=(const TimeSpan &time)
{
    hours = this->hours + time.hours;
    minutes = this->minutes + time.minutes;
    seconds = this->seconds + time.seconds;
    reduce(hours, minutes, seconds);
    return *this;

}
TimeSpan TimeSpan::operator+(const TimeSpan &time) const
{
    TimeSpan result = *this;
    result += time;
    return result;
}

TimeSpan TimeSpan::operator-() const
{
    return TimeSpan(-(this-> hours), -(this->minutes), -(this->seconds));
}

bool TimeSpan::operator==(const TimeSpan &time) const
{
    return(this->getHours() == time.getHours() && this->getMinutes()
    == time.getMinutes() && this->getSeconds() == time.getSeconds());
}

bool TimeSpan::operator!=(const TimeSpan &time) const
{
    return!(*this==time);
}