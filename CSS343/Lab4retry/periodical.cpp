#include "periodical.h"
//----------------------------------------------------------------------------
// constructor 
// set count of books to 1 per periodical
Periodical::Periodical() { count = 1; } 

//----------------------------------------------------------------------------
// destructor
Periodical::~Periodical(){ }

//----------------------------------------------------------------------------
// create
// returns a new fiction object to go to publication factory
NodeData* Periodical::create() const {
    return new Periodical;
}

//----------------------------------------------------------------------------
// setData
// sets data for each publication
// does error checking to see if data is valid
bool Periodical::setData(istream& infile) {
    infile.get();
    getline(infile, title, ',');

    infile >> month;
    infile >> year;
    return true;
}

//----------------------------------------------------------------------------
// setSortingData
// does the same as set data but sorting data has different input b
// C 1111 P H 2010 2 Communications of the ACM,
bool Periodical::setSortingData(istream& infile) {
    char format;
    string s;
    infile >> format;
    if(format != 'H') { 
        getline(infile, s);
        return false;
    }
    infile >> year; 
    infile >> month;

    infile.get();
    getline(infile, title, ',');
    return true;
}

//----------------------------------------------------------------------------
// operator< 
// checks to see if lhs < rhs
// sorted by date(year, then month) then by title
bool Periodical::operator<(const NodeData& other) const {
    if (const Periodical* oPeriodical = 
    dynamic_cast<const Periodical*>(&other)) {
        if(year < oPeriodical->year) {
            return true;
        } 
        if(year == oPeriodical->year && month < oPeriodical->month) {
            return true;
        }
        if(year == oPeriodical->year && month == oPeriodical->month) {
            return title < oPeriodical->title;
        }
    }
    return false;
}

//----------------------------------------------------------------------------
// operator==
// checks to see if lhs == rhs
// sorted by date(year, then month) then by title
bool Periodical::operator==(const NodeData& other) const {
    if(const Periodical* oPeriodical = dynamic_cast<const Periodical*>(&other)) {
        return year == oPeriodical->year && month == oPeriodical->month 
        && title == oPeriodical->title;
    }
    return false;
}

//----------------------------------------------------------------------------
// operator>
// checks to see if lhs > rhs
// sorted by date(year, then month) then by title
bool Periodical::operator>(const NodeData& other) const {
    if(const Periodical* oPeriodical = dynamic_cast<const Periodical*>(&other)) {
        return !operator<(other);
    }
    return false;
}

//----------------------------------------------------------------------------
// display
// outputs publication uniformly to console, truncates if title is too long
void Periodical::display() const {
    cout << left  << setw(7) << count; 
    displayInfo();
}

//----------------------------------------------------------------------------
// displayInfo
// outputs publication uniformly to console, truncates if title is too long
void Periodical::displayInfo() const {
        cout << right
        << setw(3) << month 
        << right << setw(10) << year << "    "
        << setw(20) << left << title << endl;
}

//----------------------------------------------------------------------------
// displayHeading
// Displays to the user a heading before reading list of periodical books
void Periodical::displayHeading() const {
    cout << endl;
    cout << "PERIODICAL PUBLICATIONS" << endl;
    cout << right
    << setw(5) << "AVAIL" 
    << setw(6) << "MONTH"
    << right << setw(9) << "YEAR" 
    <<  "    TITLE" << endl;

}