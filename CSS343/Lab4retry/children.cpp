#include "children.h"

Publication* create() const {return new Children;}

bool Children::operator<(const Publication& other) const {
        if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
            if(title == oChild->title) {
                return(author < oChild->author);
            } else {
                return(title < oChild->title);
            }

    }
    return false;
}

bool Children::operator==(const Publication& other) const {
    if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
        return(author == oChild->author && title == oChild->title);
    }
    return false;
    
}

bool Children::operator>(const Publication& other) const {
    if(const Children* oChild = dynamic_cast<const Children*>(&other)) {
        return !(operator<(other));
    }
    return false;
}