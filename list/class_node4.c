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
	dlistnode* t;
}dlisttype;

void init(dlisttype* dl) {
	dl->h = dl->t = NULL;
}

void insertfirst(dlisttype* dl, char c) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* p = dl->h;
	node->data = c;
	node->prev = node->next = NULL;

	if (p == NULL)
		dl->h = dl->t = node;
	else {
		node->next = p;
		p->prev = node;
		dl->h = node;
	}

}

void insertlast(dlisttype* dl, char c) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* p = dl->t;
	node->data = c;
	node->prev = node->next = NULL;

	if (p == NULL)
		dl->h = dl->t = node;
	else {
		node->prev = p;
		p->next = node;
		dl->t = node;
	}

}

void insert(dlisttype* dl, int pos, char c) {
	dlistnode* node = (dlistnode*)malloc(sizeof(dlistnode));
	dlistnode* p = dl->h;

	if (pos == 1)
		insertfirst(dl, c);
	else {
		for (int i = 1; i < pos - 1; i++) {
			p = p->next;
		}
		node->data = c;
		node->prev = p;
		node->next = p->next;

		if (p->next == NULL) {
			p->next = node;
			dl->t = node;
		}
		else {
			p->next->prev = node;
		}
	}
}

char deletefirst(dlisttype* dl) {
	dlistnode* p = dl->h;
	char c = p->data;

	if (p->next == NULL)
		dl->h = dl->t = NULL;
	else {
		p->next->prev = NULL;
		dl->h = p->next;
	}
	free(p);
	return c;
}

char deletelast(dlisttype* dl) {
	dlistnode* p = dl->h;
	char c = p->data;

	if (p->next == NULL)
		dl->h = dl->t = NULL;
	else {
		p->prev->next= NULL;
		dl->t = p->prev;
	}
	free(p);
	return c;
}

char delete(dlisttype* dl, int pos) {
	dlistnode* p = dl->h;
	char c;

	if (pos == 1)
		c = deletefirst(dl);
	else {
		for (int i = 1; i < pos; i++)
			p = p->next;

		if (p->next == NULL)
			c = deletelast(dl);
		else {
			c = p->data;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
		}
	}
	return c;
}

void printforward(dlisttype* dl) {
	for (dlistnode* p = dl->h; p != NULL; p = p->next)
		printf("[%c] <=> ", p->data);
	printf("\b\b\b\b   \n");
}

void printbackward(dlisttype* dl) {
	for (dlistnode* p = dl->t; p != NULL; p = p->prev)
		printf("[%c] <=> ", p->data);
	printf("\b\b\b\b   \n");
}

int main()
{
	dlisttype dl;
	init(&dl);

	insertfirst(&dl, 'A'); insertfirst(&dl, 'B');
	printforward(&dl); printbackward(&dl);

	insertlast(&dl, 'C'); insertlast(&dl, 'D');
	printforward(&dl); printbackward(&dl);

	insert(&dl, 1, 'E'); insert(&dl, 3, 'F');
	printforward(&dl); printbackward(&dl);
	getchar();

	deletefirst(&dl); printforward(&dl);
	delete(&dl, 3); printforward(&dl);



	return 0;
}
