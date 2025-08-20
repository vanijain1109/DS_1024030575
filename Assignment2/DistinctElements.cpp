#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int count = 1;  
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (j < i && arr[i] != arr[j]) {
            j++;
        }
        if (j == i) {
            count++;
        }
    }
    cout<<"Number of distinct elements : "<<count;
    return 0;
}