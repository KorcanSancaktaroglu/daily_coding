#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global Stack and Top Pointer
char* stack;
int top = -1;

void push(char character) {
    stack[++top] = character;
}

char pop() {
    return stack[top--];
}

bool isPalindrome(char str[]) {
    if (!str || str[0] == '\0') return false;

    int length = (int)strlen(str);
    int mid = length / 2;
    int i;

    // Allocate memory exactly for half of the string
    stack = (char*)malloc(sizeof(char) * mid);
    if (!stack) return false;

    // Push the first half onto the stack
    for (i = 0; i < mid; i++) {
        push(str[i]);
        printf("Step %d: '%c' pushed to stack\n", i + 1, str[i]);
    }

    // If length is odd, skip the middle character
    if (length % 2 != 0) {
        i++;
    }

    // Compare the remaining half with the stack
    bool match = true;
    while (str[i] != '\0') {
        char poppedChar = pop();
        printf("Comparing: Popped '%c' with String '%c'\n", poppedChar, str[i]);
        
        if (poppedChar != str[i]) {
            match = false;
            break;
        }
        i++;
    }

    free(stack); // Clean up memory
    return match;
}

int main() {
    char word[100];
    printf("Enter a word to check for palindrome: ");
    if (scanf("%99s", word) != 1) return -1;

    if (isPalindrome(word)) {
        printf("\nRESULT: '%s' is a palindrome! (Return 1)\n", word);
        return 1;
    } else {
        printf("\nRESULT: '%s' is NOT a palindrome. (Return -2)\n", word);
        return -2;
    }
}
