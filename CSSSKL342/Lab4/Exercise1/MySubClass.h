#include "MyClass.h"
#include <iostream>

class MySubClass : public MyClass
{
    public:
    MySubClass();
    MySubClass(const MySubClass& o);
    ~MySubClass();

    MySubClass& operator=(const MySubClass& rhs);

    void setSubClassData(int x);

    int getSubClassData() const;
    
    friend ostream& operator<<(ostream &o, const MySubClass &s);
    
    void clear(); 

    private:
    int subClassData;
};