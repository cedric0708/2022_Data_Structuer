#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 8

typedef struct {
	int element[size];
	int top;
}stacktype;

void init(stacktype* s) {
	s->top = -1;
}

int isempty(stacktype* s) {
	return s->top == -1;
}

int isfull(stacktype* s) {
	return s->top == size - 1;
}

void push(stacktype* s, int e) {
	if (isfull(s)) {
		printf("Stack Overflow\n");
		return;
	}
	else {
		s->top++;
		s->element[s->top] = e;
	}
}

int pop(stacktype* s) {
	if (isempty(s)) {
		printf("Stack is Empty\n");
		return;
	}

	return s->element[s->top--];
}

int peek(stacktype* s) {
	if (isempty(s)) {
		printf("Stack is Empty\n");
		exit(1);
	}

	return s->element[s->top];
}

void spans(stacktype* a, int x[], int s[]) {
	for (int i = 0; i < size; i++) {
		while (!isempty(a) && (x[peek(a)] <= x[i]))
			pop(a);
		if (isempty(a))
			s[i] = i + 1;
		else
			s[i] = i - peek(a);
		push(a, i);
	}
}

int main()
{
	stacktype a;
	init(&a);
	int x[size] = { 60,30,40,10,20,30,50,40 };
	int s[size];

	spans(&a, x, s);

	for (int i = 0; i < size; i++)
		printf("[%d] ", s[i]);
	printf("\n");

	return 0;
}
