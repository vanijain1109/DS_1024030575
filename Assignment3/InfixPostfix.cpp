#include <iostream>
#include <string>
using namespace std;
#define MAX 100
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
char peek(Stack &s) {
    if (!isEmpty(s)) return s.arr[s.top];
    return '\0';
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
int main() {
    Stack s;
    init(s);
    string infix, postfix = "";
    cout << "Enter infix expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            push(s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix += pop(s);
            }
            pop(s); 
        }
        else { 
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) {
                postfix += pop(s);
            }
            push(s, ch);
        }
    }
    while (!isEmpty(s)) {
        postfix += pop(s);
    }
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
