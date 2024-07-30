#include <iostream>

using namespace std;

int N = 3; // Dimension of the matrix

// Function to multiply two matrices
void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to calculate the determinant of a matrix
int determinant(int mat[3][3], int n) {
    int det = 0;
    if (n == 1) {
        return mat[0][0];
    }

    int temp[3][3]; // To store cofactors
    int sign = 1; // To store sign multiplier

    for (int f = 0; f < n; ++f) {
        // Getting Cofactor of mat[0][f]
        int subi = 0; // Submatrix's row index
        for (int i = 1; i < n; ++i) {
            int subj = 0; // Submatrix's column index
            for (int j = 0; j < n; ++j) {
                if (j == f) {
                    continue;
                }
                temp[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

int main() {
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[3][3]; // To store the result of multiplication

    multiplyMatrices(mat1, mat2, result);

    cout << "Result of Matrix Multiplication:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    int det = determinant(mat1, N);

    cout << "Determinant of the first matrix is: " << det << endl;

    return 0;
}
