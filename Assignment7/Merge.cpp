#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[50], right[50];

    for (int i = 0; i < n1; i++) left[i] = a[l + i];
    for (int i = 0; i < n2; i++) right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = l;

    // merge back
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }

    // remaining
    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

int main() {
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
