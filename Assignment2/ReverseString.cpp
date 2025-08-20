#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int start = 0;
    int end = s.length() - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    cout << "Reversed string: " << s << endl;
    return 0;
}