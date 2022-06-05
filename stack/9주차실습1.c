#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	char data[100];
	int top;

}stacktype;

void init(stacktype* s) {
	s->top = -1;
}

int isempty(stacktype* s) {
	return s->top == -1;
}

int isfull(stacktype* s, int n) {
	return s->top == n - 1;
}

void push(stacktype* s, char e, int n) {
	if (isfull(s, n)) {
		printf("Stack FULL\n");
	}
	else {
		s->top ++;
		s->data[s->top] = e;
	}
}

void pop(stacktype* s) {
	if (isempty(s)) {
		printf("Stack Empty\n");
	}
	else {
		s->top--;
	}
}

void peek(stacktype* s) {
	if (isempty(s)) {
		printf("Stack Empty\n");
	}
	else {
		printf("%c\n", s->data[s->top]);
	}
}

void duplicate(stacktype* s, int n) {
	if (isfull(s, n)) {
		printf("Stack FULL\n");
	}
	else {
		char e = s->data[s->top];
		push(s, e, n);
	}
}

void uprotate(stacktype* s, int m) {
	int t = s->top;
	if (m <= t + 1) {
		char tmp = s->data[t];
		for (int i = 1; i < m; i++) {
			s->data[t] = s->data[t - 1];
			t--;
		}
		s->data[t] = tmp;
	}
}

void downrotate(stacktype* s, int m) {
	int t = s->top;
	if (m <= t + 1) {
		char tmp = s->data[t - m + 1];
		for (int i = t-m+1; i < t; i++) {
			s->data[i] = s->data[i + 1];
		}
		s->data[t] = tmp;
	}
}

void print(stacktype* s) {
	for (int i = s->top; i >= 0; i--)
		printf("%c", s->data[i]);
	printf("\n");
}

int main() {

	stacktype s;
	init(&s);
	int n, a, i;
	char ch[6];
	scanf("%d", &n);
	getchar();
	scanf("%d", &a);
	getchar();
	for (i = 0; i < a; i++) {
		scanf("%s", ch);
		getchar();
		if (strcmp(ch, "POP") == 0) {
			pop(&s);
		}
		else if (strcmp(ch, "PUSH") == 0) {
			char c;
			scanf("%c", &c);
			getchar();
			push(&s, c, n);
		}
		else if (strcmp(ch, "PEEK") == 0) {
			peek(&s);
		}
		else if (strcmp(ch, "DUP") == 0) {
			duplicate(&s, n);
		}
		else if (strcmp(ch, "UpR") == 0) {
			int t;
			scanf("%d", &t);
			getchar();
			uprotate(&s, t);
		}
		else if (strcmp(ch, "DownR") == 0) {
			int t;
			scanf("%d", &t);
			getchar();
			downrotate(&s, t);
		}
		else if (strcmp(ch, "PRINT") == 0) {
			print(&s);
		}
	}

	return 0;
}
