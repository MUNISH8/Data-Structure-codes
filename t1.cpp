#include <iostream>
using namespace std;
 
// ===============================
// Singly linked List
// ==============================
 
class SinglyLinkedList{
private:
    struct Node{
        int data;
        Node* next;
    };
 
    Node* head;
 
public:
    //Constructor
    SinglyLinkedList(){
        head = NULL;
    }
 
    // Function to check if list is empty
    bool isEmpty(){
        return head == NULL;
    }
 
    // Insert value in front of list
    void pushFront(int value){
        Node* n = new Node;
        n->data = value;
        n->next = head;
        head = n;
    }
    //Insert value at the end of the list
    void pushBack(int value)
    {
        Node* n = new Node;
        n->data = value;
        n->next = NULL;
    
        if (head==NULL)
        head = n;
        return;
        Node* cur =head;
     while(cur->next !=NULL)
    {
        cur =cur->next;
    }
     }


    //insert in any position 
    bool insertAt(int index,int value)
    
    {
      if (index < 0) return false;
      if (index==0)
      {
      pushFront(value);
      return true;
      }

      Node* cur = head;
      int i =0;
      while (cur !=NULL && i<index -1)
      {
        cur = cur ->next;
        i++;
      }
      if(cur ==NULL) return false;//index out of bound

      Node* n=new Node;
      n->data=value;
      n->next=cur->next;
      cur->next=n;
      return true;
    }

    //remove element from the front of the list
    bool popFront ()
    {
        if (head==NULL)return false;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    //remove element from the back of the list 
    bool popBack()
    {
        if(head==NULL) return false;
        if (head->next ==  NULL)
        {
            delete head;
            head=NULL;
            return true;
        }
    }

    //Destructor
    ~SinglyLinkedList(){
        // To implement unused memory clearing method
    }
};;