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
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
int main() {
    LinkedList L;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);
    L.insertAtEnd(4);
    L.insertAtEnd(5);
    cout << "Middle Element: " << L.findMiddle();
}
