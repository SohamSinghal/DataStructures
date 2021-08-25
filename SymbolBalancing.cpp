//Use stack to balance symbol ( and )
#include<iostream>
#include<string>
using namespace std;

struct stack
{
    char data;
    stack *next;
};
stack *head = NULL;

//To check whether symbol is valid or not
bool validity(char x)
{
    if(x == '(' || x == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Initialize memory of new node
stack *GetNode(char x)
{
    stack *newNode;
    newNode = new stack;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void pop()
{
    stack *temp = head;
    head = head->next;
    delete temp;
    cout<<"popped"<<endl;
}
//To push the symbol if it is valid
void push(char x)
{
    if(validity(x))
    {
        stack *newNode;
        newNode = GetNode(x);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        if(head->data == char(x-1))
        {
            pop();
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    else
    {
        return;
    }
}
//Display the stack
void display()
{
    stack *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    push('(');
    cout<<"1st"<<endl;
    display();
    push('(');
    cout<<"2nd"<<endl;
    display();
    push(')');
    push('1');
    display();

}