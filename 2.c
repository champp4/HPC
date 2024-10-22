#include <stdio.h>
#include <time.h>
#include <omp.h>

int main() {
    int clothing, gaming, grocery, stationary;
    int total_amount = 0; // Unified total

    clock_t start_time, end_time; // Timing variables

    // Input amounts for each section
    printf("Enter the amount for clothing: ");
    scanf("%d", &clothing);
    printf("Enter the amount for gaming: ");
    scanf("%d", &gaming);
    printf("Enter the amount for grocery: ");
    scanf("%d", &grocery);
    printf("Enter the amount for stationary: ");
    scanf("%d", &stationary);

    // Serial execution to calculate total
    start_time = clock(); // Start serial timing

    total_amount = clothing + gaming + grocery + stationary;

    end_time = clock(); // End serial timing

    // Display total amount (only once)
    printf("Total Amount (Serial): %d\n", total_amount);

    // Display serial execution time
    printf("Serial Execution Time: %f seconds\n", 
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Reset total amount for parallel calculation
    total_amount = 0;

    // Parallel execution to calculate total amount
    start_time = clock(); // Start parallel timing

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                #pragma omp atomic
                total_amount += clothing;
            }
            #pragma omp section
            {
                #pragma omp atomic
                total_amount += gaming;
            }
            #pragma omp section
            {
                #pragma omp atomic
                total_amount += grocery;
            }
            #pragma omp section
            {
                #pragma omp atomic
                total_amount += stationary;
            }
        }
    }

    end_time = clock(); // End parallel timing

    // Display total amount (parallel)
    printf("Total Amount (Parallel): %d\n", total_amount);

    // Display parallel execution time
    printf("Parallel Execution Time: %f seconds\n", 
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
