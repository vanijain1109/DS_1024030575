#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Sorted array : ";
    for (int i = 0; i < n ; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int idx = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }

    cout << "Array after removing duplicate elements:\n";
    for (int i = 0; i < idx; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}