#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 100

typedef struct {
	char data[size];
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

void push(stacktype* s, char e) {
	if (isfull(s))
		printf("Stack Full\n");
	else {
		s->top++;
		s->data[s->top] = e;
	}
}

char pop(stacktype* s) {
	if (isempty(s)) {
		printf("Stack Empty\n");
		return -1;
	}

	char e = s->data[s->top];
	s->top--;
	return e;
}

char peek(stacktype* s) {
	if (isempty(s)) {
		printf("Stack is Empty\n");
		return -1;
	}

	return s->data[s->top];
}

int prec(char op) {
	switch (op) {
	case '(' : case')':
		return 0;
	case '+':case'-':
		return 1;
	case '*':case'/':
		return 2;
	}
}

void convert(char* infix) {
	stacktype s;
	init(&s);
	char c, t;
	int n = strlen(infix);

	for (int i = 0; i < n; i++) {
		c = infix[i];
		switch (c) {
		case '+':case '-': case'*':case'/':
			while (!isempty(&s) && (prec(c) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, c);
			break;
		case '(':
			push(&s, c);
			break;
		case ')':
			t = pop(&s);
			while (t != '(') {
				printf("%c", t);
				t = pop(&s);
			}
			break;
		default:
			printf("%c", c);
			break;
		}
	}
	while (!isempty(&s))
		printf("%c", pop(&s));
	printf("\n");
}

int main()
{
	char infix[size];
	scanf("%s", infix);
	convert(infix);

	return 0;
}
