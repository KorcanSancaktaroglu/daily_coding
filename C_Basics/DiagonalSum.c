#include <stdio.h>
#include <stdlib.h>

/**
 * Technical Specification:
 * This function processes a 1D memory array as a logical 2D square matrix.
 * It identifies and sums elements on the primary diagonal axis.
 */
int calculateDiagonalSum(int *matrix, int rows, int cols) {
    
    // Integrity Check: Only symmetric (square) matrices have a primary diagonal
    if (rows != cols) {
        printf("Validation Failed: Dimensions %dx%d do not form a square matrix.\n", rows, cols);
        return -1; 
    }

    int diagonalTotal = 0;
    printf("\n--- Iterating Through Primary Diagonal Elements ---\n");

    for (int i = 0; i < rows; i++) {
        /* * Address Calculation Logic:
         * In a diagonal element, the row index equals the column index (i == j).
         * Linear offset formula = (current_row * total_columns) + current_column
         * Since i = j, the offset simplifies to: (i * cols) + i
         */
        int *targetAddress = matrix + (i * cols) + i;
        
        printf("Index Mapping [%d][%d] -> Value: %d\n", i, i, *targetAddress);
        diagonalTotal += *targetAddress;
    }

    return diagonalTotal;
}

int main() {
    // Dynamic Dimension Definition
    int matrixSize = 3; 
    
    // Heap Allocation: Reserving contiguous memory block for a 3x3 structure
    int *dataBuffer = (int*)malloc(matrixSize * matrixSize * sizeof(int));

    // Runtime Safety: Check if memory allocation was successful
    if (dataBuffer == NULL) {
        printf("System Error: Critical memory allocation failure.\n");
        return 1;
    }

    // Data Initialization: Populating the buffer with sequential integers
    for (int k = 0; k < matrixSize * matrixSize; k++) {
        *(dataBuffer + k) = k + 1;
    }

    // Execution: Passing the pointer and dimensions to the processing function
    int result = calculateDiagonalSum(dataBuffer, matrixSize, matrixSize);

    // Output Handling
    if (result != -1) {
        printf("\nCalculation Complete. Primary Diagonal Sum: %d\n", result);
    }

    // Memory Deallocation: Releasing the reserved heap memory to prevent leaks
    free(dataBuffer);
    dataBuffer = NULL; // Nullifying the pointer for safety (best practice)

    return 0;
}
