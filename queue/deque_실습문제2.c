#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queuenode{
	int data;
	struct queuenode* next;
}queuenode;

typedef struct {
	queuenode* front, * rear;
}queuetype;

void init(queuetype* q) {
	q->front = q->rear = NULL;
}

int isempty(queuetype* q) {
	return q->front == NULL;
}

void addfront(queuetype* q, int e) {
	queuenode* node = (queuenode*)malloc(sizeof(queuenode));
	node->data = e;
	if (isempty(q)) {
		q->front = q->rear = node;
		node->next = NULL;
	}
	else {
		node->next = q->front;
		q->front = node;
	}
}

void addrear(queuetype* q, int e) {
	queuenode* node = (queuenode*)malloc(sizeof(queuenode));
	node->data = e;
	if (isempty(q)) {
		q->front = q->rear = node;
		node->next = NULL;
	}
	else {
		q->rear->next = node;
		q->rear = node;
		node->next = NULL;
	}
}

void deletefront(queuetype* q) {
	queuenode* p = q->front;
	if (p->next == NULL) {
		free(p);
		q->front = q->rear = NULL;
	}
	else {
		q->front = p->next;
		free(p);
	}
}

void deleterear(queuetype* q) {
	queuenode* p = q->rear;
	if (q->front == q->rear) {
		free(p);
		q->front = q->rear = NULL;
	}
	else {
		queuenode* pp = q->front;
		while (pp->next != q->rear)
			pp = pp->next;
		q->rear = pp;
		pp->next = NULL;
		free(p);
	}
}

void print(queuetype* q) {
	for (queuenode* p = q->front; p != NULL; p = p->next) {
		printf(" %d", p->data);
	}
	printf("\n");
}

int main()
{	
	int n, i, d;
	char ch[3];

	queuetype q;
	init(&q);

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%s", ch);
		getchar();
		if (strcmp(ch, "AF") == 0) {
			scanf("%d", &d);
			getchar();
			addfront(&q, d);
		}
		else if (strcmp(ch, "AR") == 0) {
			scanf("%d", &d);
			getchar();
			addrear(&q, d);
		}
		else if (strcmp(ch, "DF") == 0) {
			if (isempty(&q)) {
				printf("underflow");
				break;
			}
			else {
				deletefront(&q);
			}
		}
		else if (strcmp(ch, "DR") == 0) {
			if (isempty(&q)) {
				printf("underflow");
				break;
			}
			else {
				deleterear(&q);
			}
		}
		else if (strcmp(ch, "P") == 0) {
			print(&q);
		}
	}

	return 0;
}
