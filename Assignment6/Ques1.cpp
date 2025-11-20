#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};
class CircularList {
private:
    Node* head;

public:
    CircularList() { head = NULL; }
    void insertAtBeginning(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }
    void insertAtEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }
    void insertBefore(int key, int x) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(x);
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->next->data != key)
            temp = temp->next;
        if (temp->next == head) {
            cout << "Key not found.\n";
            return;
        }
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }
    void insertAfter(int key, int x) {
        if (head == NULL) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found.\n";
    }
    void deleteValue(int key) {
        if (head == NULL) return;
        if (head->data == key) {
            if (head->next == head) {   
                delete head;
                head = NULL;
                return;
            }
            Node* last = head;
            while (last->next != head)
                last = last->next;
            Node* del = head;
            head = head->next;
            last->next = head;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->next->data != key)
            temp = temp->next;
        if (temp->next == head) {
            cout << "Value not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void search(int key) {
        if (head == NULL) return;
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not found.\n";
    }
    void displayRepeatHead() {
        if (head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
    void display() {
        if (head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    int size() {
        if (head == NULL) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};
