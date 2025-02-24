#include "periodical.h"

Periodical::Periodical(string& a, string& t, int y) {
    this->author = a; 
    this->title = t; 
    year = y;
}

bool Periodical::operator<(const Publication& other) const {
    if (const Periodical* oPeriodical = dynamic_cast<const Periodical*>(&other)) {
        // if(author > oPeriodical->author) {
        //     if()
        // }
    }
    return true;
}

bool Periodical::operator==(const Publication& other) const {
    if(const Periodical* oPeriodical = dynamic_cast<const Periodical*>(&other)) {

    }
    return true;
}

bool Periodical::operator>(const Publication& other) const {
    if(const Periodical* oPeriodical = dynamic_cast<const Periodical*>(&other)) {

    }
    return true;
}

