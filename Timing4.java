import java.util.Scanner;
import java.util.Random;

class Matrix {
    private float[][] data;
    private int rows;
    private int cols;

    public Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new float[rows][cols];
    }

    public void input(Random rand) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand.nextFloat();
            }
        }
    }

    public Matrix multiply(Matrix B) {
        if (cols != B.rows) throw new IllegalArgumentException("Dimensions mismatch for multiplication");
        Matrix C = new Matrix(rows, B.cols);
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
}

public class Timing4 {
    public static void main(String[] args) {
        Random rand = new Random();
        int size = 20;
        Matrix A = new Matrix(size, size);
        Matrix B = new Matrix(size, size);

        A.input(rand);
        B.input(rand);

        long start = System.nanoTime();
        Matrix C = A.multiply(B);
        long stop = System.nanoTime();

        long duration = stop - start;
        System.out.println("Time taken by function: " + duration / 1000 + " microseconds");
    }
}