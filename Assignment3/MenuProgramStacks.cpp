#include <iostream>
using namespace std;
#define MAX 10
struct Stack {
    int arr[MAX];
    int top;
};
void init(Stack &s) {
    s.top = -1;
}
int isEmpty(Stack &s) {
    if (s.top == -1) return 1;
    else return 0;
}
int isFull(Stack &s) {
    if (s.top == MAX - 1) return 1;
    else return 0;
}
void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow!\n";
    } else {
        s.top++;
        s.arr[s.top] = value;
        cout << value << " pushed.\n";
    }
}
void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!\n";
    } else {
        cout << s.arr[s.top] << " popped.\n";
        s.top--;
    }
}
void peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack empty.\n";
    } else {
        cout << "Top = " << s.arr[s.top] << endl;
    }
}
void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack empty.\n";
    } else {
        cout << "Stack: ";
        for (int i = s.top; i >= 0; i--) {
            cout << s.arr[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    Stack s;
    init(s);
    int choice, value;
    do {
        cout << "\n1.Push\n2.Pop\n3.Empty\n4.Full\n5.Display\n6.Peek\n7.Exit\n";
        cout<<"Enter choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert : ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                if (isEmpty(s)) 
                cout << "The stack is empty\n";
                else cout << "The stack is not empty\n";
                break;
            case 4:
                if (isFull(s)) 
                cout << "Yes the stack is full\n";
                else cout << "No the stack is not full \n";
                break;
            case 5:
                cout<<"Entered stack : ";
                display(s);
                break;
            case 6:
                peek(s);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
