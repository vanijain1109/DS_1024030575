#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    for (int i = 0; i < (int)s.length(); i++) {        
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
            s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') {                        
            for (int j = i; j < (int)s.length(); j++) {
                s[j] = s[j + 1];
            }
            i--;  
        }
    }
    cout << "String after deleting vowels: " << s << endl;
    return 0;
}