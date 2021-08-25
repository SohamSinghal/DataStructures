//First In Last Out(FILO) or Last In First Out(LIFO)
// 2 5 8 9 3
#include <iostream>
using namespace std;
#define size 5
int stack[size],top = -1;
bool problem()
{
    if(top == -1)
    {
        cout<<"Stack Underflow"<<endl;
        return true;
    }
    else if(top>4)
    {
        cout<<"Stack Overflow"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}
void push(int x)
{
    top++;
    if(!problem())
    {
        stack[top] = x;
    }
}
int pop()
{
    if (!problem())
    {
        int popped;
        popped = stack[top];
        top--;
        return popped;
    }
}
void display()
{
    if(!problem())
    {   
        for(int i =top;i>=0;i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }   
}
int main()
{
    display();
    push(3);
    push(9);
    push(8);
    push(5);
    push(2);
    display();
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    display();
}