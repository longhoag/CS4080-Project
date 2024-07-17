import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.Random;

// matrix class to handle matrix operations
class Matrix {
    private float[][] data; // 2D array for  matrix 
    private int rows;       // number of rows 
    private int cols;       // number of columns 

    // constructor to initialize the matrix with given dimensions
    public Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new float[rows][cols];
    }

    // input matrix elements from the user
    public void input(Scanner scanner) {
        System.out.println("Enter elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = scanner.nextFloat(); // read each element
            }
        }
    }

    // randomize the element for the test simulation
    public void randomize(Random rand) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand.nextFloat();
            }
        }
    }

    // display matrix elements
    public void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(data[i][j] + " "); // print each element
            }
            System.out.println();
        }
    }

    // add two matrices
    public Matrix add(Matrix B) {
        // check if dimensions valid for addition
        if (rows != B.rows || cols != B.cols) {
            throw new IllegalArgumentException("Matrices must have the same dimensions for addition.");
        }

        Matrix C = new Matrix(rows, cols); // create a result matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                C.data[i][j] = data[i][j] + B.data[i][j]; // add  elements
            }
        }
        return C;
    }

    // subtract two matrices
    public Matrix subtract(Matrix B) {
        // check if dimensions valid for subtraction
        if (rows != B.rows || cols != B.cols) {
            throw new IllegalArgumentException("Matrices must have the same dimensions for subtraction.");
        }

        Matrix C = new Matrix(rows, cols); // create a result matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                C.data[i][j] = data[i][j] - B.data[i][j]; // subtract  elements
            }
        }
        return C; 
    }

    // multiply two matrices
    public Matrix multiply(Matrix B) {
        // Check if dimensions are valid for multiplication
        if (cols != B.rows) {
            throw new IllegalArgumentException("Number of columns of A must be equal to number of rows of B for multiplication.");
        }

        Matrix C = new Matrix(rows, B.cols); // create a result matrix

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                C.data[i][j] = 0; // initialize element to 0
                for (int k = 0; k < cols; k++) {
                    C.data[i][j] += data[i][k] * B.data[k][j]; // multiply and sum the products
                }
            }
        }
        return C;
    }

    // get the number of rows
    public int getRows() {
        return rows;
    }

    // get the number of columns
    public int getCols() {
        return cols;
    }

}

// Main class
public class MatrixOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // for getting input

        // input the size of matrix A
        System.out.print("Enter number of rows and columns for Matrix A: ");
        int rowsA = scanner.nextInt(); // int for the number of row/col
        int colsA = scanner.nextInt();

        // create and input Matrix A
        Matrix A = new Matrix(rowsA, colsA);
        A.input(scanner);

        // input the  size of Matrix B
        System.out.print("Enter number of rows and columns for Matrix B: ");
        int rowsB = scanner.nextInt();
        int colsB = scanner.nextInt();

        // create and input Matrix B
        Matrix B = new Matrix(rowsB, colsB);
        B.input(scanner);

        // initialize the result matrix C
        Matrix C = null;

        // menu for matrix operations
        int choice;

        do {
            System.out.println();
            System.out.println("Matrix Operations Menu:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Enter new matrices");
            System.out.println("5. Exit");
            System.out.println("6. Perform Test Simulation (Time versus Matrix Size)");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            try { // handle exceptions
                switch (choice) {
                    case 1:
                        // addition
                        if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) { // check valid dimension for operation
                            System.out.println("Addition not possible. Matrices must have the same dimensions.");
                        } else {
                            // addition
                            C = A.add(B);

                            System.out.println("Result of Addition:");
                            C.display(); // display the result
                        }
                        break;
                    case 2:
                        // subtraction
                        if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) { // check valid dimension for operation
                            System.out.println("Subtraction not possible. Matrices must have the same dimensions.");
                        } else {
                            //substract
                            C = A.subtract(B);

                            System.out.println("Result of Subtraction:");
                            C.display(); // display the result
                        }
                        break;
                    case 3:
                        //  multiplication
                        if (A.getCols() != B.getRows()) { // check valid dimension for operation
                            System.out.println("Multiplication not possible. Number of columns of A must be equal to number of rows of B.");
                        } else {
                            // multiplication
                            C = A.multiply(B);

                            System.out.println("Result of Multiplication:");
                            C.display(); // display the result
                        }
                        break;
                    case 4:
                        // prompt user to enter new matrices
                        System.out.print("Enter number of rows and columns for Matrix A: ");
                        rowsA = scanner.nextInt();
                        colsA = scanner.nextInt();

                        A = new Matrix(rowsA, colsA); // construct matrix A with new dimensions
                        A.input(scanner);

                        System.out.print("Enter number of rows and columns for Matrix B: ");
                        rowsB = scanner.nextInt();
                        colsB = scanner.nextInt();

                        B = new Matrix(rowsB, colsB); // construct Matrix B with new dimensions
                        B.input(scanner);

                        break;
                    case 5:
                        // exit the program
                        System.out.println("Exiting...");
                        break;

                    case 6:
                        {
                            // perform test simulation to gather runtime data
                            Random rand = new Random(); // random generator
                            int size = 10; // square matrix is fine (as noted in the assignment prompt)
                            
                            for(size = 10; size <= 100; size += 5) { // test size: 10, 15, 20, ...
                                Matrix mat1 = new Matrix(size, size);
                                Matrix mat2 = new Matrix(size, size);

                                mat1.randomize(rand);
                                mat2.randomize(rand);

                                //mat1.display();
                                

                                // start time mark
                                long start = System.nanoTime();

                                Matrix res = A.multiply(B);

                                // end time mark
                                long stop = System.nanoTime(); //nano time, needed to /1000 later

                                // duration = end - start
                                long duration = stop - start;

                                System.out.println("Size: " + size + " Time taken: " + duration / 1000 + " microseconds");
                            }

                            break;
                        }
                    default:
                        // handle invalid case
                        System.out.println("Invalid choice. Please enter a valid option.");
                        break;
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a number.");

                scanner.next(); // clear the invalid input
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }

        } while (choice != 5); // loop until user chooses to exit

        scanner.close();
    }
}