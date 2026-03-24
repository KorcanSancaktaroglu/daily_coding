#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 10

void enqueue();
void dequeue();
void display();

int Q[SIZE];
int front = -1, rear = -1;

int main() {
    setlocale(LC_ALL, "turkish");
    int choice;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nYour Choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: 
                printf("Exiting Menu...\n"); 
                system("pause"); 
                exit(0); 
            default: 
                printf("Invalid Choice!"); 
                system("pause"); 
                break;
        }
    }
    return 0;
}

void enqueue() {
    if (rear == SIZE - 1) {
        printf("Error: Queue Full!\n");
        system("pause");
        return;
    }
    
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);

    if (front == -1) {
        front = 0;
    }
    
    rear++;
    Q[rear] = data;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue Empty!\n");
        front = rear = -1;
        system("pause");
        return;
    }
    
    printf("Dequeued data: %d\n", Q[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    
    printf("Queue Content: ");
    for (int i = front; i <= rear; i++) {
        printf("[%d] ", Q[i]);
    }
    printf("\n");
}
