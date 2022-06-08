#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100

typedef struct {
	char data[n];
	int top;
}stacktype;

void init(stacktype* s) {
	s->top = -1;
}

int isempty(stacktype* s) {
	return s->top == -1;
}

int isfull(stacktype* s) {
	return s->top == n - 1;
}

void push(stacktype* s, char e) {
	if (isfull(s)) {
		printf("Stack overflow\n");
	}
	else {
		s->top++;
		s->data[s->top] = e;
	}
}

char pop(stacktype* s) {
	if (isempty(s)) {
		printf("Stack is Empty\n");
		return -1;
	}
	else {
		char c;
		c = s->data[s->top];
		s->top--;
		return c;
	}
}

char peek(stacktype* s) {
	if (isempty(s)) {
		printf("Stack is Empty\n");
		return -1;
	}
	else {
		char c;
		c = s->data[s->top];
		return c;
	}
}

int pre(char data) {
	switch (data) {
	case '(':case')':
		return 0;
	case '+':case'-':
		return 1;
	case '*':case'/':
		return 2;
	}
}

int op(char c, char b, char a) {
	switch (c) {
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/':
			return b / a;
	}
}

int evaluate(char* postfix) {
	stacktype* s;
	init(&s);
	int i, a, b;
	char c;
	for (i = 0; i < strlen(postfix); i++) {
		c = postfix[i];
		if (c != '+' && c != '-' && c != '*' && c != '/') {
			push(&s, c-'0');
		}
		else {
			a = pop(&s);
			b = pop(&s);
			push(&s, op(c, b, a));
		}
	}
	return pop(&s);
}

void convert(char* infix, char* postfix) {
	stacktype s;
	init(&s);
	int i, j=0;
	char c, t;
	for (i = 0; i < strlen(infix); i++) {
		c = infix[i];
		if (c == '(') {
			push(&s, c);
		}
		else if (c == ')') {
			t = pop(&s);
			while (t != '(') {
				postfix[j++] = t;
				t = pop(&s);
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!isempty(&s) && (pre(c) <= pre(peek(&s))))
				postfix[j++] = pop(&s);
			push(&s, c);
		}
		else
			postfix[j++] = c;
	}
	while (!isempty(&s)) {
		postfix[j++] = pop(&s);
	}
	postfix[j] = '\0';
	printf("%s\n", postfix);
	printf("%d", evaluate(postfix));
}



int main() {

	char infix[n];
	char postfix[n];
	scanf("%s", infix);
	convert(infix, postfix);
	

	return 0;
}
