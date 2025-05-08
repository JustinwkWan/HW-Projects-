#include <list> 
#include <iostream> 

using namespace std; 

void printList(list<int> num) 
{
    for(int number : num) 
        {
            cout << number << " , ";
        }
}
int main() {
    list<int> nums;
    for(int i = 0; i < 5; i++) 
    {
        nums.push_back(1 + i*2);
    }
    for(int i = 1; i < 6; i++) {
        nums.push_front(i*2);
    }
    cout << "List elements: ";
    printList(nums);
    cout << endl;
    cout << "front number " << nums.front() << endl;
    cout << "back number " << nums.back() << endl; 
    list<int>::iterator it = nums.begin();
    advance(it,2);
    nums.erase(it);
    cout << "List after deleting the third element(6): ";
    printList(nums);

    nums.sort();
    cout << endl;
    cout << "List after sorting ";
    printList(nums);
    cout << endl;
    nums.remove_if([](int n) { return n % 2 != 0; });
    //Got the code  for line 38 off of stackoverflow
    cout << "List after deleting odd numbers"; 
    printList(nums);


}