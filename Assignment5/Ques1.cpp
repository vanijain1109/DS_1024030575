#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = NULL; }
    void insertAtBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }
    void insertAtEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }
    void insertBefore(int key, int x) {
        if (head == NULL)
            return;
        if (head->data == key) {
            insertAtBeginning(x);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "Key not found.\n";
            return;
        }
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }
    void insertAfter(int key, int x) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Key not found.\n";
            return;
        }
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }
    void deleteBeginning() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteEnd() {
        if (head == NULL)
            return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void deleteValue(int key) {
        if (head == NULL)
            return;
        if (head->data == key) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "Value not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position: " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Not found.\n";
    }
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int ch, x, key;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Key\n4. Insert After Key\n";
        cout << "5. Delete Beginning\n6. Delete End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n10. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cin >> x;
            list.insertAtBeginning(x);
            break;
        case 2:
            cin >> x;
            list.insertAtEnd(x);
            break;
        case 3:
            cin >> key >> x;
            list.insertBefore(key, x);
            break;
        case 4:
            cin >> key >> x;
            list.insertAfter(key, x);
            break;
        case 5:
            list.deleteBeginning(); 
            break;
        case 6:
            list.deleteEnd(); 
            break;
        case 7:
            cin >> key;
            list.deleteValue(key);
            break;
        case 8:
            cin >> key;
            list.search(key);
            break;
        case 9:
            list.display();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
