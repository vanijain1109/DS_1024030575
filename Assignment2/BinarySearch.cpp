#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int number) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (left + right) / 2;
        if (arr[mid] == number)
            return mid;
        else if (arr[mid] < number)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[50],n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int number;
    cout<<"Enter number to search : ";
    cin>>number;
    int index = binarySearch(arr, n, number);
    if (index != -1) {
        cout << "Found at index " << index;
    }
    else cout << "Not found";
    return 0;
}
