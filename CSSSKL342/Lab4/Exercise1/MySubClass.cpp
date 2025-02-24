#include "MySubClass.h"

ostream& operator<<(ostream &o, const MySubClass &s) 
{
    o << "Value: " << " i= " << s.getI() << " d= " << s.getD() 
    << " s= " << s.getS() << "*ip " << s.getIp() << " subClassData= " << s.getSubClassData();
    return o;  
}

MySubClass::MySubClass(): MyClass(), subClassData(0){}
MySubClass::MySubClass(const MySubClass &o): MyClass(o), subClassData(o.subClassData){}

int MySubClass::getSubClassData() const
{
     return subClassData;
}
 void MySubClass::setSubClassData(int x) 
 {
    subClassData = x;
 }
 MySubClass::~MySubClass()
{
    clear(); 
}

void MySubClass::clear()
{
    subClassData = 0; 
}

MySubClass& MySubClass::operator=(const MySubClass &other)
{
    MyClass::operator=(other);
    subClassData = other.subClassData;

    return *this; 
}
