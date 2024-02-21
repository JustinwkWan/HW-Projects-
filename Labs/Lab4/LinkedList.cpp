#include "LinkedList.h"
#include <fstream> 

LinkedList::LinkedList()
{
    head = NULL;    
}

bool LinkedList::BuildList(string fileName)
{
    ifstream inFile; 
    inFile.open(fileName);
    if(inFile)
    {
        while(!inFile.eof())
        {
            int item; 
            inFile >> item; 
            insert(&item);
        }
    } else 
    {
        cout << "File:" << fileName << "was not opened" << endl;
        return false;
    }
    inFile.close();
    return true;
}


bool LinkedList::isEmpty()
{
    return count == 0;
}

bool LinkedList::insert(int *obj)
{
    Node* newNode = new Node;
    Node* temp; 
    newNode->data = obj;

    if(head == NULL || head->data > newNode->data)
    {
        newNode->next = head;
        head = newNode; 
        count++;
    } else {
        temp = head; 
        while(temp->next != NULL && *temp->next->data < *obj)
        {
            //Put in code to say no to == numbers
            temp = temp->next; 
        }
        newNode->next = temp->next; 
        temp->next = newNode; 
        count++;
    }
    //Memory leak when newNode is not deleted
    //Nodes are not inserted when delete newNode is called
    //delete newNode;
    //
    return true; 
}

void LinkedList::printList()
{
    if(head == NULL)
    {
        cout << "List is empty";
    }
Node* temp = head;
    while (temp != NULL) {
        
        cout << *(temp->data) << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::DeleteList()
{   
    Node *temp = head, *next;

    while(temp != NULL)
    {
        next = temp->next; 
        temp = NULL;
        delete temp;
        temp = next; 
    }
    head->data = NULL;
    delete head; 
    head = NULL; 
    count = 0; 
}