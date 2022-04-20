#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dlistnode {
	char data;
	struct dlistnode* prev, * next;
}dlistnode;

void init(dlistnode* h, dlistnode* t) {
	h->next = t;
	t->prev = h;
}

int count(dlistnode* h, dlistnode* t) {
	int n=0;
	for (dlistnode* p = h->next; p != t; p = p->next) {
		n++;
	}

	return n;
}

void add(dlistnode* h, int pos, char e) {
	dlistnode* p = h;
	for (int i = 1; i < pos; i++)
		p = p->next;

	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	node->data = e;
	node->prev = p;
	node->next = p->next;
	p->next->prev = node;
	p->next = node;
}

void delete(dlistnode* h, int pos) {
	dlistnode* p = h;
	for (int i = 1; i <= pos; i++)
		p = p->next;
	char e = p->data;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void get(dlistnode* h, int pos) {
	dlistnode* p = h;
	int i;

	for (i = 0; i < pos; i++) {
		p = p->next;
	}
	char e = p->data;

	printf("%c\n", e);
}

void print(dlistnode* h, dlistnode* t) {
	for (dlistnode* p = h->next; p != t; p = p->next) {
		printf("%c", p->data);
	}
	printf("\n");
}

int main()
{
	dlistnode* h = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* t = (dlistnode*)malloc(sizeof(dlistnode));

	init(h, t);

	int x, i;
	char a, b;
	int c, num;

	

	scanf("%d", &x);
	getchar();

	for (i = 0; i < x; i++) {
		num = count(h, t);
		scanf("%c", &a);
		getchar();
		if (a == 'A') {
			scanf("%d %c", &c, &b);
			getchar();
			if (c<1||c>num+1)
				printf("invalid position\n");
			else
				add(h, c, b);
		}
		else if (a == 'D') {
			scanf("%d", &c);
			getchar();
			if (c<1 || c>num)
				printf("invalid position\n");
			else
				delete(h, c);
		}
		else if (a == 'G') {
			scanf("%d", &c);
			getchar();
			if (c<1 || c>num)
				printf("invalid position\n");
			else
				get(h, c);
		}
		else if (a == 'P') {
			print(h, t);
		}
	}



	return 0;
}
