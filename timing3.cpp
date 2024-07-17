#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

class Matrix {
private:
    float** data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = static_cast<float>(rand()) / RAND_MAX;
            }
        }
    }

    Matrix operator*(const Matrix& B) const {
        if (cols != B.rows) throw "Dimensions mismatch for multiplication";
        Matrix C(rows, B.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                C.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    C.data[i][j] += data[i][k] * B.data[k][j];
                }
            }
        }
        return C;
    }
};

int main() {
    srand(time(0));
    int size = 10;
    for(size; size <= 100; size += 5) {
        Matrix A(size, size);
        Matrix B(size, size);

        A.input();
        B.input();

        auto start = high_resolution_clock::now();
        Matrix C = A * B;
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;

    }

    return 0;
}