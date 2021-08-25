#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *last;
//Insert in a empty list
void InsertInEmpty(int x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    if(last == NULL)
    {
        last = newNode;
        last->next = last;
    }
    else
    {
        cout<<"List is not empty"<<endl;
    }
}
//Insert at the end
void InsertAtEnd(int x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    if(last != NULL)
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    else
    {
        InsertInEmpty(x);
    }
}
//Insert At the beginning
void InsertAtStart(int x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    if(last != NULL)
    {
        newNode->next = last->next;
        last->next = newNode;
    }
    else
    {
        InsertInEmpty(x);
    }
}
//Print List
void display()
{
    if (last == NULL)
    {
        cout<<"Empty List"<<endl;
        return;
    }
    else
    {
        Node *temp = last->next;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp != last->next);
        cout<<endl;
    }
}
//2 5 7 9 8
int main()
{
    last = NULL;
    display();
    InsertInEmpty(7);
    cout<<last->data<<endl;
    InsertAtEnd(9);
    cout<<last->data<<endl;
    InsertAtEnd(8);
    cout<<last->data<<endl;
    InsertAtStart(5);
    cout<<last->data<<endl;
    InsertAtStart(2);
    display();
}