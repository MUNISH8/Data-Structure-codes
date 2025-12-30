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
 
    // Insert value at the end of the list
    void pushBack(int value){
        Node* n = new Node;
        n->data = value;
        n->next = NULL;
 
        if (head == NULL){
            head = n;
            return;
        }
 
        Node* cur = head;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = n;
    }
 
    // Insert at any position
    bool insertAt(int index, int value){
        if (index < 0) return false;
        if (index == 0){
            pushFront(value);
            return true;
        }
 
        Node* cur = head;
        int i = 0;
        while(cur != NULL && i < index - 1){
            cur = cur->next;
            i++;
        }
        if (cur == NULL) return false; // index out of bound
 
        Node* n = new Node;
        n->data = value;
        n->next = cur->next;
        cur->next = n;
        return true;
    }
 
    // Remove element from the front of the list
    bool popFront(){
        if (head == NULL) return false;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
 
    // Remove element from the back of the list
    bool popBack(){
        if (head == NULL) return false;
        if (head->next == NULL){
            delete head;
            head = NULL;
            return true;
        }
 
        Node* prev = NULL;
        Node* cur = head;
        while(cur->next != NULL){
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        delete cur;
        return true;
    }
 
    // Delete element from any position of the list
    bool removeAt(int index){
        if (index < 0 || head == NULL) return false;
        if (index == 0) popFront();
 
        Node* cur = head;
        int i = 0;
        while (cur == NULL && i < index - 1){
            cur = cur->next;
            i++;
        }
        if (cur == NULL || cur->next == NULL) return false;
 
        Node* nodeToDelete = cur->next;
        cur->next = nodeToDelete->next;
        delete nodeToDelete;
        return true;
    }
 
    // search if a value is present
    bool search(int value){
        Node* cur = head;
        while (cur != NULL){
            if (cur->data == value) return true;
            cur = cur->next;
        }
        return false;
    }
 
    // find the number of elements in linked list
    int size(){
        int count = 0;
        Node* cur = head;
        while (cur != NULL){
            count++;
            cur = cur->next;
        }
        return count;
    }
 
    // Display the list
    void display(){
        Node* cur = head;
        cout << "List contents: ";
        while (cur != NULL){
            cout << cur->data;
            if (cur->next != NULL) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
 
    void clear(){
        Node* cur = head;
        while (cur != NULL){
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = NULL;
    }
 
    //Destructor
    ~SinglyLinkedList(){
        clear();
    }
};
 
int main(){
    SinglyLinkedList sll;
    sll.pushBack(10);
    sll.pushBack(20);
    sll.pushFront(5);
    sll.insertAt(2, 15);
    sll.display();
    cout << "Sll size: " << sll.size() << endl;
    cout << "Search 5: " << (sll.search(5) ? "found" : "not found") << endl;
    sll.removeAt(1);
    sll.display();
    sll.popBack();
    sll.display();
    sll.popFront();
    sll.display();
    return 0;
}