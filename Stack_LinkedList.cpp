#include<iostream>
using namespace std;

struct Stack{
    int data;
    Stack *next;
};
Stack *head = NULL;

Stack* GetNew(int x){
    Stack *ptr;
    ptr = new Stack;
    ptr->data = x;
    return ptr;
}
void push(int x)
{
    Stack *newNode;
    newNode = GetNew(x);
    //First Stack is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}
void pop()
{
    int popped;
    Stack *temp = head;
    if(head == NULL)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else{
    popped = head->data;
    head = head->next;
    delete temp;
    cout<<popped<<endl;
    }
}

void display()
{
    Stack *temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    head = NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    pop();
    pop();
    display();
}