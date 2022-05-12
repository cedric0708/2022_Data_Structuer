#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct {
	char queue[N];
	int front;
	int rear;
}queuetype;

void init(queuetype* q) {
	q->front = q->rear = 0;
}

int isempty(queuetype* q) {
	return q->rear == q->front;
}

int isfull(queuetype* q) {
	return (q->rear + 1) % N == q->front;
}

void enqueue(queuetype* q, char elem) {
	if (isfull(q))
		printf("FULL\n");
	else {
		q->rear = (q->rear + 1) % N;
		q->queue[q->rear] = elem;
	}

}

char dequeue(queuetype* q) {
	if (isempty(q)) {
		printf("EMPTY\n");
		return -1;
	}
	q->front = (q->front + 1) % N;
	return q->queue[q->front];
}

char front(queuetype* q) {
	if (isempty(q)) {
		printf("EMPTY\n");
		return -1;
	}
	return q->queue[(q->front+1)%N];
}

void print(queuetype* q) {

	printf("Front pos : %d, Rear pos : %d\n", q->front, q->rear);
	int i = q->front;
	while (i != q->rear) {
		i = (i + 1) % N;
		printf("[%c] ", q->queue[i]);
	}
	printf("\n");
}

int main()
{
	queuetype q;
	init(&q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
		enqueue(&q, rand() % 26 + 65);
	print(&q); getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c] ", dequeue(&q));
	printf("\n\n");
	print(&q); getchar();

	printf("\n");
	for (int i = 0; i < 5; i++)
		enqueue(&q, rand() % 26 + 65);
	print(&q); getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c] ", dequeue(&q));
	printf("\n\n");
	print(&q); getchar();

	return 0;
}
