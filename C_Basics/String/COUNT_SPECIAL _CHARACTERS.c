/*
 * ============================================================
 * COUNT SPECIAL CHARACTERS (Visited Array Approach)
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * APPROACH:
 * Iterates through the given string. When a lowercase letter 
 * is found that hasn't been processed yet, it is marked as 
 * 'visited' to prevent double-counting (e.g., in "aaA").
 * Then, it searches the array for its uppercase counterpart 
 * using ASCII math (-32).
 *
 * TIME COMPLEXITY  : O(N^2) in the worst case.
 * SPACE COMPLEXITY : O(1) — Uses a fixed-size array of 26.
 * ============================================================
 */

#include <stdio.h>

int numberOfSpecialChars(char* word) {
    int counter = 0;
    int visited[26] = {0}; /* Tracking array for lowercase letters a-z */

    for (int i = 0; word[i] != '\0'; i++) {
        char currentChar = word[i];

        /* Check if it's a lowercase letter and NOT visited yet */
        if ('a' <= currentChar && currentChar <= 'z' && !visited[currentChar - 'a']) {
            
            visited[currentChar - 'a'] = 1; /* Mark this letter as processed */
            currentChar -= 32;              /* Convert to uppercase */

            /* Search for the uppercase counterpart */
            for (int j = 0; word[j] != '\0'; j++) {
                if (word[j] == currentChar) {
                    counter++;
                    break; /* Found the match, stop searching */
                }
            }
        }
    }

    return counter;
}

/* ============================================================
 * Main function for testing
 * ============================================================ */
int main(void) {
    char testWord1[] = "aaA";      /* Expected output: 1 */
    char testWord2[] = "aA";       /* Expected output: 1 */
    char testWord3[] = "AbC";      /* Expected output: 0 */
    
    printf("Word: %-10s -> Special Characters: %d\n", testWord1, numberOfSpecialChars(testWord1));
    printf("Word: %-10s -> Special Characters: %d\n", testWord2, numberOfSpecialChars(testWord2));
    printf("Word: %-10s -> Special Characters: %d\n", testWord3, numberOfSpecialChars(testWord3));

    return 0;
}
