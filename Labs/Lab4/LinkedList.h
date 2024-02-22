#include <iostream> 
#include <fstream> 
#include <vector>
using namespace std; 

class LinkedList { 
    struct Node
    {
        int *data = NULL;
        Node* next = NULL; 
    };

public: 
    Node* head; 
    LinkedList();  
    bool BuildList(string fileName);
    bool Insert(int *obj); 
    bool Peek(int target, int &result); 
    bool Remove(int target, int &result);
    void PrintList(); 
    void DeleteList();
    bool IsEmpty();
private: 
    int count = 0;
}; 
  