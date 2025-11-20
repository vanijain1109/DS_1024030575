// q1_traversals.cpp
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};
class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = NULL; }
    Node* createNode(int v) { return new Node(v); }
    void preorder(Node* r) {
        if (!r) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void postorder(Node* r) {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
};
int main() {
    BinaryTree T;
    T.root = T.createNode(1);
    T.root->left = T.createNode(2);
    T.root->right = T.createNode(3);
    T.root->left->left = T.createNode(4);
    T.root->left->right = T.createNode(5);
    T.root->right->right = T.createNode(6);
    cout << "Preorder: ";
    T.preorder(T.root);
    cout << "\nInorder: ";
    T.inorder(T.root);
    cout << "\nPostorder: ";
    T.postorder(T.root);
    cout << endl;
    return 0;
}
