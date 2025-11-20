#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
    void top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Stack1Q s;
    s.push(5);
    s.push(15);
    s.push(25);

    s.top();   
    s.pop();   
    s.top();   

    return 0;
}
