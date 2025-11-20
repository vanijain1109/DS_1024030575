#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};
class BST {
public:
    Node* root;
    BST() : root(NULL) {}
    void insert(int x) {
        root = insertRec(root, x);
    }
private:
    Node* insertRec(Node* node, int x) {
        if (!node) return new Node(x);
        if (x < node->data) node->left = insertRec(node->left, x);
        else if (x > node->data) node->right = insertRec(node->right, x);
        return node;
    }
public:
    Node* searchRec(Node* node, int key) {
        if (!node || node->data == key) return node;
        if (key < node->data) return searchRec(node->left, key);
        return searchRec(node->right, key);
    }
    Node* searchIter(int key) {
        Node* cur = root;
        while (cur) {
            if (key == cur->data) return cur;
            if (key < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return NULL;
    }
    Node* findMax(Node* node) {
        if (!node) return NULL;
        while (node->right) node = node->right;
        return node;
    }
    Node* findMin(Node* node) {
        if (!node) return NULL;
        while (node->left) node = node->left;
        return node;
    }
    Node* inorderSuccessor(int key) {
        Node* target = searchIter(key);
        if (!target) return NULL;
        if (target->right) return findMin(target->right);
        Node* succ = NULL;
        Node* cur = root;
        while (cur) {
            if (key < cur->data) {
                succ = cur;
                cur = cur->left;
            } else if (key > cur->data) {
                cur = cur->right;
            } else break;
        }
        return succ;
    }
    Node* inorderPredecessor(int key) {
        Node* target = searchIter(key);
        if (!target) return NULL;
        if (target->left) return findMax(target->left);
        Node* pred = NULL;
        Node* cur = root;
        while (cur) {
            if (key > cur->data) {
                pred = cur;
                cur = cur->right;
            } else if (key < cur->data) {
                cur = cur->left;
            } else break;
        }
        return pred;
    }
};
int main() {
    BST t;
    int items[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : items) t.insert(x);
    cout << "Search 40 (rec): " << (t.searchRec(t.root, 40) ? "Found\n" : "Not found\n");
    cout << "Search 99 (iter): " << (t.searchIter(99) ? "Found\n" : "Not found\n");
    Node* mx = t.findMax(t.root);
    Node* mn = t.findMin(t.root);
    cout << "Min = " << (mn ? mn->data : -1) << ", Max = " << (mx ? mx->data : -1) << "\n";
    int k = 60;
    Node* s = t.inorderSuccessor(k);
    Node* p = t.inorderPredecessor(k);
    cout << "Successor of " << k << " = " << (s ? s->data : -1) << "\n";
    cout << "Predecessor of " << k << " = " << (p ? p->data : -1) << "\n";
    return 0;
}
