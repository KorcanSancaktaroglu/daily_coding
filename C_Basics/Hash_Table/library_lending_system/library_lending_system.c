#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 53

typedef struct StudentRecord {
    char student_id[12];        /* key */
    char full_name[50];
    char book_title[100];
    int  borrow_days;           /* how many days borrowed */
    struct StudentRecord* next; /* chaining */
} StudentRecord;

StudentRecord* hashTable[TABLE_SIZE];

int hash_calc(const char* student_id) {
    int hash = 0;
    size_t len = strlen(student_id);
    for (size_t i = 0; i < len; i++) {
        hash = hash * 17 + student_id[i];
    }
    return hash % TABLE_SIZE;
}

void record_insert(const char* student_id, const char* full_name,
    const char* book_title, int borrow_days) {

    int index = hash_calc(student_id);

    StudentRecord* new_rec = (StudentRecord*)malloc(sizeof(StudentRecord));
    if (!new_rec) {
        printf("Record could not be created\n");
        return;
    }

    new_rec->next = NULL;
    strcpy(new_rec->student_id, student_id);
    strcpy(new_rec->full_name, full_name);
    strcpy(new_rec->book_title, book_title);
    new_rec->borrow_days = borrow_days;

    if (hashTable[index] != NULL) {
        StudentRecord* temp = hashTable[index];
        while (temp->next) temp = temp->next;
        temp->next = new_rec;
    }
    else {
        hashTable[index] = new_rec;
    }

    printf("Record created successfully\n");
}

void record_search(const char* student_id) {
    int index = hash_calc(student_id);
    StudentRecord* current = hashTable[index];

    while (current) {
        if (strcmp(current->student_id, student_id) == 0) {
            printf("Student %s found — %s | %s | %d days\n",
                student_id, current->full_name,
                current->book_title, current->borrow_days);
            return;
        }
        current = current->next;
    }
    printf("Student %s not found\n", student_id);
}

void record_delete(const char* student_id) {
    int index = hash_calc(student_id);
    StudentRecord* prev = NULL;
    StudentRecord* target = hashTable[index];

    /* 1. search the chain */
    while (target) {
        if (strcmp(target->student_id, student_id) == 0) break;
        prev = target;
        target = target->next;
    }

    /* 2. not found */
    if (!target) {
        printf("Student %s not found\n", student_id);
        return;
    }

    /* 3. detach from chain */
    if (prev == NULL)
        hashTable[index] = target->next;  /* head node */
    else
        prev->next = target->next;        /* middle / tail node */

    /* 4. free memory */
    free(target);
    printf("Student %s deleted\n", student_id);
}

int main() {
    record_insert("2021010034", "Ali Yilmaz", "Algorithms", 5);
    record_insert("2021010087", "Ayse Kaya", "Data Structures", 12);
    record_insert("2022050034", "Veli Demir", "C Programming", 3);

    record_search("2021010034");
    record_search("9999999999");

    record_delete("2021010087");
    record_search("2021010087");

    return 0;
}
