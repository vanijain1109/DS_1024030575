#include <iostream>
#include <string>
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
     return s.top == -1; 
    }
int isFull(Stack &s) { 
    return s.top == MAX - 1; 
}
void push(Stack &s, int value) {
    if (!isFull(s)) {
        s.top++;
        s.arr[s.top] = value;
    }
}
int pop(Stack &s) {
    if (!isEmpty(s)) {
        int v = s.arr[s.top];
        s.top--;
        return v;
    }
    return 0;
}
int main() {
    Stack s;
    init(s);
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            push(s, ch - '0');
        }
        else {
            int val2 = pop(s);
            int val1 = pop(s);
            int result = 0;
            if (ch == '+') result = val1 + val2;
            else if (ch == '-') 
            result = val1 - val2;
            else if (ch == '*') 
            result = val1 * val2;
            else if (ch == '/') 
            result = val1 / val2;
            push(s, result);
        }
    }
    cout << "Evaluation result: " << pop(s) << endl;
    return 0;
}

