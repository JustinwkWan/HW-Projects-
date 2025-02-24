#include "children.h" 

Children::Children(const string& a, const string& t, const int y) {
    author = a; 
    title = t; 
    year = y; 
}

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