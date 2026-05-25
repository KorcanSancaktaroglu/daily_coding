/*
 * ============================================================
 * MERGE SORT ALGORITHM
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * CORE IDEA:
 * "Divide and Conquer" strategy.
 * Consists of two phases:
 *
 * 1. DIVIDE: Split the array in half, recursively sort 
 * each half. A single-element array is 
 * already sorted — base case.
 *
 * 2. MERGE: Combine two sorted sub-arrays into a single
 * sorted array. This step takes O(n) time.
 *
 * DIFFERENCE FROM QUICK SORT:
 * Quick Sort: Divide first (pivot), then recurse — hard divide, easy merge.
 * Merge Sort: Recurse first, then merge — easy divide, hard merge.
 *
 * TIME COMPLEXITY:
 * In all cases (Best, Average, Worst): O(n log n)
 * log n levels × O(n) merging at each level
 *
 * SPACE COMPLEXITY  : O(n) — requires a temporary array
 * IN-PLACE          : NO
 * STABLE            : YES
 * During the merge, the condition arr[i] <= arr[j] ensures
 * that for equal elements, the left side is taken first -> 
 * original relative order is preserved.
 *
 * TO COMPILE (GCC):
 * gcc -Wall -o merge_sort merge_sort.c
 * ./merge_sort
 * ============================================================
 */

#include <stdio.h>

#define SIZE 10

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(const int arr[], int left, int right, const char *label);

/* ============================================================
 * Main
 * ============================================================ */
int main(void) {
    int arr[SIZE] = { 120, 113, 18, 110, 13, 125, 2, 15, 5, 1 };

    printArray(arr, 0, SIZE - 1, "Unsorted");
    printf("\n");

    mergeSort(arr, 0, SIZE - 1);

    printf("\n");
    printArray(arr, 0, SIZE - 1, "Sorted  ");

    printf("\nPress ENTER to continue...");
    getchar();
    return 0;
}

/* ============================================================
 * mergeSort — Recursive Division
 *
 * Parameters:
 * arr[] : array to be sorted
 * left  : starting index of the sub-array
 * right : ending index of the sub-array
 *
 * Base condition: left >= right (single element or empty array)
 * ============================================================ */
void mergeSort(int arr[], int left, int right) {
    int mid;

    if (left >= right) {
        /* Single element — already sorted, halt recursion */
        return;
    }

    mid = (left + right) / 2;

    printf("  Divide : [%d..%d] -> [%d..%d] + [%d..%d]\n",
           left, right, left, mid, mid + 1, right);

    mergeSort(arr, left, mid);       /* Sort the left half  */
    mergeSort(arr, mid + 1, right);  /* Sort the right half */
    merge(arr, left, mid, right);    /* Merge the two sorted halves */
}

/* ============================================================
 * merge — Combine two sorted sub-arrays
 *
 * [left..mid] and [mid+1..right] are already sorted.
 * Merge them in ascending order into tempArr[], 
 * then copy back to arr[].
 *
 * WHY IS IT STABLE?
 * The condition arr[i] <= arr[j] ensures that for equal elements,
 * the left side is taken first. If we used '<', the right side 
 * would be taken first, making it unstable.
 * ============================================================ */
void merge(int arr[], int left, int mid, int right) {
    int tempArr[SIZE];
    int i = left;      /* Scanner index for the left half  */
    int j = mid + 1;   /* Scanner index for the right half */
    int k = left;      /* Write index for the temp array   */

    /* Compare elements from both halves and write to tempArr[] */
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[k++] = arr[i++];  /* Left element is smaller/equal */
        } else {
            tempArr[k++] = arr[j++];  /* Right element is smaller */
        }
    }

    /* Copy any remaining elements from the left half */
    while (i <= mid) {
        tempArr[k++] = arr[i++];
    }

    /* Copy any remaining elements from the right half */
    while (j <= right) {
        tempArr[k++] = arr[j++];
    }

    /* Copy sorted elements from tempArr[] back to the original arr[] */
    for (i = left; i <= right; i++) {
        arr[i] = tempArr[i];
    }

    printf("  Merge  [%d..%d]+[%d..%d] -> ", left, mid, mid + 1, right);
    printArray(arr, left, right, "");
}

/* ============================================================
 * printArray: Helper output function
 * ============================================================ */
void printArray(const int arr[], int left, int right, const char *label) {
    int i;
    if (label[0] != '\0') {
        printf("%-9s: ", label); /* Left-aligned for cleaner console output */
    }
    for (i = left; i <= right; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}
