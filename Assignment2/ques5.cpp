#include <iostream>
using namespace std;
void DiagonalMatrix(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << arr[i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
void LowerMatrix(int arr[], int n){
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i >= j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
void UpperMatrix(int arr[], int n){
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i <= j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
void SymmetricMatrix(int arr[], int n){
    int k = 0;
    int *mat = new int[n * n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            mat[i * n + j] = arr[k++];
            mat[j * n + i] = mat[i * n + j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i * n + j] << " ";
        }
        cout << "\n";
    }
    delete[] mat;
}
void TriDiagonalMatrix(int arr[], int n){
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j || i == j + 1 || i + 1 == j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
int main(){
    int choice, n;
    cout << "Enter size of matrix : ";
    cin >> n;
    cout <<endl<<"Choose storage method : "<<endl;
    cout << "1. Diagonal Matrix"<<endl;
    cout << "2. Lower Triangular Matrix"<<endl;
    cout << "3. Upper Triangular Matrix"<<endl;
    cout << "4. Symmetric Matrix"<<endl;
    cout << "5. Tri-diagonal Matrix"<<endl;
    cout << "Enter choice: ";
    cin >> choice;
    int size = 0;
    switch(choice){
    case 1:
        size = n;
        break;
    case 2:
        size = 3 * n - 2;
        break;
    case 3:
        size = n * (n + 1) / 2;
        break;
    case 4:
        size = n * (n + 1) / 2;
        break;
    case 5:
        size = n * (n + 1) / 2;
        break;
    default:
        cout << "Invalid choice"<<endl;
        return 0;
    }
    int *arr = new int[size];
    cout << "Enter " << size << " elements (row-major order of the compact storage):\n";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "\nMatrix:\n";
    switch (choice){
    case 1:
        DiagonalMatrix(arr, n);
        break;
    case 2:
        LowerMatrix(arr, n);
        break;
       
    case 3:
        UpperMatrix(arr, n);
        break;
    case 4:
        SymmetricMatrix(arr, n);
        break;
        
    case 5:
        TriDiagonalMatrix(arr, n);
        break;
        
    }
    delete[] arr;
    return 0;
}