/*
 * ============================================================
 * INSERTION SORT ALGORITHM
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * CORE IDEA:
 * Playing card sorting analogy:
 * At each step, take the next card (key) and place it in 
 * its correct position among the already sorted cards in your hand.
 *
 * The array is divided into two regions:
 * [0 .. i-1]  -> sorted region (grows by one in each pass)
 * [i .. n-1]  -> unsorted region
 *
 * In each pass:
 * 1. Pick key = arr[i]
 * 2. Scan the sorted region from right to left
 * 3. Shift elements greater than the key one position to the right
 * 4. Insert the key into the newly emptied space
 *
 * TIME COMPLEXITY:
 * Best    : O(n)   <- If the array is already sorted (while loop never runs)
 * Average : O(n^2)
 * Worst   : O(n^2) <- If the array is reverse sorted
 *
 * SPACE COMPLEXITY  : O(1) — in-place
 * STABLE            : YES
 * Since the while condition is arr[j] > key, identical elements 
 * are not swapped, preserving their original relative order.
 *
 * IN PRACTICE:
 * Extremely fast for small arrays and nearly sorted arrays.
 * This is why hybrid algorithms (like TimSort, IntroSort) 
 * switch to Insertion Sort when the sub-array size becomes small.
 *
 * TO COMPILE (GCC):
 * gcc -Wall -o insertion_sort insertion_sort.c
 * ./insertion_sort
 * ============================================================
 */

#include <stdio.h>

#define SIZE 10

void insertionSort(int arr[], int n);
void printArray(const int arr[], int n, const char *label);

/* ============================================================
 * Main
 * ============================================================ */
int main(void) {
    int arr[SIZE] = { 120, 113, 18, 110, 13, 125, 2, 15, 5, 1 };

    printArray(arr, SIZE, "Unsorted");
    printf("\n");

    insertionSort(arr, SIZE);

    printf("\n");
    printArray(arr, SIZE, "Sorted  ");

    printf("\nPress ENTER to continue...");
    getchar();
    return 0;
}

/* ============================================================
 * insertionSort
 *
 * Parameters:
 * arr[] : array to be sorted
 * n     : number of elements
 *
 * Difference from Selection Sort:
 * Selection : Scans entire array -> finds minimum -> one swap
 * Insertion : Takes a key -> shifts sorted elements -> inserts
 * NO SWAPS — only shifting is involved.
 * ============================================================ */
void insertionSort(int arr[], int n) {
    int i, j;
    int key;   /* The element to be inserted in the current pass */

    for (i = 1; i < n; i++) {

        key = arr[i];   /* Take the first element of the unsorted region */
        j = i - 1;

        /*
         * Scan the sorted region from right to left:
         * Shift elements greater than the 'key' one position to the right.
         * This is a SHIFT operation, NOT a swap.
         */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];   /* Shift one position to the right */
            j--;
        }

        /*
         * j+1 is the correct position for the key.
         * The while loop stops either when j < 0 or arr[j] <= key.
         */
        arr[j + 1] = key;

        printf("  Pass %2d: key=%4d  -->  ", i, key);
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
