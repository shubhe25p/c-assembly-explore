#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform matrix multiplication
void matrixMultiply(int *a, int *b, int *c, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                 c[i * N + j] += a[i * N + k] * b[k * N + j];
            }
        }
    }
}

int main() {
    int N=10;

    // Allocate memory for matrices
    int *a = (int *)malloc(N * N * sizeof(int));
    int *b = (int *)malloc(N * N * sizeof(int));
    int *c = (int *)malloc(N * N * sizeof(int));

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i * N + j] = rand() % 10;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i * N + j] = rand() % 10;
        }
    }

    // Timing code
    clock_t start = clock();

    // Perform matrix multiplication
    matrixMultiply(a, b, c, N);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for multiplication: %f seconds\n", time_spent);

    // Free allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
