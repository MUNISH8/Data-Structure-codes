#include <iostream>
using namespace std;
 
class Queue
{
private:
    static const int MAX_SIZE = 100; // max capacity of the queue
    int arr[MAX_SIZE]; // array to store the queue elements
    int front; // index of the front element
    int rear; // index of the rear element
    int size; // current number of elements in the queue
 
public:
    // Constructor
    Queue()
    {
        front = 0;
        rear = -1;
        size = 0;
    }
 
    // Check if queue is empty
    bool isEmpty()
    {
        return (size == 0);
    }
 
    //Check if queue is full
    bool isFull()
    {
        return (size == MAX_SIZE);
    }
 
    // Add element to the rear of the queue
    void enqueue(int value)
    {
         if (isFull())
         {
            cout << "Queue is full, cannot enqueue new element" << endl;
            return;
         }
         // linear enqueue in rear
         // rear++;
         // circular enqueue in rear
         rear = (rear + 1) % MAX_SIZE;
         arr[rear] = value;
         size++;
    }
 
    // Remove element from the front of the queue
    int dequeue(){
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return -1;
        }
        int removedValue = arr[front];
        // linear dequeue
        // front++;
        // circular dequeue
        front = (front + 1) % MAX_SIZE;
        size--;
        return removedValue;
    }
 
    // Get the front element without removing
    int peek(){
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
 
    // Sequentially display elements from front to rear
    void display(){
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < size; i++)
        {
            cout << arr[index] << " ";
            // for linear queue
            // index++;
            // for circular queue
            index = (index + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};
 
int main(){
    Queue q;
 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
 
    q.display();
 
    cout << "Front element: " << q.peek() << endl;
 
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
 
    q.display();
 
    q.enqueue(40);
    q.enqueue(50);
 
    q.display();
    return 0;
}