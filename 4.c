#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 #include <omp.h> // Uncomment this line if you want to use OpenMP

int main() {
    int n;
    printf("Number of terms: ");
    scanf("%d", &n);
    
    if (n < 2) {
        printf("Please enter a value greater than or equal to 2.\n");
        return 1; // Exit if n is less than 2
    }

    int* a = (int*)malloc(n * sizeof(int));
    a[0] = 0;
    a[1] = 1;

    clock_t st, et;
    st = clock();

   // Uncomment for parallel Fibonacci calculation using OpenMP
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 2; i < n; i++) {
            a[i] = a[i - 2] + a[i - 1];
        }
    }

    // // Sequential Fibonacci calculation
    // for (int i = 2; i < n; i++) {
    //     a[i] = a[i - 2] + a[i - 1]; // Calculation dependent on previous two values
    // }

    printf("Fibonacci numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    et = clock();
    printf("Time Taken: %lf ms\n", ((double)(et - st) * 1000 / CLOCKS_PER_SEC));

    free(a); // Free allocated memory
    return 0;
}
