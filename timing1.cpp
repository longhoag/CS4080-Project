#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

#define MAX 100

void inputMatrix(float mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

void multiplyMatrices(float mat1[MAX][MAX], float mat2[MAX][MAX], float res[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(float matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            // use nested loop to print out each element of the matrix
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int size = 10;
    float mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];

    for(size; size <= 100; size += 5) {
        inputMatrix(mat1, size, size);
        inputMatrix(mat2, size, size);

        auto start = high_resolution_clock::now();
        //displayMatrix(mat1, size, size);
        multiplyMatrices(mat1, mat2, res, size, size, size, size);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}