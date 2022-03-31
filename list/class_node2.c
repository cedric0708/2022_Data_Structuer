#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Listnode {
	char elem;
	struct Listnode* next;
}Listnode;

typedef struct {
	Listnode* h;
}Listtype;

void init(Listtype* l) {
	l->h = NULL;
}

void insertfirst(Listtype* l, char c) {
	Listnode* node = (Listnode*)malloc(sizeof(Listnode));
	node->elem = c;
	node->next = l->h;
	l->h = node;
}

void insertlast(Listtype* l, char c) {
	Listnode* node = (Listnode*)malloc(sizeof(Listnode));
	node->elem = c;
	node->next = NULL;

	Listnode* p = l->h;
	if (p == NULL)
		l->h = node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}

void insert(Listtype* l, int pos, char c) {
	Listnode* node = (Listnode*)malloc(sizeof(Listnode));
	Listnode* p=l->h;

	if (pos == 1)
		insertfirst(l, c);
	else {
		for (int i = 1; i < pos - 1; i++)
			p = p->next;
		node->elem = c;
		node->next = p->next;
		p->next = node;
	}
}

char deletefirst(Listtype* l) {
	Listnode* p = l->h;
	char c = p->elem;
	l->h = p->next;
	free(p);
	return c;
}

char deletelast(Listtype* l) {
	Listnode* p = l->h;
	Listnode* q = p;

	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	char c = p->elem;
	q->next = NULL;
	free(p);
	return c;
}

char delete(Listtype* l, int pos) {
	Listnode* p = l->h;
	Listnode* q = p;

	if (pos == 1)
		return deletefirst(l);
	else {
		for (int i = 1; i <= pos-1; i++) {
			q = p;
			p = p->next;
		}
		char c = p->elem;
		q->next = p->next;
		free(p);
		return c;
	}
}

void partition(Listtype* l, Listtype* l1, Listtype* l2, int pos) {
	Listnode* p = l->h;
	l1->h = p;
	for (int i = 1; i < pos; i++)
		p = p->next;

	l2->h = p->next;
	p->next = NULL;
}

void concat(Listtype* l1, Listtype* l2) {

}

void print(Listtype* l) {
	for (Listnode* p = l->h; p != NULL; p=p->next) {
		printf("%c -> ", p->elem);
	}
	printf("\b\b\b  \n");
}

int main()
{
	Listtype l;
	init(&l);

	insertlast(&l, 'D'); print(&l);
	insertlast(&l, 'E'); print(&l);
	insertlast(&l, 'F'); print(&l);
	getchar();

	insertfirst(&l, 'A'); print(&l);
	insertfirst(&l, 'B'); print(&l);
	insertfirst(&l, 'C'); print(&l);
	getchar();

	insert(&l, 2, 'G'); print(&l);
	insert(&l, 4, 'H'); print(&l);
	insert(&l, 6, 'I'); print(&l);
	getchar();

	printf("%c\n", deletefirst(&l)); print(&l);
	deletelast(&l); print(&l);
	delete(&l, 3); print(&l);

	Listtype l1, l2;
	int pos;
	printf("Partition position : ");
	scanf("%d", &pos);

	partition(&l, &l1, &l2, pos);
	print(&l1); print(&l2);
	getchar(); getchar();

	concat(&l1, &l2); print(&l1);

	return 0;
}
