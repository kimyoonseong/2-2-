#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// Error Handling
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Queue initialization
void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;

	printf("Q is initialized!!\n");
}

// Check if queue is empty
int is_empty(QueueType* q)
{
	if (q->front == -1 && q->rear == -1)
		return 1;
	else
		return 0;
}

// Check if queue is full
int is_full(QueueType* q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}

int get_count(QueueType* q, int x)
{
	
	int count = 0;
	if (is_empty(q)) {
		return -1;
	}
	
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			if (x == q->data[i]) count++;
			//printf("%d\n", count);
		}
	
	
	return count;
}
// Add an item into queue
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		printf("Queue is full!!");
		return;
	}

	// if queue is empty (i.e. front == rear == -1)
	if (is_empty(q)) {
		q->front += 1;
		q->rear += 1;
	}

	// if there are more than or equal to one item in queue
	else
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	q->data[q->rear] = item;
	// q->data[++(q->rear)] = item; 
}


// Remove and return an item from queue
element dequeue(QueueType* q)
{
	element item;

	if (is_empty(q)) {
		printf("Queue is empty!!");
		return -1;
	}

	item = q->data[q->front];
	// int item = q->data[++(q->front)];

	// if there is only one item in queue (i.e., front == rear)
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}

	// if there are more than or equal to two items in queue 
	else
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	return item;
}

// Check the item in the front
element peek(QueueType* q)
{
	if (is_empty(q))
		printf("Q is empty!!");

	return q->data[q->front];
}


int main(void)
{
	QueueType queue;
	int x,y,z;
	
	init_queue(&queue);

	printf("== Data Input ==\n");
	
	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);
	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);
	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);
	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);
		

	y = dequeue(&queue);
	printf("Dequeued item: %d \n", y);

	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);

	y = dequeue(&queue);
	printf("Dequeued item: %d \n", y);

	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);

	printf("Enter an integer: ");
	scanf("%d", &x);
	enqueue(&queue, x);

	
	z=get_count(&queue, 3);
	printf("3의 갯수는:%d\n", z);

	z=get_count(&queue, 7);
	printf("7의 갯수는:%d\n", z);
	
	return 0;
}