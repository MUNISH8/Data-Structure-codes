#include <iostream>
using namespace std;

class Stack
{
  private:
    static const int MAX_SIZE=100; //Max number of elements
    int arr[MAX_SIZE]; //array to store stack elements
    int top;


public:

    //constructor,when stack starts empty
    Stack()
    {
        top=-1;
    }
    //helper function to check if stack is empty
    bool isEmpty()
    {
        return (top==-1);
    }

    //helper function to check if stack is full
    bool isFull()
    {
        return(top==MAX_SIZE-1);
    }
    // push value on stack and return true if successfull
    //Return false if stack overflow
    bool push(int value)
    {
       if(isFull())
       {
        return false;
       }
       top++;
       arr[top]=value;
       return true;
    }
    
    //get the top value without removing it
    //Stores the top value in outValue
    //returns true if successful,flase otherwise

    bool peek(int &outValue)
    {
      if(isEmpty())
      {
        return false; //stack underflow
      }
      outValue=arr[top];
      return true;
    }
    // pop the value
    //Stores the top value in outValue
    //return true if successful,false otherwise
    bool pop(int &outValue)
    {
        if(isEmpty())
      {
        return false; //stack underflow
      }
      outValue=arr[top];
      top--;
      return true;
    }
    //return number of elements in stack
    int numOfElements()
    {
        return top+1;
    }
 
};
int main()
{
   Stack s;
   int value;//container variable to store peek and pop values
   cout<<"pushing 10,20,30 on stack....."<<endl;
   s.push(10);
   s.push(20);
   s.push(30);

   cout<<"Currrent number of elements: "<<s.numOfElements()<<endl;

   //peek top element
   if(s.peek(value))
   {
    cout<<"Top element (peek): "<<value<<endl;
   }
   else
   {
     cout<<"Stack is empty."<<endl;
   }
   //pop elements one by one
   cout<<"Popping all elements: "<<endl;
   while(!s.isEmpty())
   {
    s.pop(value);
    cout<<"popped "<<value<<endl;
   }
   //we try to pop from empty stack
   if(!s.pop(value))
   {
    cout<<"Cannot pop from empty stack"<<endl;
   }
   return 0;
}