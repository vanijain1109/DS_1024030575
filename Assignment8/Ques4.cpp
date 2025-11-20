#include <iostream>
#include <limits>
using namespace std;
class Node {
public:
    int data;
    Node* left; Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};
bool isBSTUtil(Node* node, long minv, long maxv) {
    if (!node) return true;
    if (node->data <= minv || node->data >= maxv) return false;
    return isBSTUtil(node->left, minv, node->data) && isBSTUtil(node->right, node->data, maxv);
}
bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    cout << (isBST(root) ? "Is BST\n" : "Not BST\n");
    root->right->left = new Node(9); 
    cout << (isBST(root) ? "Is BST\n" : "Not BST\n");
    return 0;
}
