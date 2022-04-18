#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct dlistnode {
	int elem;
	char group;
	struct dlistnode* prev, * next;
}dlistnode;

void init(dlistnode* h, dlistnode* t) {
	h->next = t;
	t->prev = h;
}

void addnode(dlistnode* p, int e, char c) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	node->elem = e;
	node->group = c;
	node->prev = p->prev;
	node->next = p;
	p->prev->next = node;
	p->prev = node;
}

void add(dlistnode* h, int r, int e, char c) {
	dlistnode* p = h;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	addnode(p, e, c);
}

void removenode(dlistnode* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void removegroup(dlistnode* h, dlistnode* t, char g) {
	dlistnode* p = h->next;
	for (; p != t; p = p->next) {
		if (p->group == g)
			removenode(p);
	}
}

void traversegroup(listnode* h, listnode* t, char g)
{
	listnode* p = h->next;
	printf("group %c",g);
	for (; p != t; p = p->next)
		if(p->group == g)
			printf(" [%d]", p->elem);
	printf("\n");

}

void traverse(dlistnode* h, dlistnode* t) {
	dlistnode* p = h->next;
	printf(" elem  group\n============\n");
	for (; p != t; p = p->next)
		printf(" [%2d]   [%c]\n", p->elem, p->group);
	printf("\n");
}

int main()
{
	dlistnode* h = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* t = (dlistnode*)malloc(sizeof(dlistnode));

	init(h, t);
	srand(time(NULL));

	char g[5] = { 'A', 'B', 'C', 'D', 'E' };
	for (int i = 1; i <= 10; i++) {
		int e = rand() % 100;
		char c = g[rand() % 5];
		add(h, i, e, c);
	}

	traverse(h, t);

	printf("Remove Group Name : ");
	char d;
	scanf("%c", &d);
	removegroup(h, t, d);
	traverse(h, t);

	return 0;
}
