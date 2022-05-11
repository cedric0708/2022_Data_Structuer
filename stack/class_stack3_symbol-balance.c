#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 100

typedef struct stacknode{
	char data;
	struct stacknode* next;
}stacknode;

typedef struct {
	stacknode* top;
	int size;
}stacktype;

void init(stacktype* s) {
	s->top = NULL;
	s->size = 0;
}

int isempty(stacktype* s) {
	return s->size == 0;
}

void push(stacktype* s ,char e) {
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	node->data = e;
	node->next = s->top;
	s->top = node;
	s->size++;
}

char pop(stacktype* s) {
	if (isempty(s)) {
		printf("Stack Empty\n");
		return -1;
	}
	stacknode* p = s->top;
	char e = p->data;
	s->top = p->next;
	free(p);
	s->size--;
	return e;
}

char peek(stacktype* s) {
	if (isempty(s)) {
		printf("Stack Empty\n");
		return -1;
	}

	return s->top->data;
}


void print(stacktype* s) {
	for (stacknode *p= s->top; p!=NULL; p=p->next)
		printf("%c -> ", p->data);
	printf("NULL\n");
}

int check(char str[]) {
	stacktype s;
	init(&s);

	char c, t;
	int m = strlen(str);

	for (int i = 0; i < m; i++) {
		c = str[i];
		if (c == '(' || c=='{' || c=='[') {
			push(&s, c);
		}
		else if (c == ')' || c=='}' || c==']') {
			if (isempty(&s))
				return 0;
			else {
				t = pop(&s);
				if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']'))
					return 0;
			}		
		}
	}
	return isempty(&s);
}

int main()
{	
	char str[n];
	gets(str);

	if (check(str))
		printf("OK\n");
	else
		printf("FAIL\n");

	return 0;
}
