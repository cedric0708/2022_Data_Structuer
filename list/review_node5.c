#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define size 3

typedef struct listnode {
	int elem;
	struct listnode* prev, * next;
}listnode;//이중연결리스트

void init(listnode* H[], listnode* T[]) {
	for (int i = 0; i < size; i++) {
		listnode* h = (listnode*)malloc(sizeof(listnode));
		listnode* t = (listnode*)malloc(sizeof(listnode));
		h->next = t;
		t->prev = h;
		H[i] = h;
		T[i] = t;
	}
}//초기화

void add(listnode* H[], int g, int e) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->prev = H[g];
	node->next = H[g]->next;
	H[g]->next->prev = node;
	H[g]->next = node;
}//노드 추가

void traverse(listnode* H[], listnode* T[]) {
	for (int i = 0; i < size; i++) {
		listnode* p = H[i]->next;
		for (; p != T[i]; p = p->next)
			printf(" %d", p->elem);
		printf("\n");
	}
}//출력



int main()
{
	listnode* h[size], * t[size];
	int g, e;

	init(h, t);
	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		g = rand() % 3;
		e = rand() % 100;
		add(h, g, e);
	}

	traverse(h, t);


	return 0;
}
