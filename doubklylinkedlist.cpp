// =========================
// Doubly Linked List
// =========================
#include<iostream>
using namespace std;
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
 
    Node* head;
    Node* tail;
 
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}
 
    ~DoublyLinkedList() {
        clear();
    }
 
    bool isEmpty() const {
        return head == NULL;
    }
 
    void pushFront(int value) {
        Node* n = new Node;
        n->data = value;
        n->prev = NULL;
        n->next = head;
 
        if (head != NULL) head->prev = n;
        head = n;
 
        if (tail == NULL) tail = head;
    }
 
    void pushBack(int value) {
        Node* n = new Node;
        n->data = value;
        n->next = NULL;
        n->prev = tail;
 
        if (tail != NULL) tail->next = n;
        tail = n;
 
        if (head == NULL) head = tail;
    }
 
    bool popFront() {
        if (head == NULL) return false;
 
        Node* tmp = head;
        head = head->next;
 
        if (head != NULL) head->prev = NULL;
        else tail = NULL; // list became empty
 
        delete tmp;
        return true;
    }
 
    bool popBack() {
        if (tail == NULL) return false;
 
        Node* tmp = tail;
        tail = tail->prev;
 
        if (tail != NULL) tail->next = NULL;
        else head = NULL; // list became empty
 
        delete tmp;
        return true;
    }
 
    bool insertAt(int index, int value) {
        if (index < 0) return false;
        if (index == 0) {
            pushFront(value);
            return true;
        }
 
        Node* cur = head;
        int i = 0;
        while (cur != NULL && i < index) {
            cur = cur->next;
            i++;
        }
 
        if (cur == NULL) {
            // index == size -> append allowed
            if (i == index) {
                pushBack(value);
                return true;
            }
            return false;
        }
 
        // insert before cur
        Node* n = new Node;
        n->data = value;
        n->next = cur;
        n->prev = cur->prev;
 
        if (cur->prev != NULL) cur->prev->next = n;
        cur->prev = n;
 
        return true;
    }
 
    bool removeAt(int index) {
        if (index < 0 || head == NULL) return false;
        if (index == 0) return popFront();
 
        Node* cur = head;
        int i = 0;
        while (cur != NULL && i < index) {
            cur = cur->next;
            i++;
        }
        if (cur == NULL) return false;
 
        if (cur->prev != NULL) cur->prev->next = cur->next;
        if (cur->next != NULL) cur->next->prev = cur->prev;
 
        if (cur == tail) tail = cur->prev;
 
        delete cur;
        return true;
    }
 
    bool search(int value) const {
        Node* cur = head;
        while (cur != NULL) {
            if (cur->data == value) return true;
            cur = cur->next;
        }
        return false;
    }
 
    int size() const {
        int cnt = 0;
        Node* cur = head;
        while (cur != NULL) {
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }
 
    void displayForward() const {
        cout << "DLL (F): ";
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data;
            if (cur->next != NULL) cout << " <-> ";
            cur = cur->next;
        }
        cout << "\n";
    }
 
    void displayBackward() const {
        cout << "DLL (B): ";
        Node* cur = tail;
        while (cur != NULL) {
            cout << cur->data;
            if (cur->prev != NULL) cout << " <-> ";
            cur = cur->prev;
        }
        cout << "\n";
    }
 
    void clear() {
        Node* cur = head;
        while (cur != NULL) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = NULL;
        tail = NULL;
    }
};
 
int main() {
    DoublyLinkedList dll;
    dll.pushBack(10);
    dll.pushBack(20);
    dll.pushFront(5);
    dll.insertAt(2, 15); // 5 <-> 10 <-> 15 <-> 20
    dll.displayForward();
    dll.displayBackward();
    cout << "DLL size: " << dll.size() << "\n";
    cout << "Search 99: " << (dll.search(99) ? "found" : "not found") << "\n";
    dll.removeAt(3); // remove 20
    dll.displayForward();
    dll.popFront();
    dll.displayForward();
 
    return 0;
}