// Name: Long Hoang

#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono; // for the calculate time data for the test run

const int MAX_SIZE = 100;

// add two matrices
void matrixAddition(float A[][MAX_SIZE], float B[][MAX_SIZE], float C[][MAX_SIZE], int rows, int cols) {
    // loop through for addition: C is the resulting matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// subtract two matrices
void matrixSubtraction(float A[][MAX_SIZE], float B[][MAX_SIZE], float C[][MAX_SIZE], int rows, int cols) {
    // loop through for substraction: C is the resulting matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// multiply two matrices: mxn multiply nxt = mxt
void matrixMultiplication(float A[][MAX_SIZE], float B[][MAX_SIZE], float C[][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                // row x column; column of A must = row of B
                C[i][j] += A[i][k] * B[k][j]; // sum the products resulting element of new matrix
            }
        }
    }
}

// display a matrix
void displayMatrix(float matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            // use nested loop to print out each element of the matrix
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// random matrix elements
void randomMatrix(float mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = static_cast<float>(rand()) / RAND_MAX; // generate random value for element in the matrix between 0 and 1
        }
    }
}


int main() {

    // properties of matrix A and B
    int rowsA, colsA, rowsB, colsB;

    float A[MAX_SIZE][MAX_SIZE];
    float B[MAX_SIZE][MAX_SIZE];
    
    // ask user to input the size of matrices
    cout << "Enter number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;

    // check if matrix size exceeds maximum allowed size
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        cout << "Matrix size exceeds maximum allowed size of " << MAX_SIZE << "x" << MAX_SIZE << "." << endl;
        return 1;
    }

    // input Matrix A
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    // input size of Matrix B
    cout << "Enter number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    // check if matrix size exceeds maximum allowed size
    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        cout << "Matrix size exceeds maximum allowed size of " << MAX_SIZE << "x" << MAX_SIZE << "." << endl;
        return 1;
    }

    // input Matrix B
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    // initialize Matrix C for result
    float C[MAX_SIZE][MAX_SIZE];

    // menu for matrix operations
    int choice;

    do {
        cout << endl;
        cout << "Matrix Operations Menu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Enter new matrices" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Perform Test Simulation (Time versus Matrix Size)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // user enter number base on the mennu
        switch (choice) {
            case 1:
                // check if addition is valid
                if (rowsA != rowsB || colsA != colsB) {
                    cout << "Matrices A and B must have the same dimensions for addition." << endl;
                } else {
                    matrixAddition(A, B, C, rowsA, colsA);
                    cout << "Result of Addition:" << endl;
                    displayMatrix(C, rowsA, colsA);
                }
                break;
            case 2:
                // check if subtraction is valid
                if (rowsA != rowsB || colsA != colsB) {
                    cout << "Matrices A and B must have the same dimensions for subtraction." << endl;
                } else {
                    matrixSubtraction(A, B, C, rowsA, colsA);
                    cout << "Result of Subtraction:" << endl;
                    displayMatrix(C, rowsA, colsA);
                }
                break;
            case 3:
                // check if multiplication is valid
                if (colsA != rowsB) {
                    cout << "Matrix A must have the same number of columns as rows of Matrix B for multiplication." << endl;
                } else {
                    matrixMultiplication(A, B, C, rowsA, colsA, colsB);
                    cout << "Result of Multiplication:" << endl;
                    displayMatrix(C, rowsA, colsB);
                }
                break;
            case 4:
                // prompt user to enter new matrices
                cout << "Enter number of rows and columns for Matrix A: ";
                cin >> rowsA >> colsA;
                cout << "Enter elements of Matrix A:" << endl;
                for (int i = 0; i < rowsA; ++i) {
                    for (int j = 0; j < colsA; ++j) {
                        cin >> A[i][j];
                        // order of input from left to right, up to down, the values of elements are limited to the range of rowsA and colsA 
                    }
                }
                
                cout << "Enter number of rows and columns for Matrix B: ";
                cin >> rowsB >> colsB;
                cout << "Enter elements of Matrix B:" << endl;
                for (int i = 0; i < rowsB; ++i) {
                    for (int j = 0; j < colsB; ++j) {
                        cin >> B[i][j];
                    }
                }
                break;
            case 5:
                // exit the program
                cout << "Exiting..." << endl;
                break;
            case 6: 
                {
                    // perform test simulation to gather runtime data
                    srand(time(0)); // random generator
                    int size = 10; // square matrix is fine (as noted in the assignment prompt)

                    float mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];

                    for(size; size <= 100; size += 5) { // test size: 10, 15, 20, ...
                        randomMatrix(mat1, size, size);
                        randomMatrix(mat2, size, size);

                        // start mark for counting
                        auto start = high_resolution_clock::now();

                        matrixMultiplication(mat1, mat2, res, size, size, size);

                        // end mark
                        auto stop = high_resolution_clock::now();

                        // duration = end - start
                        auto duration = duration_cast<microseconds>(stop - start);
                        cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;
                    }
                    break;
                }
            default:
                // handle invalid case
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}