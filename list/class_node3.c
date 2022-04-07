#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dlistnode {
	char data;
	struct dlistnode* prev, * next;
}dlistnode;

typedef struct {
	dlistnode* h;
}dlisttype;

void init(dlisttype* dl) {
	dl->h = NULL;
}

void insertfirst(dlisttype* dl, char e) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* p = dl->h;
	node->data = e;
	node->prev = NULL;
	node->next = p;
	dl->h = node;

	if (p)
		p->prev = node;
}

void insert(dlisttype* dl, int pos, char e) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* p = dl->h;

	if (pos == 1)
		insertfirst(dl, e);
	else {
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		node->data = e;
		node->prev = p->prev;
		node->next=p;
		node->prev->next = node;
		p->prev = node;
	}
}

void print(dlisttype* dl) {
	for (dlistnode* p = dl->h; p != NULL; p = p->next) {
		printf("[%c] <=> ", p->data);
	}
	printf("\b\b\b\b   \n");
 }

int main()
{
	dlisttype dl;
	init(&dl);

	insertfirst(&dl, 'A'); print(&dl);
	insertfirst(&dl, 'B'); print(&dl);
	insertfirst(&dl, 'C'); print(&dl);

	insert(&dl, 2, 'D'); print(&dl);
	insert(&dl, 1, 'E'); print(&dl);
	insert(&dl, 3, 'F'); print(&dl);

	return 0;
}
