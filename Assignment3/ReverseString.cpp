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
    if (s.top == -1) 
    return 1;
    else return 0;
}
int isFull(Stack &s) {
    if (s.top == MAX - 1) return 1;
    else return 0;
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
int main() {
    Stack s;
    init(s);
    string str;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        push(s, str[i]);
    }
    cout << "Reversed string: ";
    while (!isEmpty(s)) {
        cout << pop(s);
    }
    cout << endl;
    return 0;
}
