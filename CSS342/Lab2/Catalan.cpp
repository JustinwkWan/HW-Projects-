#include <iostream> 
using namespace std;
int catalan(int n);
int main(int argc, char* argv[]) {
    //int input = stoi(argv[1]);  
    //cout << "The input is " << input <<  " with the number as " << catalan(input) << endl;
    cout << "catalan 4 = " << catalan(4) << endl;
    cout << "catalan 5 = " << catalan(5) << endl;
    cout << "catalan 6 = " << catalan(6) << endl;
    cout << "catalan 7 = " << catalan(7) << endl;
    return 0;
}
int catalan(int n) 
{
    if(n <= 1) 
    {
        return 1; 
    }
    int result = 0; 
    for(int i = 0; i < n; i++) 
    {
        result += catalan(i) * catalan(n-i-1); 
    }
    return result; 
}
