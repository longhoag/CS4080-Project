#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void inputMatrix(float** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

float** multiplyMatrices(float** mat1, float** mat2, int r1, int c1, int r2, int c2) {
    float** res = new float*[r1];
    for (int i = 0; i < r1; i++) {
        res[i] = new float[c2];
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

int main() {
    srand(time(0));
    int size = 100;
    float** mat1 = new float*[size];
    float** mat2 = new float*[size];

    for (int i = 0; i < size; i++) {
        mat1[i] = new float[size];
        mat2[i] = new float[size];
    }

    inputMatrix(mat1, size, size);
    inputMatrix(mat2, size, size);

    auto start = high_resolution_clock::now();
    float** res = multiplyMatrices(mat1, mat2, size, size, size, size);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    for (int i = 0; i < size; i++) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] res[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] res;

    return 0;
}