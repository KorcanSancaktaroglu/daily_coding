#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>



typedef struct Q {
	int front, rear, size;
	unsigned capacity;
	int* arr;

}Q;
Q* createQueue(unsigned capacity);
void destroyQueue(Q* q);
int  isEmpty(Q* q);
int isFull(Q* q);
void enqueue(Q* q, int item);
int dequeue(Q* q);
int getFront(Q* q);
int getRear(Q* q);
void display(Q* q);
int main()
{
	setlocale(LC_ALL, "turkish");
	int capacity;
	printf("Enter capacity to queue:"); scanf("%d", &capacity);
	Q* q = createQueue(capacity);

	enqueue(q, 10); 
	enqueue(q, 20);
	enqueue(q, 30);

	dequeue(q);
	display(q);

	enqueue(q, 40);
	display(q);
	destroyQueue(q);




   return 0;
}
Q* createQueue(unsigned capacity) {
	Q* q = (Q*)malloc(sizeof(Q));
	q->front = q->size = 0;
	q->capacity = capacity;
	q->rear = capacity - 1;

	q->arr = (int*)calloc(capacity, sizeof(int));
	return q;

}
void destroyQueue(Q* q) {
	if (!q) {
		printf("Error\n");
		return;
	}
	free(q->arr);
	free(q);
	printf("Memory Deallocated\n");

}
int  isEmpty(Q* q) {
	return q->size == 0;
}
int isFull(Q* q) {
	return q->size == q->capacity;
}
void enqueue(Q* q,int item) {
	if (isFull(q)) {
		printf("Error: %d cannot be added ,Queue is full!", item);
		system("pause");
		return;

	}
	q->rear = (q->rear + 1) % q->capacity;
	q->arr[q->rear] = item;
	q->size += 1;
	printf("---> %d enqueued to queue\n", item);
	system("pause");
}
int dequeue(Q* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		system("pause");
		return INT_MIN;
	}
	int item = q->arr[q->front];
	q->arr[q->front] = 0;
	q->front = (q->front + 1) % q->capacity;
	q->size -= 1;
	printf("<<--- %d dequeued from queue\n", item);
	system("pause");
	return item;
}
int getFront(Q* q) {
	if (isEmpty(q)) return INT_MIN;
	return q->arr[q->front];
}
int getRear(Q* q) {
	if (isEmpty(q)) return INT_MIN;
	return q->arr[q->rear];
}
void display(Q* q) {
	if (isEmpty(q)) return;

	printf("\n");
	for (int i = 0; i < q->capacity * 13; i++) printf("=");
	printf("\n==== QUEUE INFO====\n");
	printf("Front Index: %d, Rear Index: %d, Size: %d, Capacity: %d\n",
		q->front, q->rear, q->size, q->capacity);
	printf("Front Item: %d, Rear Item: %d\n", getFront(q), getRear(q));
	printf("-- Array Content --\n");
	for (int i = 0; i < (int)q->capacity; i++) {
		printf("|%3d. - %3d| ", i, q->arr[i]);
	}
	printf("\n");
	for (int i = 0; i < (int)q->capacity; i++) {
		if (i == q->front && i == q->rear) printf("     F/R     ");
		else if (i == q->front) printf("      F      ");
		else if (i == q->rear) printf("      R      ");
		else printf("             ");
	}
	printf("\n");
	for (int i = 0; i < (int)q->capacity * 13; i++) printf("~");
	printf("\n");
}




