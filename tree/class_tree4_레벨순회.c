#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

#define N 10

typedef struct
{
	TreeNode* element[N];
	int front, rear;
}QueueType;

void init(QueueType* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
	return Q->rear == Q->front;
}

int isFull(QueueType* Q)
{
	return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, TreeNode* elem)
{
	if (isFull(Q))
		printf("FULL\n");
	else
	{
		Q->rear = (Q->rear + 1) % N;
		Q->element[Q->rear] = elem;
	}
}

TreeNode* dequeue(QueueType* Q)
{
	if (isEmpty(Q))
	{
		printf("EMPTY\n");
		return NULL;
	}
	Q->front = (Q->front + 1) % N;
	return Q->element[Q->front];
}

void levelOrder(TreeNode* root) {
	QueueType Q;
	init(&Q);

	enqueue(&Q, root);
	while (!isEmpty(&Q)) {
		root = dequeue(&Q);
		printf("%c ", root->data);
		if (root->left)
			enqueue(&Q, root->left);
		if (root->right)
			enqueue(&Q, root->right); 
	}
}

int main() {

	TreeNode* n9 = makeNode('I', NULL, NULL);
	TreeNode* n8 = makeNode('H', NULL, NULL);
	TreeNode* n7 = makeNode('G', NULL, NULL);
	TreeNode* n6 = makeNode('F', NULL, NULL);
	TreeNode* n5 = makeNode('E', n8, n9);
	TreeNode* n4 = makeNode('D', NULL, NULL);
	TreeNode* n3 = makeNode('C', n6, n7);
	TreeNode* n2 = makeNode('B', n4, n5);
	TreeNode* n1 = makeNode('A', n2, n3);

	TreeNode* root = n1;
	levelOrder(root); printf("\n");
	
	return 0;
}
	
