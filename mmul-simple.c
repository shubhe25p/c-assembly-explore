#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform matrix multiplication
void matrixMultiply(int *a, int *b, int *c, int rows, int cols, int cols_b) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                 sum += a[i * cols + k] * 
                 b[k * cols_b + j];
            }
            c[i * cols_b + j] = sum;
        }
    }
}

int main() {
    int rows_a = 2000;
    int cols_a = 2000;
    int cols_b = 2000;

    // Allocate memory for matrices
    int *a = (int *)malloc(rows_a * cols_a * sizeof(int));
    int *b = (int *)malloc(cols_a * cols_b * sizeof(int));
    int *c = (int *)malloc(rows_a * cols_b * sizeof(int));

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            a[i * cols_a + j] = rand() % 10;
        }
    }
    for (int i = 0; i < cols_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            b[i * cols_b + j] = rand() % 10;
        }
    }

    // Timing code
    clock_t start = clock();

    // Perform matrix multiplication
    matrixMultiply(a, b, c, rows_a, cols_a, cols_b);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for multiplication: %f seconds\n", time_spent);

    // Free allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
