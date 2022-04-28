#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void push(stacktype* s ,char e) {
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
		printf("Stack Empty\n");
		return -1;
	}

	return s->data[s->top];
}

void dupilcate(stacktype* s) {
	char temp = peek(s);
	if (temp != -1)
		push(s, temp);
}

void uprotate(stacktype* s, int m) {
	int t = s->top;
	if (m <= t + 1) {
		char temp = s->data[t];
		for (int i = 1; i < m; i++) {
			s->data[t] = s->data[t - 1];
			t--;
		}
		s->data[t] = temp;
	}
}
void downrotate(stackType* s, int m)
{
    int t = s->top;
    if(m <= t+1)
    {
        char temp = s->data[t-m+1];
        for(int i = t-m+1; i < t; i++)
            s->data[i] = s->data[i+1];
       
        s->data[t] = temp;
    }
}


void print(stacktype* s) {
	for (int i = s->top; i >= 0; i--)
		printf("%c", s->data[i]);
	printf("\n");
}

int main()
{
	stacktype* s;
	init(&s);

	pop(&s);

	return 0;
}
