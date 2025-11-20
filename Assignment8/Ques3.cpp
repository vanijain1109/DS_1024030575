#include <iostream>
#include <algorithm>
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
    void insert(int x) { root = insertRec(root, x); }
private:
    Node* insertRec(Node* node, int x) {
        if (!node) return new Node(x);
        if (x < node->data) node->left = insertRec(node->left, x);
        else if (x > node->data) node->right = insertRec(node->right, x);
        return node;
    }
public:
    void remove(int x) { root = deleteRec(root, x); }
private:
    Node* deleteRec(Node* node, int key) {
        if (!node) return NULL;
        if (key < node->data) node->left = deleteRec(node->left, key);
        else if (key > node->data) node->right = deleteRec(node->right, key);
        else {
            if (!node->left) {
                Node* r = node->right;
                delete node;
                return r;
            } else if (!node->right) {
                Node* l = node->left;
                delete node;
                return l;
            } else {
                Node* succ = node->right;
                while (succ->left) succ = succ->left;
                node->data = succ->data;
                node->right = deleteRec(node->right, succ->data);
            }
        }
        return node;
    }
public:
    int maxDepth() { return depthRec(root); }
    int minDepth() { return minDepthRec(root); }

private:
    int depthRec(Node* node) {
        if (!node) return 0;
        int l = depthRec(node->left);
        int r = depthRec(node->right);
        return 1 + max(l, r);
    }
    int minDepthRec(Node* node) {
        if (!node) return 0;
        if (!node->left) return 1 + minDepthRec(node->right);
        if (!node->right) return 1 + minDepthRec(node->left);
        return 1 + min(minDepthRec(node->left), minDepthRec(node->right));
    }
};
int main() {
    BST tree;
    int arr[] = {50,30,70,20,40,60,80};
    for (int x : arr) tree.insert(x);
    cout << "Max depth: " << tree.maxDepth() << "\n";
    cout << "Min depth: " << tree.minDepth() << "\n";
    cout << "Deleting 50 (root)...\n";
    tree.remove(50);
    cout << "New max depth: " << tree.maxDepth() << "\n";
    return 0;
}
