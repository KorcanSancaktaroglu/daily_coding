#include <stdio.h>   /* printf  */
#include <stdlib.h>  /* standard library */
#include <string.h>  /* memset  */

#define BASE 10      /* Number base (Decimal) */
#define SIZE 10      /* Array size */

/* ---- Function Declarations -------------------------------- */
int getMaxDigitCount(int arr[], int n);
void radixSort(int arr[], int n);
void printArray(const int arr[], int n, const char* label);

/* ============================================================
 * Main
 * ============================================================ */
int main(void) {
    int arr[SIZE] = { 120, 113, 18, 110, 13, 125, 2, 15, 5, 1 };

    printArray(arr, SIZE, "Unsorted");

    radixSort(arr, SIZE);

    printArray(arr, SIZE, "Sorted");

    printf("\nPress ENTER to continue...");
    getchar();   /* Standard cross-platform pause */
    return 0;
}

/* ============================================================
 * getMaxDigitCount: Finds the number of digits in the maximum
 * element of the array.
 * Example: maxVal = 125  ->  digitCount = 3
 * ============================================================ */
int getMaxDigitCount(int arr[], int n) {
    int maxVal = arr[0];
    int i, digitCount = 0;

    for (i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    /* Safety check against an array of 0s */
    if (maxVal == 0) {
        return 1;
    }

    while (maxVal > 0) {
        digitCount++;
        maxVal /= BASE;
    }
    return digitCount;
}

/* ============================================================
 * radixSort: Radix Sort Algorithm Implementation
 *
 * Step by step:
 * 1. Find the max number of digits (determines pass count).
 * 2. For each pass:
 * a) Reset all buckets.
 * b) Distribute elements into buckets based on current digit.
 * c) Empty buckets back into the original array.
 * d) Multiply placeValue by 10 (move to the next digit).
 * ============================================================ */
void radixSort(int arr[], int n) {
    int bucket[BASE][SIZE];      /* bucket[digitValue][index] */
    int bucketCount[BASE];       /* tracks number of elements in each bucket */

    int i, j, k, h;
    int digit;
    int maxDigits = getMaxDigitCount(arr, n);
    int placeValue = 1;          /* 1: ones, 10: tens, 100: hundreds... */

    printf("Max element digit count: %d\n\n", maxDigits);

    for (h = 0; h < maxDigits; h++) {

        /* --- a) Reset buckets ----------------------------- */
        memset(bucketCount, 0, sizeof(bucketCount));
        memset(bucket, 0, sizeof(bucket));

        /* --- b) Distribute elements into buckets ---------- */
        for (i = 0; i < n; i++) {
            digit = (arr[i] / placeValue) % BASE;
            bucket[digit][bucketCount[digit]] = arr[i];
            bucketCount[digit]++;
        }

        /* --- c) Empty buckets and update array ------------ */
        i = 0;
        for (k = 0; k < BASE; k++) {
            for (j = 0; j < bucketCount[k]; j++) {
                arr[i] = bucket[k][j];
                i++;
            }
        }

        /* Print intermediate steps for debugging & tracking */
        printf("Pass %d (%-8s place) placeValue=%-4d: ",
            h + 1,
            h == 0 ? "ones" : h == 1 ? "tens" : "hundreds",
            placeValue);
        printArray(arr, n, "");

        placeValue *= BASE;
    }
}

/* ============================================================
 * printArray: Helper function for printing arrays cleanly
 * ============================================================ */
void printArray(const int arr[], int n, const char* label) {
    int i;
    if (label[0] != '\0') {
        printf("%-9s : ", label); /* Left-aligned for cleaner console output */
    }
    for (i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}
