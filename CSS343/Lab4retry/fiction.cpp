#include "fiction.h"
#include "library.h"
//----------------------------------------------------------------------------
// constructor
// initlizes count of books to 5
Fiction::Fiction() {
    count = 5;
}

//----------------------------------------------------------------------------
// deconstructor
Fiction::~Fiction() { }

//----------------------------------------------------------------------------
// create
// returns a new fiction object to go to publication factory
NodeData* Fiction::create() const {
    return new Fiction;
}

//----------------------------------------------------------------------------
// operator< 
// checks to see if lhs < rhs
// sorted by author then title
bool Fiction::operator<(const NodeData& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
        if(author == oFiction->author) {
            return(title < oFiction->title);
        }
        return(author < oFiction->author);
    
    return false;
}

//----------------------------------------------------------------------------
// operator==
// checks to see if lhs == rhs
// sorted by author then title
bool Fiction::operator==(const NodeData& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
    return(author == oFiction->author && title == oFiction->title);
}

//----------------------------------------------------------------------------
// operator> 
// checks to see if lhs > rhs
// sorted by author then title
bool Fiction::operator>(const NodeData& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
    return !(operator<(other));
}

//----------------------------------------------------------------------------
// setData
// sets data for each publication
// does error checking to see if data is valid
bool Fiction::setData(istream& infile) {
        infile.get();
        getline(infile, author, ',');

        infile.get();
        getline(infile, title, ',');

        infile >> year;
        return true;
}

//----------------------------------------------------------------------------
// setSortingData
// does the same as set data but sorting data has different input b
// C 8000 F H Kerouac Jack, On the Road,
bool Fiction::setSortingData(istream& infile) {
    char format;
    string s;
    infile >> format;
    if(format != 'H') { 
        getline(infile, s);
        return false;
    }
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, title, ',');

    return true;
}

//----------------------------------------------------------------------------
// display
// outputs publication uniformly to console, truncates if title is too long
void Fiction::display() const { 
    cout << left
        << setw(7) << count;
        displayInfo();
}

//----------------------------------------------------------------------------
// displayInfo
// outputs publication uniformly to console, truncates if title is too long
void Fiction::displayInfo() const {
        cout << left
        << setw(TITLE_MAX_LENGTH+2) << author.substr(0,TITLE_MAX_LENGTH)
        << setw(TITLE_MAX_LENGTH+2) << title.substr(0,TITLE_MAX_LENGTH + 1) 
        << setw(5) << year << endl;
}

//----------------------------------------------------------------------------
// displayHeading
// Displays to the user a heading before reading list of fiction books
void Fiction::displayHeading() const {   
    cout << endl;
    cout << "FICTION PUBLICATIONS" << endl;
    cout << left 
    << setw(7) << "AVAIL" 
    << setw(TITLE_MAX_LENGTH+2) << "AUTHOR"
    << setw(TITLE_MAX_LENGTH+2) << "TITLE" 
    << setw(5) << "YEAR" << endl;
    
}