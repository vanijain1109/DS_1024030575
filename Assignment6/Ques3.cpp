#include <iostream>
using namespace std;
class DoublyLinkedList {
public:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int d) { data = d; prev = next = NULL; }
    };
    Node* head;
    DoublyLinkedList() { head = NULL; }
    void insert(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }

        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
    int size() {
        int count = 0;
        Node* t = head;
        while (t) {
            count++;
            t = t->next;
        }
        return count;
    }
};
class CircularLinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        Node(int d) { data = d; next = NULL; }
    };
    Node* head;
    CircularLinkedList() { head = NULL; }
    void insert(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
    int size() {
        if (!head) return 0;
        int count = 0;
        Node* t = head;
        do {
            count++;
            t = t->next;
        } while (t != head);

        return count;
    }
};
int main() {
    DoublyLinkedList d;
    CircularLinkedList c;
    d.insert(10); d.insert(20); d.insert(30);
    c.insert(5); c.insert(15); c.insert(25); c.insert(35);
    cout << "Size of Doubly Linked List = " << d.size() << endl;
    cout << "Size of Circular Linked List = " << c.size() << endl;
    return 0;
}
