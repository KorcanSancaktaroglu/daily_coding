/*
 * ============================================================
 * BINARY SEARCH TREE (BST) - Word Frequency Counter
 * Data Structures & Algorithms — Implementation Example
 * ============================================================
 *
 * CORE IDEA:
 * Reads words from a text file and inserts them into a BST.
 * If a word already exists, its frequency is incremented.
 * Since it's a BST, an in-order traversal automatically 
 * yields the words in alphabetical order.
 *
 * FEATURES:
 * - Build BST from a text file
 * - Search for a specific word and get its frequency
 * - List all words alphabetically with frequencies
 * - Export the alphabetical list to a new text file
 * - Count total unique words (nodes) in the tree
 *
 * TO COMPILE (GCC):
 * gcc -Wall -o bst_word_counter bst_word_counter.c
 * ./bst_word_counter
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct Node {
    char word[MAX_WORD_LEN];
    int frequency;
    struct Node *left, *right;
} Node;

Node* newNode(const char* word) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->frequency = 1;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, const char* word) {
    if (root == NULL) return newNode(word);
    
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insert(root->left, word);
    } else if (cmp > 0) {
        root->right = insert(root->right, word);
    } else {
        root->frequency++;
    }
    return root;
}

Node* search(Node* root, const char* word) {
    if (root == NULL) return NULL;
    
    int cmp = strcmp(word, root->word);
    if (cmp == 0) return root;
    if (cmp < 0)  return search(root->left, word);
    return search(root->right, word);
}

void listFrequencies(Node* root) {
    if (root == NULL) return;
    
    listFrequencies(root->left);
    printf("%-20s : %d\n", root->word, root->frequency);
    listFrequencies(root->right);
}

void writeToFile(Node* root, FILE* file) {
    if (root == NULL) return;
    
    writeToFile(root->left, file);
    fprintf(file, "%s %d\n", root->word, root->frequency);
    writeToFile(root->right, file);
}

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* buildTreeFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) { 
        printf("Error: Could not open file '%s'!\n", filename); 
        return NULL; 
    }
    
    Node* root = NULL;
    char word[MAX_WORD_LEN];
    /* Using %99s prevents buffer overflow for 100-character arrays */
    while (fscanf(file, "%99s", word) == 1) {
        root = insert(root, word);
    }
    
    fclose(file);
    return root;
}

int main() {
    Node* root = NULL;
    int choice;
    char inputBuffer[MAX_WORD_LEN];

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1- Build BST from file\n");
        printf("2- Search for a word\n");
        printf("3- List word frequencies (Alphabetical)\n");
        printf("4- Export alphabetical list to file\n");
        printf("5- Display total node count\n");
        printf("6- Exit\n");
        printf("Your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); /* clear input buffer */
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter filename (e.g., input.txt): ");
                scanf("%99s", inputBuffer);
                root = buildTreeFromFile(inputBuffer);
                if (root) printf("Success: Tree successfully built from '%s'.\n", inputBuffer);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%99s", inputBuffer);
                Node* result = search(root, inputBuffer);
                if (result) {
                    printf("Found! The word '%s' appears %d time(s).\n", result->word, result->frequency);
                } else {
                    printf("Not found: The word '%s' is not in the tree.\n", inputBuffer);
                }
                break;
            case 3:
                printf("\n--- Word Frequencies ---\n");
                listFrequencies(root);
                printf("------------------------\n");
                break;
            case 4: {
                FILE* file = fopen("output.txt", "w");
                if (file) {
                    writeToFile(root, file);
                    fclose(file);
                    printf("Success: Data successfully written to 'output.txt'.\n");
                } else {
                    printf("Error: Could not create output file.\n");
                }
                break;
            }
            case 5:
                printf("Total unique words (nodes): %d\n", countNodes(root));
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
