#include<iostream>
using namespace std;

//DLL - 2,4,7,8
struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head;//Global variable for head
//Fuction to get a node from user and return its pointer
Node *GetNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//function to insert node at head
void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head=newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
//function to insert node at the tail
void InsertAtTail(int x)
{
    Node *temp = head;
    Node *newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
//Insert node at a place
void Insert(Node *n,int x)
{
    if (n != NULL)
    {
        Node *newNode = GetNewNode(x);
        newNode->data = x;
        newNode->next = n->next;
        n->next = newNode;
    }
}
//Print normally
void print(Node *n)
{
    if(n == NULL)
    {
        cout<<"Empty List"<<endl;
        return;
    }
    cout<<"Forward Print"<<endl;
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
//Print in Reverse
void print_reverse(Node *n)
{
    if(head == NULL)
    {
        cout<<"Empty List"<<endl;
        return;
    }
    while(n->next != NULL)
    {
        n = n->next;
    }
    cout<<"Print in reverse"<<endl;
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->prev;
    }
    cout<<endl;
}
//Main function
int main()
{
    head = NULL;
    InsertAtHead(7);
    InsertAtHead(4);
    InsertAtHead(2);
    //2 4 7
    print(head);
    InsertAtTail(8);
    //2 4 7 8
    print(head);
    //8 7 4 2
    print_reverse(head);
    //2 4 9 7 8 
    Insert(head->next,9);
    print(head);
}
