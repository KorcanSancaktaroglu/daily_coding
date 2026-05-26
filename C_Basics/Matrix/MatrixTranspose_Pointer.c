#include <stdio.h>
#include <stdlib.h>

/**
 * Function: printMatrixTranspose
 * ----------------------------
 * This function treats a 1D allocated memory block as a 2D matrix 
 * and prints its transpose using pointer arithmetic.
 */
void printMatrixTranspose(int *matrix, int rowCount, int colCount) {
    int i, j;
    printf("\n--- Transposed Matrix [%d][%d]) ---\n", colCount, rowCount);

    // CRITICAL: Outer loop now iterates through the ORIGINAL columns
    for (i = 0; i < colCount; i++) {
        for (j = 0; j < rowCount; j++) {
            // Pointer Arithmetic Formula: 
            // base_address + (current_row * total_columns) + current_column
            // To transpose, we read vertically: j moves through rows, i stays on column
            int value = *(matrix + (j * colCount) + i);
            printf("%d\t", value);
        }
        printf("\n"); // New line after each transposed row
    }
}

int main() {
    int rows = 2, cols = 3; // Example: 2x3 matrix
    
    // Dynamic Memory Allocation (1D Buffer)
    int *matrixBuffer = (int*)malloc(rows * cols * sizeof(int));

    if (matrixBuffer == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    // Initialize/Fill the matrix (Example values: 1, 2, 3, 4, 5, 6)
    printf("--- Original Matrix (2x3) ---\n");
    for (int k = 0; k < rows * cols; k++) {
        *(matrixBuffer + k) = k + 1;
        printf("%d%c", *(matrixBuffer + k), (k + 1) % cols == 0 ? '\n' : '\t');
    }

    // Call the Transpose Function
    printMatrixTranspose(matrixBuffer, rows, cols);

    // CRITICAL: Always free dynamically allocated memory
    free(matrixBuffer);
    matrixBuffer = NULL; // Best practice: avoid dangling pointers

    return 0;
}
