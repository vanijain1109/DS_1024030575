#include <iostream>
using namespace std;
class DoublyLinkedList {
public:
    class Node {
    public:
        char data;
        Node* prev;
        Node* next;
        Node(char d) { data = d; prev = next = NULL; }
    };
    Node* head;
    DoublyLinkedList() { head = NULL; }
    void insert(char ch) {
        Node* n = new Node(ch);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = head;
        while (right->next) 
            right = right->next;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};
int main() {
    DoublyLinkedList d;
    d.insert('l');
    d.insert('e');
    d.insert('v');
    d.insert('e');
    d.insert('l');
    if (d.isPalindrome())
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
    return 0;
}
