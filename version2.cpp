//Name: Long Hoang 

#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono; // for the calculate time data for the test run

// dynamically allocate a matrix
float** allocateMatrix(int rows, int cols) {
    float** matrix = new float*[rows]; //allocate row dimension
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float[cols]; //allocate column dimension
    }
    return matrix;
}

// deallocate a matrix
void deallocateMatrix(float** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; // deallocate memory for each row
    }
    delete[] matrix; // deallocate memory for row pointers
}

// add two matrices
float** matrixAddition(float** A, float** B, int rows, int cols) {
    //allocate memory for result matrix
    float** C = allocateMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // addition calculation
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// subtract two matrices
float** matrixSubtraction(float** A, float** B, int rows, int cols) {
    //allocate memory for result matrix
    float** C = allocateMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // substraction calculation
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// multiply two matrices
float** matrixMultiplication(float** A, float** B, int rowsA, int colsA, int colsB) {
    // allocate memory for result matrix
    float** C = allocateMatrix(rowsA, colsB);

    //  multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0; // initialize element to 0
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j]; // sum the products resulting element of new matrix
            }
        }
    }
    return C;
}

// display a matrix
void displayMatrix(float** matrix, int rows, int cols) {
    // loop through each element and print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// random matrix elements for test simulation
void randomMatrix(float** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = static_cast<float>(rand()) / RAND_MAX; // generate random value for element in the matrix between 0 and 1
        }
    }
}

int main() {

    // initialize properties of matrix A and B
    int rowsA, colsA, rowsB, colsB;

    // input the size of Matrix A
    cout << "Enter number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;

    // input Matrix A via allocation
    float** A = allocateMatrix(rowsA, colsA);
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    // input the size of Matrix B
    cout << "Enter number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    // input Matrix B
    float** B = allocateMatrix(rowsB, colsB);
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    // initialize Matrix C for result
    float** C;

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
                    //  addition
                    C = matrixAddition(A, B, rowsA, colsA);
                    // display result
                    cout << "Result of Addition:" << endl;
                    displayMatrix(C, rowsA, colsA);
                    // free memory
                    deallocateMatrix(C, rowsA);
                }
                break;
            case 2:
                // check if subtraction is valid
                if (rowsA != rowsB || colsA != colsB) {
                    cout << "Matrices A and B must have the same dimensions for subtraction." << endl;
                } else {
                    //  subtraction
                    C = matrixSubtraction(A, B, rowsA, colsA);
                    // display result
                    cout << "Result of Subtraction:" << endl;
                    displayMatrix(C, rowsA, colsA);
                    // deallocate
                    deallocateMatrix(C, rowsA);
                }
                break;
            case 3:
                // check if multiplication is valid
                if (colsA != rowsB) {
                    cout << "Matrix A must have the same number of columns as rows of Matrix B for multiplication." << endl;
                } else {
                    //  multiplication
                    C = matrixMultiplication(A, B, rowsA, colsA, colsB);
                    // display result
                    cout << "Result of Multiplication:" << endl;
                    displayMatrix(C, rowsA, colsB);
                    // deallocate 
                    deallocateMatrix(C, rowsA);
                }
                break;
            case 4:
                // freeing memory of the  existing matrices before creating new ones
                deallocateMatrix(A, rowsA);
                deallocateMatrix(B, rowsB);
                // allow user to enter new matrices
                cout << "Enter number of rows and columns for Matrix A: ";
                cin >> rowsA >> colsA;
                A = allocateMatrix(rowsA, colsA);

                cout << "Enter elements of Matrix A:" << endl;
                for (int i = 0; i < rowsA; ++i) {
                    for (int j = 0; j < colsA; ++j) {
                        cin >> A[i][j];
                    }
                }

                cout << "Enter number of rows and columns for Matrix B: ";
                cin >> rowsB >> colsB;
                B = allocateMatrix(rowsB, colsB);

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
                    
                    

                    for(size; size <= 100; size += 5) { // test size: 10, 15, 20, ...
                        
                        float** mat1 = allocateMatrix(size, size);
                        float** mat2 = allocateMatrix(size, size);

                        randomMatrix(mat1, size, size);
                        randomMatrix(mat2, size, size);

                        // start mark for counting
                        auto start = high_resolution_clock::now();

                        float** res = matrixMultiplication(mat1, mat2, size, size, size);

                        // end mark
                        auto stop = high_resolution_clock::now();

                        // duration = end - start
                        auto duration = duration_cast<microseconds>(stop - start);
                        cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;

                        // freeing memory 
                        deallocateMatrix(res, size);
                        deallocateMatrix(mat1, size);
                        deallocateMatrix(mat2, size);
                        
                    }
                    break;
                }
            default:
                // handle invalid case
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

    } while (choice != 5);

    // deallocate matrices before exiting
    deallocateMatrix(A, rowsA);
    deallocateMatrix(B, rowsB);
    // we have deallocated matrix C before







    // srand(time(0)); // random generator
    // int size = 10; // square matrix is fine (as noted in the assignment prompt)
    
    

    // for(size; size <= 100; size += 5) { // test size: 10, 15, 20, ...
        
    //     float** mat1 = allocateMatrix(size, size);
    //     float** mat2 = allocateMatrix(size, size);

    //     randomMatrix(mat1, size, size);
    //     randomMatrix(mat2, size, size);

    //     // start mark for counting
    //     auto start = high_resolution_clock::now();

    //     float** res = matrixMultiplication(mat1, mat2, size, size, size);

    //     // end mark
    //     auto stop = high_resolution_clock::now();

    //     // duration = end - start
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;

    //     // freeing memory 
    //     deallocateMatrix(res, size);
    //     deallocateMatrix(mat1, size);
    //     deallocateMatrix(mat2, size);
    // }

    return 0;
}