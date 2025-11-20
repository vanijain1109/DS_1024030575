#include <iostream>
using namespace std;
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
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }
    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;
        cout << endl;
    }
};
int main() {
    CircularLinkedList c;
    c.insert(20);
    c.insert(100);
    c.insert(40);
    c.insert(80);
    c.insert(60);
    c.display();
    return 0;
}
