#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct StackNode
{
	char elem;
	struct StackNode* next;

}StackNode;

typedef struct
{
	StackNode* top;

}Stack;

void init(Stack* S)
{
	for (int i = 0; i < 3; i++)
		S[i].top = NULL;
}

int isEmpty(Stack* S, int i)
{
	return S[i].top == NULL;
}

void push(Stack* S, char c, int i)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->elem = c;
	node->next = S[i].top;
	S[i].top = node;
}

char pop(Stack* S, int i)
{
	if (isEmpty(S, i))
		return;

	StackNode* p = S[i].top;
	char c = p->elem;
	S[i].top = p->next;
	free(p);
	return c;
}

void printStack(Stack* S)
{
	StackNode* p;
	for (int i = 0; i < 3; i++)
	{
		printf("Stack %d: ", i);
		for (p = S[i].top; p != NULL; p = p->next)
		{
			printf("[%c] ", p->elem);
		}
		printf("\n");
	}
}

int main()
{
	Stack* S[3];
	init(S);
	srand(time(NULL));

	for (int i = 0; i < 15; i++)
	{
		push(S, rand() % 26 + 65, rand() % 3);
		//if (i % 4 == 0)
		//{
			//printStack(S);
			//printf("\n");
		//}
	}
	printStack(S); printf("\n");

	for (int i = 0; i < 5; i++)
	{
		int idx = rand() % 3;
		printf("[S[%d] - %c] ", idx, pop(S, idx));
	}
	printf("\n\n");
	printStack(S);
}
