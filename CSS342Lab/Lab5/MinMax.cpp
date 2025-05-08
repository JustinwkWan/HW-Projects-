#include <iostream> 
#include <limits> 
using namespace std;

int main()
{
    cout << "Min and max for ints" << endl;
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
    
    cout << "Min and max for floats" << endl;
    cout << numeric_limits<float>::min() << endl;
    cout << numeric_limits<float>::max() << endl;

    cout << "Min and max for unsigned ints" << endl;
    cout << numeric_limits<unsigned int>::min() << endl;
    cout << numeric_limits<unsigned int>::max() << endl;

    cout << "Min and max for double" << endl;
    cout << numeric_limits<double>::min() << endl;
    cout << numeric_limits<double>::max() << endl;

    cout << "Min and max for longs" << endl;
    cout << numeric_limits<long>::min() << endl;
    cout << numeric_limits<long>::max() << endl;

    cout << "Min and max for char" << endl;
    cout << numeric_limits<char>::min() << endl;
    cout << numeric_limits<char>::max() << endl;
    cout << "Doesn't work" << endl;
}
