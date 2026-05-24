/*
 * ============================================================
 * SELECTION SORT ALGORITHM
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * CORE IDEA:
 * Divide the array into two regions:
 * [0 .. i-1]  -> sorted (grows by one in each pass)
 * [i .. n-1]  -> unsorted
 * In each pass, find the MINIMUM element in the unsorted region,
 * and move it to the immediate next position of the sorted region (index i).
 * After n-1 passes, the entire array is sorted.
 *
 * ALGORITHM STEPS:
 * for i = 0 -> n-2:
 * min_idx = i
 * for j = i+1 -> n-1:
 * if arr[j] < arr[min_idx]: min_idx = j
 * if min_idx != i: swap(arr[i], arr[min_idx])
 *
 * TIME COMPLEXITY:
 * In all cases (Best, Average, Worst): O(n^2)
 * Number of comparisons: n*(n-1)/2 (independent of array state)
 * Number of swaps: at most n-1 (superior to other O(n^2) algorithms in this regard)
 *
 * SPACE COMPLEXITY  : O(1) — in-place
 * STABLE            : NO
 * Example: { 5a, 5b, 1 } -> In Pass 1, 5a is swapped with 1
 * { 1, 5b, 5a } — The relative order of 5a and 5b is lost
 *
 * TO COMPILE (GCC):
 * gcc -Wall -o selection_sort selection_sort.c
 * ./selection_sort
 * ============================================================
 */

#include <stdio.h>

#define SIZE 10

void selectionSort(int arr[], int n);
void printArray(const int arr[], int n, const char *label);

/* ============================================================
 * Main
 * ============================================================ */
int main(void) {
    int arr[SIZE] = { 120, 113, 18, 110, 13, 125, 2, 15, 5, 1 };

    printArray(arr, SIZE, "Unsorted");
    printf("\n");

    selectionSort(arr, SIZE);

    printf("\n");
    printArray(arr, SIZE, "Sorted  ");

    printf("\nPress ENTER to continue...");
    getchar();
    return 0;
}

/* ============================================================
 * selectionSort
 *
 * Parameters:
 * arr[] : array to be sorted
 * n     : number of elements
 * ============================================================ */
void selectionSort(int arr[], int n) {
    int i, j;
    int min_idx;   /* index of the minimum element in the unsorted region */
    int temp;

    for (i = 0; i < n - 1; i++) {

        /* ---- 1. Find the minimum in the unsorted region ----- */
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        /* ---- 2. Do not swap if the minimum is already in place -- */
        if (min_idx != i) {
            printf("  Pass %2d: min=%4d (index %d) <-> arr[%d]=%4d  -->  ",
                   i + 1, arr[min_idx], min_idx, i, arr[i]);
            temp         = arr[i];
            arr[i]       = arr[min_idx];
            arr[min_idx] = temp;
        } else {
            printf("  Pass %2d: min=%4d already in place [%d]          -->  ",
                   i + 1, arr[i], i);
        }

        printArray(arr, n, "");
    }
}

/* ============================================================
 * printArray: Helper output function
 * ============================================================ */
void printArray(const int arr[], int n, const char *label) {
    int i;
    if (label[0] != '\0') {
        printf("%-9s: ", label); /* Left-aligned for cleaner console output */
    }
    for (i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}
