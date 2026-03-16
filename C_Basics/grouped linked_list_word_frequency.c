#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 25
#define MAX_WORD_LENGTH 50

typedef struct word_type {
    char word[MAX_WORD_LENGTH];
    int count;
    struct word_type* next;

}word;
void processFile(word* buckets[]);
void addOrUpdateWord(word* buckets[], char* newWord);
void freeAllLists(word* buckets[]);
void displayStats(word* buckets[]);

int main()
{
    word* buckets[BUCKET_SIZE]{NULL};
    processFile(buckets);
    displayStats(buckets);
    freeAllLists(buckets);
    printf("\nProcess completed. Memory deallocated.\n");
    


    return 0;
}
void processFile(word* buckets[]) {
    char filename[30];  printf("Enter the file name:"); fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    if (!filename || filename[0] == '\0') { printf("invalid file name\n"); return; }
    FILE* fp = fopen(filename, "r");
    if(!fp){
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", buffer) != EOF) {
        addOrUpdateWord(buckets, buffer);
    }
    fclose(fp);
}
void addOrUpdateWord(word* buckets[], char* newWord) {
    int len = (int)strlen(newWord);
    if (len >= BUCKET_SIZE) return;
    word* curr = buckets[len];

    while (curr) {
        if (strcmp(curr->word, newWord) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    word* newNode = (word*)malloc(sizeof(word));
    if (!newNode) return;
    strcpy(newNode->word, newWord); newNode->count = 1;

    newNode->next = buckets[len];
    buckets[len] = newNode;

}
void displayStats(word* buckets[]) {
    printf("\n--- Word Frequency Report (Grouped by Length) ---\n");
    for (int i = 1; i < BUCKET_SIZE; i++) {
        if (buckets[i]) {
            printf("\nWords with Length [%d]:\n", i);
            word* temp = buckets[i];
            
                while (temp) {
                    printf("  -> %s: %d\n", temp->word, temp->count);
                    temp = temp->next;


                }

            
        }
    }
}
void freeAllLists(word* buckets[]) {
    printf("Lists are being cleared.\n");
    for (int i = 1; i < BUCKET_SIZE; i++) {
        word* curr= buckets[i];
        while (curr) {
            word*temp = curr;
            curr = curr->next;
            free(temp);

        }
        buckets[i] = NULL;


    }


}
   
