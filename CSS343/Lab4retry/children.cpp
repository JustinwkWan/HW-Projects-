#include "children.h"
//----------------------------------------------------------------------------
// constructor 
// sets count to 5
Children::Children() {
    count = 5;
}

//----------------------------------------------------------------------------
//destructor
Children::~Children() { }

//----------------------------------------------------------------------------
// create 
// creates children object for publicationfactory
NodeData* Children::create() const {
    return new Children;
}
//----------------------------------------------------------------------------
// setData
// sets data for each publication
// does error checking to see if data is valid
bool Children::setData(istream& infile) {
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, title, ',');
    infile >> year;
    // do some error checking
    return true;

}

//----------------------------------------------------------------------------
// setSortingData
// does the same as set data but sorting data has different input b
// 8000 F H Kerouac Jack, On the Road,
bool Children::setSortingData(istream& infile) {
    char format;
    string s;
    infile >> format;
    if(format != 'H') { 
        getline(infile, s);
        return false;
    }
    infile.get();
    getline(infile, title, ',');

    infile.get();
    getline(infile, author, ',');
    return true;
}

//----------------------------------------------------------------------------
// operator< 
// checks to see if lhs < rhs
// sorted by title then author
bool Children::operator<(const NodeData& other) const {
        // casting other to a children object as it is stored 
        // as a nodedata inside BinTree currently
        if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
            if(title == oChild->title) {
                return(author < oChild->author);
            } else {
                return(title < oChild->title);
            }

    }
    return false;
}

//----------------------------------------------------------------------------
// operator==
// checks to see if lhs == rhs
// sorted by title then author
bool Children::operator==(const NodeData& other) const {
    // casting other to a children object as it is stored 
    // as a nodedata inside BinTree currently
    if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
        return(author == oChild->author && title == oChild->title);
    }
    return false;
    
}

//----------------------------------------------------------------------------
// operator>
// checks to see if lhs > rhs
// sorted by title then author
bool Children::operator>(const NodeData& other) const {
    // casting other to a children object as it is stored 
    // as a nodedata inside BinTree currently
    if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
        return !(operator<(other));
    }
    return false;
}

//----------------------------------------------------------------------------
// display
// outputs publication uniformly to console, truncates if title is too long
void Children::display() const {
    cout << left << setw(7) << count;
    displayInfo();
}
//----------------------------------------------------------------------------
// displayInfo
// outputs publication uniformly to console, truncates if title is too long
void Children::displayInfo() const {
    cout << left   
    << setw(TITLE_MAX_LENGTH+2)  << title.substr(0, TITLE_MAX_LENGTH) 
    << setw(TITLE_MAX_LENGTH + 2) << author.substr(0, TITLE_MAX_LENGTH)
    << setw(5) << year << endl;
}
//----------------------------------------------------------------------------
// displayHeading
// Displays to the user a heading before reading list of childrens books
void Children::displayHeading() const {
    cout << endl;
    cout << "CHILDREN PUBLICATION" << endl;
    cout << left
    << setw(7) << "AVAIL" 
    << setw(TITLE_MAX_LENGTH+2) << "TITLE" 
    << setw(TITLE_MAX_LENGTH + 2) << "AUTHOR" 
    << setw(5) << "YEAR" << endl;
}
