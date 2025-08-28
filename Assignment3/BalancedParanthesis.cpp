#include <iostream>
#include <string>
using namespace std;
#define MAX 10
struct Stack {
    char arr[MAX];
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
void push(Stack &s, char c) {
    if (!isFull(s)) {
        s.top++;
        s.arr[s.top] = c;
    }
}
char pop(Stack &s) {
    if (!isEmpty(s)) {
        char c = s.arr[s.top];
        s.top--;
        return c;
    }
    return '\0';
}
int Match(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}
int main() {
    Stack s;
    init(s);
    string a;
    cout << "Enter expression: ";
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        char ch = a[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(s)) {
                cout << "Not Balanced\n";
                return 0;
            }
            char top = pop(s);
            if (!Match(top, ch)) {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }
    if (isEmpty(s))
    cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
