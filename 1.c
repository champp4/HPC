#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int A[n][n], x[n], y[n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);  // Input matrix A
           // A[i][j]=rand()%100;
        }
    }

    printf("Enter vector x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);  // Input vector x
        y[i] = 0;  // Initialize y[i] to 0
       // x[i]=rand()%100;
    }

    // Serial or Parallel computation
    clock_t start = clock();

    // Uncomment this line for parallel execution
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];  // Matrix-vector multiplication
        }
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Result y: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    // Output the execution time
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
