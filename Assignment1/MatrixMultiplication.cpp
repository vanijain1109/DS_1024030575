#include<iostream>
using namespace std;
void multiplyMatrices() { 
    int r1, r2, c1, c2; 
    cout << "Enter rows of matrix 1 : "; 
    cin >> r1; 
    cout << "Enter columns of matrix 1 : "; 
    cin >> c1; 
    cout << "Enter rows of matrix 2 : "; 
    cin >> r2; 
    cout << "Enter columns of matrix 2 : "; 
    cin >> c2;  
    if (c1 != r2) {
         cout << "Matrix multiplication not possible" << endl;
    }

int A[10][10], B[10][10], C[10][10] = {0}; 
cout << "Enter elements of matrix 1:\n"; 
for (int i = 0; i < r1; i++){
    for (int j = 0; j < c1; j++){
        cin >> A[i][j];
    }
}

cout << "Enter elements of matrix 2 :\n"; 
for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
        cin >> B[i][j];
    }
}

 for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

cout << "Result of matrix multiplication:\n";
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }  
}
int main(){
    multiplyMatrices();
    return 0;
}