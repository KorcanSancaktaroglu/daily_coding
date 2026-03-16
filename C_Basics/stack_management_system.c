#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct stack {
    int value;
    struct stack* prev;
}stack;
void push(stack** top);
int pop(stack** top);
void reset(stack** top);
void display(stack* top);

int main()
{
    stack* top = NULL; int choice;
    do {
        system("cls");
        printf("=== STACK MANAGEMENT SYSTEM ===\n");
        printf("Top Address: %p\n", (void*)top);
        printf("-------------------------------\n");
        printf("1 - Push (Add)\n");
        printf("2 - Pop (Remove)\n");
        printf("3 - Reset (Clear All)\n");
        printf("4 - Display (List)\n");
        printf("5 - Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1: {
            push(&top);
            break;
        }
        case 2: {
            int poppedValue = pop(&top);
            if (poppedValue != -1) printf("Popped Value:%d", poppedValue);
            system("pause");
            break;

        }
        case 3: {
            reset(&top);
            break;

        }
        case 4 : {
            display(top);
            break;


        }
        case 5:
        {
            reset(&top);
            printf("\nExiting program...\n");
            
            return 0;
        }






        }
    } while (choice>=1 && choice<=5);
    return 0;
}

void push(stack** top) {
    stack* newNode = (stack*)malloc (sizeof(stack));
    if (!newNode) {
        printf("\nMemory Allocation Error!\n"); return;
    }

    printf("Enter Value to push:"); scanf("%d", &newNode->value);

    newNode->prev = *top;
    *top = newNode;
    printf("Value added successfully.\n");
    system("pause");


}
int pop(stack** top) {
    if (!(*top) || !top) {
        printf("\nError: Stack Underflow (Empty)!\n"); return -1;
    }
    stack* temp = *top;

    int data = temp->value;
    *top = (*top)->prev;
    free(temp); temp = NULL;
    return data;
}
void reset(stack** top) {
    if (!top) return;
    while (*top) {
        stack* temp = *top;
        *top = (*top)->prev;
        free(temp);

    }
    *top = NULL;
    printf("\nStack has been reset.\n");
    system("pause");
}
void display(stack* top) {
    if (!top) { printf("\nStack is currently empty.\n"); return; }
    printf("\n--- CURRENT STACK STATE ---\n");
    stack* curr = top;
    while (curr) {
        if (curr == top) printf("[TOP] -> %d\n", curr->value);
        else printf("         %d\n", curr->value);

        if (curr->prev) printf("          |\n");
        curr = curr->prev;
    }
    printf("      [BOTTOM]\n");
    system("pause");
}


