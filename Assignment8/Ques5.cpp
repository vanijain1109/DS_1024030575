#include <iostream>
using namespace std;
void swapInt(int &a, int &b) { int t=a; a=b; b=t; }
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swapInt(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swapInt(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void heapSortIncreasing(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) {
        swapInt(arr[0], arr[i]); 
        maxHeapify(arr, i, 0);   
    }
}
void heapSortDecreasing(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) minHeapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) {
        swapInt(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}
int main() {
    int arr1[] = {5,2,8,12,3,7};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int a1[10]; for (int i=0;i<n;i++) a1[i]=arr1[i];
    heapSortIncreasing(a1, n);
    cout << "Sorted ascending: ";
    for (int i=0;i<n;i++) cout << a1[i] << " ";
    cout << "\n";

    int a2[10]; for (int i=0;i<n;i++) a2[i]=arr1[i];
    heapSortDecreasing(a2, n);
    cout << "Sorted descending: ";
    for (int i=0;i<n;i++) cout << a2[i] << " ";
    cout << "\n";

    return 0;
}
