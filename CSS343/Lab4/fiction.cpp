#include "fiction.h"

Fiction::Fiction(const string& a, const string& t, const int y) {
    author = a; 
    title = t; 
    year = y; 
}


bool Fiction::operator<(const Publication& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
        if(author != oFiction->author) {
            return(title < oFiction->title);
        }
        return(author < oFiction->author);
    
    return false;
}

bool Fiction::operator==(const Publication& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
    return(author == oFiction->author && title == oFiction->title);
    return false;
}

bool Fiction::operator>(const Publication& other) const {
    const Fiction* oFiction = static_cast<const Fiction*>(&other);
    return !(operator<(other));
}