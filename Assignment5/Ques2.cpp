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
    void insert(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }
    int deleteAll(int key) {
        int count = 0;
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        if (head == NULL)
            return count;
        Node* curr = head;
        while (curr->next != NULL) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }
    void display() {
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList L;
    int arr[] = {1,2,1,2,1,3,1};
    for (int i = 6; i >= 0; i--)
        L.insert(arr[i]);
    cout << "Original List: ";
    L.display();
    int key = 1;
    int count = L.deleteAll(key);
    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    L.display();
}
