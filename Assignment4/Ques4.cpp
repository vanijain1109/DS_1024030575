#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> q;
    int freq[26] = {0};
    char ch;

    while (cin >> ch) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
}
