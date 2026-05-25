#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 5

void enqueue();
void dequeue();
void display();


int Q[SIZE];
int front = -1;
int rear = -1;

int main()
{
    setlocale(LC_ALL, "turkish");
    int choice;
    while (1) {
        printf("\nIndices: [Front: %d] - [Rear: %d]\n", front, rear);
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
        case 1:enqueue(); break;
        case 2:dequeue(); break;
        case 3: display(); break;
        case 4: printf("Menu is closing\n"); system("pause"); exit(0);
        default:printf("Invalid Choice!\n"); system("pause"); break;

        }
    }
    return 0;
}
void enqueue(){
    if ((rear + 1) % SIZE == front) {
        printf("Error: Queue Full!\n");
        return;
    }
    int value;
    printf("Enter data to enqueue"); scanf("%d", &value);
    if (front == -1) front= 0;

    rear = (rear + 1) % SIZE;
    Q[rear] = value;
    printf("Inserted [%d]\n",value);


}
void dequeue() {
    if (front == -1) {
        printf("Error: Queue Empty!\n");
        return;
    }
    printf("Dequeued: [%d]\n", Q[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    int i = front;
    while (1) {
        printf("[%d]", Q[i]);
        if (front == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

