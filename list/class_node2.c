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

	return 0;
}
