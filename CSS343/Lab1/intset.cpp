// A intset holds a boolean value of a set of integer

#include "intset.h"
//----------------------------------------------------------------------------
//IntSet constructor
//Parameters are integers to be put in the set
//Has to be greater than 0
IntSet::IntSet(int first, int second, int third, int fourth, int fifth) {
    size = 0; 
    int inset[5] = {first, second, third, fourth, fifth};
    //Getting the highest number 
    for(int i = 0; i < 5; i++) {
        if(inset[i] > size) {
            size = inset[i] + 1; 
        }
    }
    //Setting size of bool array
    if(size > 0) {
        set = new bool[size]{0};
    } else {
        set = new bool[1]{0};
    }
    //Indexing all values
    for(int i = 0; i < 5; i++) {
        if(inset[i] > -1) {
            set[inset[i]] = 1;
        }
    }
}

//----------------------------------------------------------------------------
// IntSet copy constructor
// Makes a deep copy of incoming intset
IntSet::IntSet(const IntSet &other) {
    size = other.size; 
    set = new bool[size] {0};

    for(int i = 0; i < size; i++) {
        set[i] = other.set[i];
    }
}

//----------------------------------------------------------------------------
// IntSet Deconstructor 
// Deletes the set 
IntSet::~IntSet() {
    delete[] set; 
}

//----------------------------------------------------------------------------
// is Empty 
// Returns true if the array is empty 
bool IntSet::isEmpty() { return size == 0; }

//----------------------------------------------------------------------------
// isInSet
// Returns true if the number is in the set
bool IntSet::isInSet(int num) {
    return(num > -1 && num < size && set[num]);
}

//----------------------------------------------------------------------------
// insert
// Inserts a value into the set
// Will not accept the integer if is negative 
bool IntSet::insert(int num) {
    if(0 > num) {return false;}

    
    if(num > size) { 
         //creating new array 
        bool *temp = new bool[num + 1] {false};
        //copying from old array
        for(int i = 0; i < size; i++) {
            temp[i] = set[i];
        }
        size = num + 1;
        delete[] set; 
        set = temp; 
    }
    //input new num into array
    set[num] = true;
    return true; 
}

//----------------------------------------------------------------------------
// remove 
// Will remove a certain value in the set 
// Returns false and doesn't change anything if int not in set
bool IntSet::remove(int num) {
    if((num > size) || (num < 0)) {return false;}
    set[num] = 0;
    return true; 
}

//----------------------------------------------------------------------------
// operator== 
// overloaded ==: Compares all values inside intset
// to see if two intsets are the same
bool IntSet::operator==(const IntSet& other) const {
    if(size != other.size) {return false;}
    for(int i = 0; i < size; i++) {
        if(set[i] =! other.set[i]) {
            return false;
        }
    }
    return true; 
}

//----------------------------------------------------------------------------
// operator != 
// overloaded !=: true if object is != parameter and returns false otherwise
bool IntSet::operator!=(const IntSet& other) const
{
    return (!(*this == other));
}

//----------------------------------------------------------------------------
// operator<< 
// overloaded <<: outputs all the integers within brackets {}
ostream& operator<<(ostream& output, const IntSet &list) {
    output << "{";
    //output all valid ints
    for(int i = 0; i < list.size; i++) {
        if(list.set[i] == 1) {
                output << " " << i;
        }
    }
    output <<"}";
    return output;
}

//----------------------------------------------------------------------------
// operator>>
// overloaded >>: takes in a set of integers, doesn't allow negative numbers
istream& operator>>(istream& input, IntSet& list) {
    int temp; 
    //global initlizaition of temp var
    input >> temp; 
    while(temp != -1) {
        if(temp < 0) {
            input >> temp; 
        }
        //inserting into set as long as valid num
        list.insert(temp);
        input >> temp; 
    }
    return input; 
}

//----------------------------------------------------------------------------
// IntSet operator+
// overloaded +: returns the union of two sets 
IntSet IntSet::operator+(const IntSet& other) const {
    //initalizing new set
    IntSet retSet(max(size,other.size) - 1);
    //adding ints from each set
    for(int i = 0; i < retSet.size; i++) {
        if(i < size && set[i]) {
            retSet.set[i] = true; 
        }
        if(i < other.size && other.set[i]) {
            retSet.set[i] = true; 
        }
    }
    return retSet; 
}

//----------------------------------------------------------------------------
// IntSet operator-
// IntSet operator-
// overloaded -; returns the difference of current set to incoming set
IntSet IntSet::operator-(const IntSet& other) const {
    //Copying set and initlizaing smaller int
    IntSet retSet(*this);
    int length = min(size, other.size); 
    //Getting rid of int that are in both sets
    for(int i = 0; i < length; i++) {
        if(set[i] == other.set[i]) {
            retSet.set[i] = false;
        }
    }
    return retSet; 
}

//----------------------------------------------------------------------------
// IntSet operator*
//overloaded *: 
IntSet IntSet::operator*(const IntSet& other) const {
    //initalizing smaller value and new set
    int length = min(size, other.size);
    IntSet retSet(length - 1); 
    retSet.set[length - 1] = false; 
    //Checking which int are in both sets
    for(int i = 0; i < retSet.size; i++) {
        if(set[i] == other.set[i]) {
            retSet.set[i] = set[i];
        }
    }
    return retSet; 
}

//----------------------------------------------------------------------------
// IntSet operator= 
// overload =: Makes the lhs equal to the rhs intset object 
IntSet& IntSet::operator=(const IntSet& other) {
    //does nothing if already equal
    if(set == other.set) {return *this;}
    //delete old set and initalize
    // a new set equal to the size of the incoming set
    delete[] set;
    size = other.size; 
    set = new bool[size] {0};
    //Moving everything over
    for(int i = 0; i < size; i++) {
        set[i] = other.set[i];
    }
    return *this; 
}

//----------------------------------------------------------------------------
// IntSet Operator+= 
// overload+=: union assignment operator
IntSet& IntSet::operator+=(const IntSet& other) {
    //initize i and length
    int i; 
    int length = max(size, other.size);
    bool *temp = new bool[length] {false};

    //Check if num is in either, if yes, then add to new array
    for(i = 0; i < length; i++) {
        if(i < size && i < other.size) {
            if(set[i] || other.set[i]) {
                temp[i] = true;
            }
        } else {
            break; 
        }
    }
    //Continue to check between the difference in length of shoter
    //to longer array
    if(i >= size) {
        for(; i < length; i++) {
            temp[i] = other.set[i];
        }
    } else {
        for(; i < length; i++) {
            temp[i] = set[i];
        }
    }
    //set old bool array to new array
    size = length;
    delete[] set; 
    set = temp;  
    return *this; 
}

//----------------------------------------------------------------------------
// IntSet operator*=
// *=: intersection assignment operator
IntSet& IntSet::operator*=(const IntSet& other) {
    //find length of longer intset
    int length = min(size, other.size);
    bool *temp = new bool[length] {false};

    //if in both, put in new set
    for(int i = 0; i < length; i++) {
        if(set[i] && other.set[i]) {
                temp[i] = true;
        }
    }
    //Set old bool array to new one
    size = length;
    delete[] set; 
    set = temp; 
    return *this; 
}

//----------------------------------------------------------------------------
// IntSet operator-=
// -=: difference assignment operator
IntSet& IntSet::operator-=(const IntSet& other) {
    //initaize length of set
    int length; 
    if(size > other.size) {
        length = other.size; 
    } else {
        length = size; 
    }
    bool *temp = new bool[length]{0};
    //Check to see if num is in first set and not in other
    for(int i = 0; i < length; i++) {
        if(i < size && i < other.size) {
            if(set[i] && !other.set[i]) {
                temp[i] = 1;
            }
        } else {
            break; 
        }
    }
    //Set old bool array to new one
    size = length; 
    delete[] set;
    set = temp; 
    return *this; 
}
//----------------------------------------------------------------------------
// min 
// helper method: finds minimum int
int IntSet::min(int const a, int const b) const {
    if(a < b) { return a;} 
    return b; 
}
//----------------------------------------------------------------------------
// max
// helper method: finds maximum int
int IntSet::max(int const a, int const b) const {
    if(a > b) {return a;}
    return b;
}