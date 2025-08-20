#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int missing = -1;
    for(int i = 0; i < n-1; i++) {
        if(arr[i+1] != arr[i] + 1) {
            missing = arr[i] + 1;
            break;
        }
    }
    if(missing != -1)
        cout << "Missing number is: " << missing << endl;
    else
        cout << "No number is missing" << endl;

    return 0;
}