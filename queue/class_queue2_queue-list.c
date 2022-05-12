#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct queuenode{
	char elem;
	struct queuenode* next;
}queuenode;

typedef struct {
	queuenode* front, * rear;
}queuetype;

void init(queuetype* q) {
	q->front = q->rear = NULL;
}

int isempty(queuetype* q) {
	return q->front==NULL;
}

void enqueue(queuetype* q, char elem) {
	queuenode* node = (queuenode*)malloc(sizeof(queuenode));
	node->elem = elem;
	node->next = NULL;
	
	if (isempty(q))
		q->front = q->rear = node;
	else {
		q->rear->next = node;
		q->rear = node;
	}
}

char dequeue(queuetype* q) {
	if (isempty(q)) {
		printf("EMPTY\n");
		return -1;
	}
	queuenode* p = q->front;
	char elem = p->elem;
	q->front = p->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(p);
	return elem;
}

int size(queuetype* q) {

	queuenode* p = q->front;
	int count = 0;
	for (; p != NULL; p = p->next)
		count++;
	return count;
}

void print(queuetype* q) {

	queuenode* p = q->front;
	for (; p != NULL; p = p->next)
		printf("[%c] => ", p->elem);
	printf("NULL\n");
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
