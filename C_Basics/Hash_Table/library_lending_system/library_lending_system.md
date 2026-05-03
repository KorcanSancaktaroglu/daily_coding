Hash Tables & Hash Functions — Learning Journey

Course: Data Structures and Algorithms
Topic: Hash Tables, Hash Functions, Collision Resolution
Language: Python (concepts), C (implementation)


1. Theory
What is a Hash Table?
A hash function converts a key into a fixed-size index, allowing data to be stored and retrieved in average O(1) time.
"ali@test.com"  →  hash_fn()  →  index: 3  →  bucket[3]
Time Complexity Comparison
StructureSearchArray / ListO(n)BST / Binary SearchO(log n)Hash TableO(1) average
Core Concepts
TermDescriptionKeyThe identifier used to access data (ID number, email…)ValueThe actual data being storedBucketThe slot at each indexCollisionTwo different keys mapping to the same index

2. Hash Functions
Modulo Hash
pythondef hash_modulo(key: int, size: int) -> int:
    return key % size
String Hash — djb2
pythondef hash_string(key: str, size: int) -> int:
    h = 5381
    for char in key:
        h = (h * 33 + ord(char)) % size
    return h
Hash Function in C
cint hash_calc(const char* key) {
    int hash = 0;
    size_t len = strlen(key);
    for (size_t i = 0; i < len; i++) {
        hash = hash * 17 + key[i];
    }
    return hash % TABLE_SIZE;
}

Why 17? A prime multiplier produces uniform distribution and reduces clustering.
Why a prime table size? The modulo operation distributes keys more evenly across buckets.

Properties of a Good Hash Function

Deterministic: same key → always the same index
Uniform distribution: spreads keys evenly across all buckets
Fast: O(key length), independent of table size
Low collision rate: different keys should map to different indices


3. Collision Resolution
Chaining
When two keys land on the same index, that bucket holds a linked list.
pythonclass HashTable:
    def __init__(self, size=7):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def set(self, key, value):
        idx = self._hash(key)
        for i, (k, v) in enumerate(self.table[idx]):
            if k == key:
                self.table[idx][i] = (key, value)
                return
        self.table[idx].append((key, value))

    def get(self, key):
        idx = self._hash(key)
        for k, v in self.table[idx]:
            if k == key: return v
        return None

    def delete(self, key):
        idx = self._hash(key)
        self.table[idx] = [(k,v) for k,v in self.table[idx] if k != key]
Open Addressing — Linear Probing
On collision, place the element in the next available slot.
pythonclass OpenAddressHash:
    def __init__(self, capacity=11):
        self.capacity = capacity
        self.size     = 0
        self.keys     = [None] * capacity
        self.values   = [None] * capacity
        self.DELETED  = "__DELETED__"

    def _hash(self, key):
        return hash(key) % self.capacity

    def insert(self, key, value):
        if self.size / self.capacity >= 0.7:
            self._rehash()

        idx = self._hash(key)
        while self.keys[idx] not in (None, self.DELETED):
            if self.keys[idx] == key:
                self.values[idx] = value
                return
            idx = (idx + 1) % self.capacity

        self.keys[idx]   = key
        self.values[idx] = value
        self.size += 1

    def _rehash(self):
        old_keys, old_vals = self.keys, self.values
        self.capacity *= 2
        self.keys   = [None] * self.capacity
        self.values = [None] * self.capacity
        self.size   = 0
        for k, v in zip(old_keys, old_vals):
            if k and k != self.DELETED:
                self.insert(k, v)
Load Factor
load_factor = total_elements / table_size
RangeStatus< 0.5Good0.5 – 0.7Caution> 0.7Rehash required — performance degrades

4. Real-World Problem — Group Anagrams
Problem: ["eat","tea","tan","ate","nat","bat"] → [["eat","tea","ate"],["tan","nat"],["bat"]]
Key insight: Two words are anagrams if and only if their sorted characters produce the same string. Use that sorted string as the hash map key.
"eat" → sort → "aet"
"tea" → sort → "aet"  ← same key!
"tan" → sort → "ant"
pythonfrom collections import defaultdict

def group_anagrams(words: list[str]) -> list[list[str]]:
    groups = defaultdict(list)
    for word in words:
        key = "".join(sorted(word))
        groups[key].append(word)
    return list(groups.values())
Complexity: O(n · k log k) — n: number of words, k: length of the longest word

5. Assignment — University Library System (C)
Data Structure
c#define TABLE_SIZE 53

typedef struct StudentRecord {
    char student_id[12];        /* key */
    char full_name[50];
    char book_title[100];
    int  borrow_days;           /* how many days borrowed */
    struct StudentRecord* next; /* chaining pointer */
} StudentRecord;

StudentRecord* hashTable[TABLE_SIZE];

record_insert — Version History
❌ v1 — First attempt (3 bugs)
c/* BUG 1: new_rec->next never set to NULL
          → garbage pointer → infinite loop or crash
   BUG 2: hashTable[index] = new_rec missing
          → record is lost when no collision exists
   BUG 3: code duplication — strcpy block written twice */
❌ v2 — NULL check in wrong order
cStudentRecord* new_rec = (StudentRecord*)malloc(sizeof(StudentRecord));
new_rec->next = NULL;   /* WRONG ORDER — if malloc fails,
                           new_rec is NULL → crash here */
if (!new_rec) { ... }   /* check comes too late */
✅ v3 — Correct Version
cvoid record_insert(const char* student_id, char* full_name,
                   const char* book_title, int borrow_days) {

    int index = hash_calc(student_id);

    StudentRecord* new_rec = (StudentRecord*)malloc(sizeof(StudentRecord));
    if (!new_rec) {                         /* 1. check first */
        printf("Record could not be created\n");
        return;
    }
    new_rec->next = NULL;                   /* 2. then init pointer */
    strcpy(new_rec->student_id, student_id);
    strcpy(new_rec->full_name,  full_name);
    strcpy(new_rec->book_title, book_title);
    new_rec->borrow_days = borrow_days;     /* 3. fill data */

    if (hashTable[index] != NULL) {         /* 4. decide linkage */
        StudentRecord* temp = hashTable[index];
        while (temp->next) temp = temp->next;
        temp->next = new_rec;
    } else {
        hashTable[index] = new_rec;
    }
    printf("Record created successfully\n");
}
Golden Rule for malloc in C
malloc  →  NULL check  →  next = NULL  →  fill data  →  link

record_search — Version History
❌ v1 — First attempt (3 bugs)
c/* BUG 1: strcmp result inverted — returns 0 on match, 0 = false
          if (strcmp(...)) fires when keys DON'T match
   BUG 2: while(current->next) skips the last node entirely
   BUG 3: unnecessary if/else branch on next == NULL */
❌ v2 — strcmp fixed, if/else remains
c/* while(current) is correct but
   if(!current->next) / else branch adds needless complexity */
❌ v3 — if/else removed, new bug introduced
cwhile (current) { ... }
printf("Student %s not found\n", student_id);
/* found flag never checked — always prints "not found" */
❌ v4 — flag removed, found printf missing
cif (strcmp(current->student_id, student_id) == 0) {
    /* printf missing — exits silently on match */
    return;
}
✅ v5 — Correct Version
cvoid record_search(const char* student_id) {
    int index = hash_calc(student_id);
    StudentRecord* current = hashTable[index];

    while (current) {
        if (strcmp(current->student_id, student_id) == 0) {
            printf("Student %s found — %s | %s | %d days\n",
                   student_id, current->full_name,
                   current->book_title, current->borrow_days);
            return;   /* exit immediately on match */
        }
        current = current->next;
    }
    printf("Student %s not found\n", student_id);
}
Key Rules for record_search
strcmp == 0   →  keys are equal  (0 = false, never forget!)
while(current)  →  traverses the entire chain including the last node
return          →  cleaner exit than break + flag

record_delete — Correct Version
cvoid record_delete(const char* student_id) {
    int index = hash_calc(student_id);
    StudentRecord* prev   = NULL;
    StudentRecord* target = hashTable[index];

    /* 1. search the chain, tracking previous node */
    while (target) {
        if (strcmp(target->student_id, student_id) == 0) break;
        prev   = target;
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
        prev->next = target->next;        /* middle or tail node */

    /* 4. free memory */
    free(target);
    printf("Student %s deleted\n", student_id);
}
Three Cases in Delete
CaseActionTarget is the head nodehashTable[index] = target->nextTarget is middle / tailprev->next = target->nextNot foundprint error, return
Why is prev pointer essential?
Without tracking prev, deleting the head node leaves hashTable[index] pointing to freed memory — the record appears deleted but causes undefined behavior.
4-step pattern — same for every linked list delete:
search (track prev)  →  not found? return  →  detach  →  free

Complete Implementation
c#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 53

typedef struct StudentRecord {
    char student_id[12];
    char full_name[50];
    char book_title[100];
    int  borrow_days;
    struct StudentRecord* next;
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

void record_insert(const char* student_id, char* full_name,
                   const char* book_title, int borrow_days) {
    int index = hash_calc(student_id);
    StudentRecord* new_rec = (StudentRecord*)malloc(sizeof(StudentRecord));
    if (!new_rec) { printf("Record could not be created\n"); return; }

    new_rec->next = NULL;
    strcpy(new_rec->student_id, student_id);
    strcpy(new_rec->full_name,  full_name);
    strcpy(new_rec->book_title, book_title);
    new_rec->borrow_days = borrow_days;

    if (hashTable[index] != NULL) {
        StudentRecord* temp = hashTable[index];
        while (temp->next) temp = temp->next;
        temp->next = new_rec;
    } else {
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
    StudentRecord* prev   = NULL;
    StudentRecord* target = hashTable[index];
    while (target) {
        if (strcmp(target->student_id, student_id) == 0) break;
        prev   = target;
        target = target->next;
    }
    if (!target) { printf("Student %s not found\n", student_id); return; }
    if (prev == NULL) hashTable[index] = target->next;
    else              prev->next = target->next;
    free(target);
    printf("Student %s deleted\n", student_id);
}

int main(void) {
    record_insert("2021010034", "Ali Yilmaz",  "Algorithms",      5);
    record_insert("2021010087", "Ayse Kaya",   "Data Structures", 12);
    record_insert("2022050034", "Veli Demir",  "C Programming",   3);

    record_search("2021010034");
    record_search("9999999999");

    record_delete("2021010087");
    record_search("2021010087");

    return 0;
}

6. Pattern Recognition Guide
QuestionUse"Does it exist?"set"How many?" / "Frequency?"Counter / dict"What is the value for X?"dictReduce O(n²) → O(n)Hash almost always makes it possible

7. Key Takeaways

Hash tables provide average O(1) for insert, search, and delete — far faster than O(n) linear search
Use a prime multiplier and a prime table size for uniform key distribution
Collision is inevitable; resolve it with chaining or open addressing
When load factor exceeds 0.7, rehash to maintain performance
In C: malloc → NULL check → next = NULL → fill → link — never skip this order
Code duplication is a bug source — move shared blocks above branching logic
strcmp == 0 means equal — one of the most common C mistakes
while(current->next) skips the last node — always use while(current)
return is cleaner than break + flag for early exit
prev pointer is mandatory in linked list deletion — forgetting it causes memory leaks on head node removal
Every malloc must have a matching free — no exceptions
