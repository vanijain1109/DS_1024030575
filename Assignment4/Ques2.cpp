#include <iostream>
using namespace std;
#define SIZE 10
class CQueue {
    int arr[SIZE];
    int front, rear;
public:
    CQueue() {
        front = rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        cout << x << " added.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return;
        }
        cout << arr[front] << " removed.\n";
        if (front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue empty!\n";
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};
int main() {
    CQueue cq;
    int ch, val;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cq.enqueue(val);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
