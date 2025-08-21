#include <iostream>
using namespace std;

#define MAX 100

// Take sparse matrix input
void inputSparse(int mat[MAX][3]) {
    int rows, cols, nz;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter total non-zero elements: ";
    cin >> nz;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nz;

    cout << "Enter each non-zero element as (row col value):\n";
    for (int idx = 1; idx <= nz; idx++) {
        cin >> mat[idx][0] >> mat[idx][1] >> mat[idx][2];
    }
}

// Display sparse matrix in triplet form
void printSparse(int mat[MAX][3]) {
    int nz = mat[0][2];
    cout << "\n(row, col, value) format:\n";
    for (int i = 0; i <= nz; i++) {
        cout << mat[i][0] << "   " << mat[i][1] << "   " << mat[i][2] << "\n";
    }
}

// Transpose of sparse matrix
void transposeSparse(int a[MAX][3], int b[MAX][3]) {
    int nz = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = nz;

    for (int i = 1; i <= nz; i++) {
        b[i][0] = a[i][1];
        b[i][1] = a[i][0];
        b[i][2] = a[i][2];
    }
}

// Addition of two sparse matrices
void sumSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrix dimensions mismatch! Cannot add.\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int nz1 = a[0][2], nz2 = b[0][2];

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= nz1 && j <= nz2) {
        if (a[i][0] < b[j][0] || 
           (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        } 
        else if (b[j][0] < a[i][0] || 
                (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        } 
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= nz1) {
        c[k][0] = a[i][0]; 
        c[k][1] = a[i][1]; 
        c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= nz2) {
        c[k][0] = b[j][0]; 
        c[k][1] = b[j][1]; 
        c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][2] = k - 1;
}

// Multiplication of two sparse matrices
void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Matrix multiplication not possible (dimension mismatch).\n";
        return;
    }

    int rows = a[0][0], cols = b[0][1];
    c[0][0] = rows;
    c[0][1] = cols;
    int k = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0][2]; x++) {
                if (a[x][0] == i) {
                    for (int y = 1; y <= b[0][2]; y++) {
                        if (b[y][0] == a[x][1] && b[y][1] == j) {
                            sum += a[x][2] * b[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

// Main function
int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int choice;

    cout << "Enter first sparse matrix:\n";
    inputSparse(A);

    cout << "\nChoose an operation:\n";
    cout << "1. Transpose\n";
    cout << "2. Addition\n";
    cout << "3. Multiplication\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        transposeSparse(A, C);
        cout << "\nTranspose result:\n";
        printSparse(C);
    } 
    else if (choice == 2) {
        cout << "Enter second sparse matrix:\n";
        inputSparse(B);
        sumSparse(A, B, C);
        cout << "\nAddition result:\n";
        printSparse(C);
    } 
    else if (choice == 3) {
        cout << "Enter second sparse matrix:\n";
        inputSparse(B);
        multiplySparse(A, B, C);
        cout << "\nMultiplication result:\n";
        printSparse(C);
    } 
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
