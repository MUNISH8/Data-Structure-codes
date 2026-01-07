#include <iostream>
using namespace std;
 
class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
 
        Node(int k) : key(k), left(NULL), right(NULL) {}
    };
 
    Node* root;

    Node* insertRec(Node* cur, int key) {
        if (cur == NULL) return new Node(key);
 
        if (key < cur->key) cur->left = insertRec(cur->left, key);
        else if (key > cur->key) cur->right = insertRec(cur->right, key);
        return cur;
    }
 
    bool searchRec(Node* cur, int key) const {
        if (cur == NULL) return false;
        if (key == cur->key) return true;
        if (key < cur->key) return searchRec(cur->left, key);
        return searchRec(cur->right, key);
    }
 
    Node* findMin(Node* cur) const {
        while (cur->left != NULL) cur = cur->left;
        return cur;
    }
 
    Node* removeRec(Node* cur, int key) {
        if (cur == NULL) return NULL;
 
        if (key < cur->key) {
            cur->left = removeRec(cur->left, key);
        } else if (key > cur->key) {
            cur->right = removeRec(cur->right, key);
        } else {
            // Found node to delete
            if (cur->left == NULL && cur->right == NULL) {
                delete cur;
                return NULL;
            } else if (cur->left == NULL) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            } else if (cur->right == NULL) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            } else {
                // Two children: replace with inorder successor (min of right subtree)
                Node* succ = findMin(cur->right);
                cur->key = succ->key;
                cur->right = removeRec(cur->right, succ->key);
            }
        }
        return cur;
    }
 
    void inorderRec(Node* cur) const {
        if (cur == NULL) return;
        inorderRec(cur->left);
        cout << cur->key << " ";
        inorderRec(cur->right);
    }
 
    void preorderRec(Node* cur) const {
        if (cur == NULL) return;
        cout << cur->key << " ";
        preorderRec(cur->left);
        preorderRec(cur->right);
    }
 
    void postorderRec(Node* cur) const {
        if (cur == NULL) return;
        postorderRec(cur->left);
        postorderRec(cur->right);
        cout << cur->key << " ";
    }
 
    int heightRec(Node* cur) const {
        if (cur == NULL) return -1; // height of empty tree as -1 (so leaf = 0)
        int hl = heightRec(cur->left);
        int hr = heightRec(cur->right);
        return (hl > hr ? hl : hr) + 1;
    }
 
    int countRec(Node* cur) const {
        if (cur == NULL) return 0;
        return 1 + countRec(cur->left) + countRec(cur->right);
    }
 
    void destroyRec(Node* cur) {
        if (cur == NULL) return;
        destroyRec(cur->left);
        destroyRec(cur->right);
        delete cur;
    }
 
public:
    BST() : root(NULL) {}
 
    ~BST() {
        destroyRec(root);
        root = NULL;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }
 
    bool search(int key) const {
        return searchRec(root, key);
    }
 
    void remove(int key) {
        root = removeRec(root, key);
    }
 
    void inorder() const {
        inorderRec(root);
        cout << "\n";
    }
 
    void preorder() const {
        preorderRec(root);
        cout << "\n";
    }
 
    void postorder() const {
        postorderRec(root);
        cout << "\n";
    }
 
    int height() const {
        return heightRec(root);
    }
 
    int countNodes() const {
        return countRec(root);
    }
 
    bool empty() const {
        return root == NULL;
    }
};

int main() {
    BST t;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    for (int i = 0; i < n; i++) t.insert(values[i]);
 
    cout << "Inorder (sorted): ";
    t.inorder();
 
    cout << "Preorder: ";
    t.preorder();
 
    cout << "Postorder: ";
    t.postorder();
 
    // Search
    cout << "Search 60: " << (t.search(60) ? "Found" : "Not Found") << "\n";
    cout << "Search 25: " << (t.search(25) ? "Found" : "Not Found") << "\n";
 
    // Delete cases: leaf, one child, two children
    t.remove(20); // leaf
    t.remove(30); // one child (after removing 20)
    t.remove(50); // two children
 
    cout << "After deletions, inorder: ";
    t.inorder();
 
    cout << "Height: " << t.height() << "\n";
    cout << "Node count: " << t.countNodes() << "\n";
 
    return 0;
}