#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define size 3

typedef struct dlistnode {
	int elem;
	struct dlistnode* prev, * next;
}dlistnode;

void init(dlistnode* H[], dlistnode* T[]) {
	for (int i = 0; i < size; i++) {
		dlistnode* h = (dlistnode*)malloc(sizeof(dlistnode));
		dlistnode* t = (dlistnode*)malloc(sizeof(dlistnode));
		h->next = t;
		t->prev = h;
		H[i] = h;
		T[i] = t;
	}
}

void add(dlistnode* H[], int g, int e) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	node->elem = e;
	node->prev = H[g];
	node->next = H[g]->next;

	H[g]->next->prev = node;
	H[g]->next = node;
}


void traverse(dlistnode* H[], dlistnode* T[]) {
	for (int i = 0; i < size; i++) {
		printf("GROUP %d : ", i);
		dlistnode* p = H[i]->next;
		for (; p != T[i]; p = p->next)
			printf("%d <=> ", p->elem);
		printf("\b\b\b\b   \n");
	}
}

int main()
{
	dlistnode* h[size], * t[size];

	init(h, t);
	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		int g = rand() % 3;
		int e = rand() % 100;
		add(h, g, e);
	}

	traverse(h, t);


	return 0;
}
