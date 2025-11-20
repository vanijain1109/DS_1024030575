#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};
class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }
    void insertAtEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void display() {
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList L;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);
    L.insertAtEnd(4);
    cout << "Original: ";
    L.display();
    L.reverse();
    cout << "Reversed: ";
    L.display();
}
