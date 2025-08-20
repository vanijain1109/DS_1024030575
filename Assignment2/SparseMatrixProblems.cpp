#include <iostream>
using namespace std;
#define MAX 100
void readSparse(int mat[MAX][3]){
    int r , c , x;
    cout << "Enter rows : ";
    cin >> r ;
    cout << "Enter columns : ";
    cin >> c;
    cout << "Enter non-zero elements  : ";
    cin >> x;
    mat[0][0] = r;
    mat[0][1] = c;
    mat[0][2] = x;
    cout << "Enter row - column value for " << x << " non-zero elements:\n";
    for (int i = 1; i <= x; i++)
    {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}
void display(int mat[MAX][3]){
    int t = mat[0][2];
    cout << "\nRow Column Value\n";
    for (int i = 0; i <= t; i++)
    {
        cout << mat[i][0] << "   " << mat[i][1] << "   " << mat[i][2] << "\n";
    }
}
void transpose(int a[MAX][3], int b[MAX][3]){
    int x = a[0][2];
    b[0][0] = a[0][1]; 
    b[0][1] = a[0][0]; 
    b[0][2] = x;

    for (int i = 1; i <= x; i++)
    {
        b[i][0] = a[i][1];
        b[i][1] = a[i][0];
        b[i][2] = a[i][2];
    }
}
void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]){
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]){
        cout <<"Addition not possible\n";
        return;
    }
    int x1 = a[0][2], x2 = b[0][2];
    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i <= x1 && j <= x2){
        if (a[i][0] < b[j][0] ||
            (a[i][0] == b[j][0] && a[i][1] < b[j][1])){
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;
        }
        else if (b[j][0] < a[i][0] ||
                 (b[j][0] == a[i][0] && b[j][1] < a[i][1])){
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
        else{
            int sum = a[i][2] + b[j][2];
            if (sum != 0){
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i <= x1)
        c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2], i++, k++;
    while (j <= x2)
        c[k][0] = b[j][0], c[k][1] = b[j][1], c[k][2] = b[j][2], j++, k++;

    c[0][2] = k - 1;
}
void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]){
    if (a[0][1] != b[0][0]){
        cout << "Multiplication not possible\n";
        return;
    }
    int m = a[0][0], n = a[0][1], p = b[0][1];
    c[0][0] = m;
    c[0][1] = p;
    int k = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            int sum = 0;
            for (int x = 1; x <= a[0][2]; x++){
                if (a[x][0] == i){
                    for (int y = 1; y <= b[0][2]; y++){
                        if (b[y][0] == a[x][1] && b[y][1] == j){
                            sum += a[x][2] * b[y][2];
                        }
                    }
                }
            }
            if (sum != 0){
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}
int main(){
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int choice;
    cout << "Enter first sparse matrix:\n";
    readSparse(A);
    cout << "\nChoose operation:\n1. Transpose\n2. Addition\n3. Multiplication\n";
    cin >> choice;
    if (choice == 1){
        transpose(A, C);
        cout << "\nTranspose:\n";
        display(C);
    }
    else if (choice == 2){
        cout << "Enter second sparse matrix:\n";
        readSparse(B);
        addSparse(A, B, C);
        cout << "\nAddition result:\n";
        display(C);
    }
    else if (choice == 3){
        cout << "Enter second sparse matrix:\n";
        readSparse(B);
        multiplySparse(A, B, C);
        cout << "\nMultiplication result:\n";
        display(C);
    }
    else{
        cout << "Invalid choice\n";
    }

    return 0;
}