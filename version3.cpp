// Name: Long Hoang
// private data in a matrix class

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <stdexcept>  // for std::invalid_argument
using namespace std::chrono; // for the calculate time data for the test run

using namespace std;

class Matrix {

private: // private data
    float** data;  // pointer to pointer for dynamic allocation
    int rows;      // number of rows
    int cols;      // number of columns

public: // public data

    // constructor to initialize matrix with given dimensions: row and col
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        data = new float*[rows]; // allocate memory for rows
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols]; // allocate memory for columns in the row
        }
    }

    // copy constructor
    Matrix(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;

        data = new float*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = m.data[i][j];
            }
        }
    }

    // destructor to deallocate memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i]; // deallocate memory for rows
        }
        delete[] data; // deallocate memory for row pointers
    }

    // input matrix elements from the user
    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];  // read input each element
            }
        }
    }

    void random() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = static_cast<float>(rand()) / RAND_MAX; // generate random value for element in the matrix between 0 and 1
            }
        }
    }

    // display matrix elements
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";  // print each element
            }
            cout << endl; 
        }
    }

    // overloaded + operator for matrix addition
    Matrix operator+(const Matrix& B) const {
        if (rows != B.rows || cols != B.cols) {
            throw invalid_argument("Matrices must have the same dimensions for addition.");  // check if dimensions match for addition
        }

        Matrix C(rows, cols);  // create a result matrix with the same dimensions using the constructor

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                C.data[i][j] = data[i][j] + B.data[i][j];  // add elements: addition
            }
        }
        return C; 
    }

    // overloaded - operator for matrix subtraction
    Matrix operator-(const Matrix& B) const {
        if (rows != B.rows || cols != B.cols) {
            throw invalid_argument("Matrices must have the same dimensions for subtraction.");  // Check if dimensions match for substraction
        }

        Matrix C(rows, cols);  // create a result matrix with the same dimensions using constructor
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                C.data[i][j] = data[i][j] - B.data[i][j];  // subtract elements
            }
        }
        return C;
    }

    // overloaded * operator for matrix multiplication
    Matrix operator*(const Matrix& B) const {
        if (cols != B.rows) {
            throw invalid_argument("Number of columns of A must be equal to number of rows of B for multiplication.");  // Check if dimensions are for multiplication
        }

        Matrix C(rows, B.cols);  // create a result matrix with the resulting dimensions

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < B.cols; ++j) {
                C.data[i][j] = 0;  // initialize element to 0

                for (int k = 0; k < cols; ++k) {
                    C.data[i][j] += data[i][k] * B.data[k][j];  // multiply and sum the products
                }
            }
        }
        return C;
    }

    // overloaded = operator for matrix calculation: like C = A + B (deep copy)
    Matrix& operator=(const Matrix& m) {
        if (this == &m) return *this; //  self-assignment

        // free existing memory
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // copy new resource
        rows = m.rows;
        cols = m.cols;

        data = new float*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = m.data[i][j];
            }
        }
        return *this;
    }

    // get the number of rows
    int getRows() const {
        return rows;
    }

    // get the number of columns
    int getCols() const {
        return cols;
    }
};

int main() {

    // initialize properties of matrix A and B
    int rowsA, colsA, rowsB, colsB;

    // input the size of matrix A
    cout << "Enter number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;

    // create and input matrix A
    Matrix A(rowsA, colsA);  // construct matrix A
    A.input();  // input the elements of matrix A

    // input the size of matrix B
    cout << "Enter number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    // create and input matrix B
    Matrix B(rowsB, colsB);  // construct matrix B
    B.input();  // input elements of matrix B

    // initialize the result matrix C 
    Matrix C(1, 1);  // temp for initialization

    // menu for matrix operations
    int choice;

    // loop over menu 
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

        try { // try catch exception
            switch (choice) {
                case 1:
                    // check valid requirement for operation
                    if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) { 
                        cout << "Addition not possible. Matrices must have the same dimensions." << endl;
                    } else {
                        // addition (using overloaded operator)
                        C = A + B;

                        cout << "Result of Addition:" << endl;
                        C.display();  // display the result
                    }
                    break;
                case 2:
                    // check valid requirement for operation
                    if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) {
                        cout << "Subtraction not possible. Matrices must have the same dimensions." << endl;
                    } else {
                        // subtraction (using overloaded operator)
                        C = A - B;

                        cout << "Result of Subtraction:" << endl;
                        C.display();  // display the result
                    }
                    break;

                case 3:
                    // check valid requirement for operation
                    if (A.getCols() != B.getRows()) {
                        cout << "Multiplication not possible. Number of columns of A must be equal to number of rows of B." << endl;
                    } else {
                        // multiplication (using overloaded operator)
                        C = A * B;

                        cout << "Result of Multiplication:" << endl;
                        C.display();  //display the result
                    }
                    break;
                case 4:
                    // prompt user to enter new matrices
                    cout << "Enter number of rows and columns for Matrix A: ";
                    cin >> rowsA >> colsA;

                    A = Matrix(rowsA, colsA);  // construct matrix A with new dimensions
                    A.input();  // input new elements for matrix A

                    cout << "Enter number of rows and columns for Matrix B: ";
                    cin >> rowsB >> colsB;
                    
                    B = Matrix(rowsB, colsB);  // construct matrix B with new dimensions
                    B.input();  // input new elements for matrix B
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
                            
                            Matrix mat1(size, size);
                            Matrix mat2(size, size);

                            mat1.random();
                            mat2.random(); 

                            // start mark for counting
                            auto start = high_resolution_clock::now();

                            Matrix res = mat1 * mat2;

                            // end mark
                            auto stop = high_resolution_clock::now();

                            // duration = end - start
                            auto duration = duration_cast<microseconds>(stop - start);
                            cout << "Size: " << size << " Time taken: " << duration.count() << " microseconds" << endl;
                        }
                    }
                    break;

                default:
                    // handle invalid case
                    cout << "Invalid choice. Please enter a valid option." << endl;
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;  // print exception message
        }

    } while (choice != 5);  // loop menu until user chooses to exit

    return 0;
}