#include <iostream> 
#include <fstream> 
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
    LinkedList(string FileName);
    bool BuildList(string fileName);
    bool insert(int *obj); 
    void printList(); 
    void DeleteList();
    bool deleteNode(int); 
    bool isEmpty();
private: 
    int count = 0;
}; 
  