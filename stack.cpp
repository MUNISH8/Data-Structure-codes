#include<iostream>
using namespace std;

int stack[100],Top=0,maxElement=100;

bool isEmpty()
{
    return Top==0;
}

bool isFull()
{
    return Top==maxElement;
}

bool push(int Element)
{
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }

    else
    {
        stack[Top]=Element;
        Top++;
        return true;

    }
}

bool pop()
{
    if(isEmpty())
    {
        cout<<"The stack is Underflow"<<endl;
        return false;
    }
    else
    {
        Top--;
        return true;
    }
}

int topElemnt()
{
    if(isEmpty())
    {
        cout<<"The Stack is Empty"<<endl;
        return -1;
    }
    else
    {
        return stack[Top-1];
    }
}

void show()
{
    if(isEmpty())
    {
        cout<<"The Stack is Empty"<<endl;
        return;
    }
    else
    {
        cout<<"Stack Elemnts: ";
        
        for(int i=0;i<Top;i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(35);
    push(42);
    show();
    cout<<"Top Element: "<<topElemnt()<<endl;

    pop();
    show();
    return 0;
}
