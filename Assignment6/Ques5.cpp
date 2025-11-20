#include <iostream>
using namespace std;
class LinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        Node(int d) { data = d; next = NULL; }
    };
    Node* head;
    LinkedList() { head = NULL; }
    void insert(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    bool isCircular() {
        if (!head) return true; 
        Node* t = head->next;
        while (t != NULL && t != head)
            t = t->next;
        return (t == head);
    }
};
int main() {
    LinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    if (l.isCircular())
        cout << "Circular Linked List\n";
    else
        cout << "Not Circular\n";

    return 0;
}
