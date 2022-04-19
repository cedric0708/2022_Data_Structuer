#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define size 3

typedef struct listnode {
	int elem;
	struct listnode* prev, * next;
}listnode;

void init(listnode* H[], listnode* T[]) {
	for (int i = 0; i < size; i++) {
		listnode* h = (listnode*)malloc(sizeof(listnode));
		listnode* t = (listnode*)malloc(sizeof(listnode));
		h->next = t;
		t->prev = h;
		H[i] = h;
		T[i] = t;
	}
}

void add(listnode* H[], int g, int e) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->prev = H[g];
	node->next = H[g]->next;
	H[g]->next->prev = node;
	H[g]->next = node;
}

void traverse(listnode* H[], listnode* T[]) {
	listnode* p;
	for (int i = 0; i < size; i++) {
		for (p = H[i]->next; p != T[i]; p = p->next)
			printf(" %d", p->elem);
		printf("\n");
	}
}



int main()
{
	listnode* h[size],* t[size];
	int g, e;

	init(h, t);

	for (int i = 1; i <= 6; i++) {
		scanf("%d %d", &g, &e);
		add(h, g, e);
		getchar();
	}

	traverse(h, t);


	return 0;
}
