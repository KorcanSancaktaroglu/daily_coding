/*
 * ============================================================
 * QUICK SORT ALGORITHM
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * CORE IDEA:
 * "Divide and Conquer" strategy.
 * Select a pivot element; move smaller elements to the left,
 * and larger elements to the right (partitioning). Then, 
 * recursively apply the same process to both sub-arrays.
 *
 * PIVOT SELECTION (In this implementation):
 * Middle index -> arr[(left + right) / 2]
 * Choosing the first/last element can degrade performance to 
 * O(n^2) for already sorted arrays. The middle index provides 
 * a more balanced partition on average.
 *
 * TIME COMPLEXITY:
 * Average : O(n log n)
 * Worst   : O(n^2)   <- Occurs if the pivot is always the min/max
 * Best    : O(n log n)
 *
 * SPACE COMPLEXITY  : O(log n) — Due to the recursion stack
 * IN-PLACE          : Yes (No extra array allocation needed)
 * STABLE            : NO
 *
 * TO COMPILE (GCC):
 * gcc -Wall -o quick_sort quick_sort.c
 * ./quick_sort
 * ============================================================
 */

#include <stdio.h>

#define SIZE 10

void quickSort(int arr[], int left, int right);
void printArray(const int arr[], int left, int right, const char *label);

/* ============================================================
 * Main
 * ============================================================ */
int main(void) {
    int arr[SIZE] = { 120, 113, 18, 110, 13, 125, 2, 15, 5, 1 };

    printArray(arr, 0, SIZE - 1, "Unsorted");
    printf("\n");

    quickSort(arr, 0, SIZE - 1);

    printf("\n");
    printArray(arr, 0, SIZE - 1, "Sorted  ");

    printf("\nPress ENTER to continue...");
    getchar();
    return 0;
}

/* ============================================================
 * quickSort — Partitioning + Recursion
 *
 * Parameters:
 * arr[] : Array to be sorted
 * left  : Starting index of the sub-array
 * right : Ending index of the sub-array
 *
 * Algorithm Steps:
 * 1. Choose pivot = arr[(left + right) / 2]
 * 2. Start two pointers: low = left, high = right
 * 3. Move 'low' right: loop until arr[low] >= pivot
 * 4. Move 'high' left: loop until arr[high] <= pivot
 * 5. If low <= high, swap elements, low++, high--
 * 6. When low > high, partitioning is complete
 * 7. Recursively sort sub-arrays: [left..high] and [low..right]
 * ============================================================ */
void quickSort(int arr[], int left, int right) {
    int low = left;
    int high = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    printf("  QuickSort([%d..%d])  pivot = arr[%d] = %d\n",
           left, right, (left + right) / 2, pivot);
    printf("  Before : ");
    printArray(arr, left, right, "");

    /* ---- Partition Loop ------------------------------------ */
    do {
        /*
         * Shift 'low' to the right: Elements smaller than the pivot
         * are already in the correct place -> skip them
         */
        while (arr[low] < pivot && low < right) {
            low++;
        }

        /*
         * Shift 'high' to the left: Elements larger than the pivot
         * are already in the correct place -> skip them
         */
        while (arr[high] > pivot && high > left) {
            high--;
        }

        if (low <= high) {
            /* Two elements are on the wrong side -> Swap them */
            printf("  Swap   : %3d <-> %3d\n", arr[low], arr[high]);
            temp      = arr[low];
            arr[low]  = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }

    } while (low <= high);

    printf("  After  : ");
    printArray(arr, left, right, "");
    printf("  Left Part [%d..%d]  Right Part [%d..%d]\n", left, high, low, right);
    printf("  ----------------------------------------\n");

    /* ---- Recursive Calls ----------------------------------- */
    if (left < high)  quickSort(arr, left, high);   /* Left partition  */
    if (low < right)  quickSort(arr, low, right);   /* Right partition */
}

/* ============================================================
 * printArray: Prints the sub-array within [left..right]
 * ============================================================ */
void printArray(const int arr[], int left, int right, const char *label) {
    int i;
    if (label[0] != '\0') {
        printf("%-8s: ", label); /* Left-aligned for cleaner console output */
    }
    for (i = left; i <= right; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}
