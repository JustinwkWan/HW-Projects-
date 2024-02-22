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
            Insert(&item);
        }
    } else 
    {
        cout << "File:" << fileName << "was not opened" << endl;
        return false;
    }
    inFile.close();
    return true;
}

bool LinkedList::IsEmpty()
{
    return count == 0;
}

bool LinkedList::Insert(int *obj)
{
    Node* newNode = new Node;
    Node* temp = head; 
    newNode->data = obj;
    if(head == NULL || *head->data > *obj)
    {
        newNode->next = head;
        head = newNode; 
        count++;
        return true; 
    }
    if(*head->data == *obj)
    {
        delete newNode;
        return false;
    } 

    while(temp->next != NULL && *temp->next->data <= *obj)
    {   
        if(*temp->next->data == *obj) return false;
        temp = temp->next; 
    }
    newNode->next = temp->next; 
    temp->next = newNode; 
    count++;    
    return true; 
}

bool LinkedList::Remove(int target, int &result)
{
    Node *temp = head;
    Node *delNode;
    result = -1;
    if(head == NULL)
    {
        return false;
    }
    if(*head->data == target)
    {
        result = target;
        head = head->next; 
        delete temp;
        return true; 
    }


    while(temp->next != NULL && *(temp->next->data) != target)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return false;
    }
    result = target;
    delNode = temp->next;   
    temp->next = temp->next->next;

    delete delNode;
    return true; 
}

bool LinkedList::Peek(int target,int &result) 
{
    result = -1;
    Node* temp = head; 
    if(temp == NULL)
    {
        return false;
    }
    while(temp != NULL)
    {
        if(*temp->data == target)
        {
            result = *temp->data;
            return true; 
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::PrintList()
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
    Node *temp = head;
    while(temp != NULL)
    {
        this->head = head->next;
        delete temp;
        temp = head;
    }
}