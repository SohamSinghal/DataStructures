#include<iostream>
using namespace std;
//List - 2->4->3->6
//Create a  node
 struct Node{
    int data; //This will store the values of the list
     Node *next; //This pointer will help in pointing towards the next node
};
void display( Node *n)
{
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
void InsertElement( Node *prev,int y)
{
    if (prev != NULL)
    {
        Node *new_node;
        new_node = (Node*)malloc(sizeof( Node));
        new_node->data = y;
        new_node->next = prev->next;
        prev->next = new_node;
    }
    else
    {
        cout<<"End of list"<<endl;
    }
}
//Allocate ure to memory using malloc() 
int main()
{
    //Initializing the strucutres to NULL
    Node *head = NULL; //2->
    Node *first = NULL; //4->
    Node *second = NULL; //3->
    Node *third = NULL; //6
    head = ( Node *)malloc(sizeof( Node));
    first = ( Node *)malloc(sizeof( Node));
    second = ( Node *)malloc(sizeof( Node));
    third = ( Node *)malloc(sizeof( Node));
    //Assign values 2,4,3,6 to the Node and linking with pointer next
    head->data = 2;
    head->next = first;
    first->data = 4;
    first->next = second;
    second->data = 3;
    second->next = third;
    third->data = 6;
    third->next = NULL;
    //Displaying the linked list
    display(head);
    //2 4 3 6
    int x;
    cout<<"Enter a number"<<endl;
    cin>>x;
    InsertElement(second,x);
    display(head);
}