#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode {
	char data;
	struct treenode* left, * right;
}treenode;

treenode* makenode(char e, treenode* left, treenode* right) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->data = e;
	node->left = left;
	node->right = right;
	return node;
}

#define n 10

typedef struct {
	treenode* elem[n];
	int front, rear;
}queuetype;

void init(queuetype* q) {
	q->front = q->rear = 0;
}

int isempty(queuetype* q) {
	return q->front == q->rear;
}

int isfull(queuetype* q) {
	return (q->rear + 1) % n == q->front;
}

void inqueue(queuetype* q, treenode *elem) {
	if (isfull(q)) {
		printf("Full\n");
	}
	else {
		q->rear = (q->rear + 1) % n;
		q->elem[q->rear] = elem;
	}
}

treenode* dequeue(queuetype* q) {
	if (isempty(q)) {
		printf("Empty\n");
		return NULL;
	}
	else {
		q->front = (q->front + 1) % n;
		return q->elem[q->front];
	}
}

void levelorder(treenode* root) {
	queuetype q;
	init(&q);
	inqueue(&q, root);
	while (!isempty(&q)) {
		root = dequeue(&q);
		printf("%c ", root->data);
		if (root->left)
			inqueue(&q, root->left);
		if (root->right)
			inqueue(&q, root->right);
	}
}

int main()
{	
	treenode* n9 = makenode('I', NULL, NULL);
	treenode* n8 = makenode('H', NULL, NULL);
	treenode* n7 = makenode('G', NULL, NULL);
	treenode* n6 = makenode('F', NULL, NULL);
	treenode* n5 = makenode('E', n8, n9);
	treenode* n4 = makenode('D', NULL, NULL);
	treenode* n3 = makenode('C', n6, n7);
	treenode* n2 = makenode('B', n4, n5);
	treenode* n1 = makenode('A', n2, n3);

	levelorder(n1);

	return 0;
}
