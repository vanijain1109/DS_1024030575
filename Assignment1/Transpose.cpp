#include <iostream>
using namespace std;
int main() {
    int matrix[10][10], transpose[10][10];
    int rows, col;
    cout << "Enter rows of the matrix: ";
    cin >> rows ;
    cout << "Enter columns of the matrix: ";
    cin >> col;
    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < col; ++j)
            cin >> matrix[i][j];
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < col; ++j){
            transpose[j][i] = matrix[i][j];
        }
    }
    cout << "Transpose :\n";
    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < rows; ++j)
            cout << transpose[i][j] << " ";
        cout << endl;
    }
    return 0;
}