#include<iostream>
using namespace std;
void create(int arr[],int &n){
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
}
void display(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElem(int arr[], int &n) {
    int x, pos;
    cout << "Element to insert: "; 
    cin >> x;
    cout << "Enter position to insert element :  "; 
    cin >> pos;
    if (pos >= 0 && pos <= n) {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = x;
        n++;
    } else {
        cout << "Invalid position\n";
        return;
    }
    cout << "New array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void deleteElem(int arr[], int &n) {
    int pos;
    cout << "Position to delete: "; cin >> pos;

    if (pos >= 0 && pos < n) {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } else {
        cout << "Invalid position\n";
        return;
    }

    // Display result
    cout << "New array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void linearSearch(int arr[], int n) {
    int x, idx = -1;
    cout << "Element to search: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) { 
            idx = i;
            break;  // Exit loop once found
        }
    }
    if (idx == -1)
        cout << "Not found\n";
    else
        cout << "Found at index " << idx << endl;
}
int main() {
    int arr[50], n = 0, choice;
    do {
        cout << "\n--- MENU ---\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Search\n6.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(arr, n); break;
            case 2: display(arr, n); break;
            case 3: insertElem(arr, n); break;
            case 4: deleteElem(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid\n";
        }
    } while (choice != 6);
    return 0;
}