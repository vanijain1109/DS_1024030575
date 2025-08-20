#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings : ";
    cin >> n;
    cin.ignore(); 
    const int MAX = 100;
    string arr[MAX];
    cout << "Enter each string on a new line: "<<endl;
    for (int i = 0; i < n; i++) {
        getline(cin,arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minidx]) {
                minidx = j;
            }
        }
        if (minidx != i) {
            string temp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = temp;
        }
    }
    cout << "\nSorted Strings:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<endl;
    }
    return 0;
}