#include <queue>
#include <iostream>
using namespace std;
void interleave(queue<int> &q) {
    int n = q.size();
    queue<int> first;
    for (int i = 0; i < n / 2; i++) {
        first.push(q.front());
        q.pop();
    }
    while (!first.empty()) {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue<int> q;
    int x;
    cout << "Enter 6 values: ";
    for (int i = 0; i < 6; i++) {
        cin >> x;
        q.push(x);
    }
    interleave(q);
    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
