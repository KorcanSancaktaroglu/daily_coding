#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    // Variable Declarations
    int rows, cols, i, j, value;
    int* messageData, * ptr;
    int searchItems[5];
    int itemCount = 0;

    // 1. INPUT: Matrix Dimensions and Allocation
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamic Memory Allocation using calloc (initializes to zero)
    messageData = (int*)calloc(rows * cols, sizeof(int));

    if (!messageData) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    // 2. INPUT: Fill the Matrix using Pointer Arithmetic
    printf("\n--- Filling the Matrix ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &value);

            // Formula: base_address + (current_row * total_columns) + current_column
            ptr = messageData + (i * cols) + j;
            *ptr = value;
        }
    }

    // 3. INPUT: Data to Search
    printf("\nEnter up to 5 items to search (Enter 0 to stop):\n");
    for (i = 0; i < 5; i++) {
        printf("Search Item %d: ", i + 1);
        scanf("%d", &value);

        if (value != 0) {
            searchItems[i] = value;
            itemCount++;
        }
        else break;
    }

    // 4. LOGIC: Search and Mark with -1
    // We scan the entire memory block as a single array for efficiency
    for (int k = 0; k < itemCount; k++) {
        for (i = 0; i < (rows * cols); i++) {
            ptr = messageData + i;
            if (*ptr == searchItems[k]) {
                *ptr = -1; // Replace found item with -1
            }
        }
    }

    // 5. OUTPUT: Display Processed Matrix
    printf("\n--- Processed Message Matrix ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ptr = messageData + (i * cols) + j;
            printf("%d\t", *ptr);
        }
        printf("\n");
    }

    // 6. CLEANUP: Free Dynamic Memory (MÜDEK Standard)
    free(messageData);
    printf("\nMemory freed. Program finished.\n");

    return 0;
}
