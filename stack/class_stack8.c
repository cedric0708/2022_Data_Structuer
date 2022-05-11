#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15

typedef struct
{
	int A[N];
	int* b;
	int* t;

}Stack;

void initMultiStack(Stack* S, int n)
{
	int stacksize = N / n;
	S->b = (int*)malloc(sizeof(int) * (n + 1));
	S->t = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		S->b[i] = stacksize * i-1;
		S->t[i] = S->b[i];
	}
	S->b[n] = N - 1;
}

int size(Stack* S, int i)
{
	return S->t[i] - S->b[i];
}

int isEmpty(Stack* S, int i)
{
	return S->t[i] == S->b[i];
}

int isFull(Stack* S, int i)
{
	return S->t[i] == S->b[i+1];
}

void push(Stack* S, int i, int e)
{
	if (isFull(S, i))
	{
		printf("Stack Overflow\n");
		return;
	}

	S->t[i]++;
	S->A[S->t[i]] = e;
}

char pop(Stack* S, int i)
{
	if (isEmpty(S,i))
	{
		printf("Stack is Empty\n");
		return;
	}

	S->t[i]--;
	return S->A[S->t[i]+1];
}

char peek(Stack* S, int i)
{
	if (isEmpty(S, i))
	{
		printf("Stack is Empty\n");
		return;
	}

	return S->A[S->t[i]];
}

void printMultiStack(Stack* S, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Stack %d: ", i);
		for (int j = S->b[i] + 1; j <= S->t[i]; j++)
		{
			printf("[%d] ", S->A[j]);
		}
		printf("\n");
	}
}

int main()
{
	Stack S;
	int n;

	printf("다중 스택의 갯수 입력: ");
	scanf("%d", &n);
	initMultiStack(&S, n);

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		push(&S, rand() % 3, rand() % 50 + 10);
	printMultiStack(&S, n);
	printf("\n");

	int i;
	printf("POP 연산을 수행 할 스택 번호 입력: ");
	scanf("%d", &i);
	printf("%d가 POP\n", pop(&S, i));
	printf("\n");
	printMultiStack(&S, n);
}
