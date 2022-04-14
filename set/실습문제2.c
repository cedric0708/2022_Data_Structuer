#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct setnode {
	int data;
	struct setnode* next;
}setnode;

typedef struct {
	setnode* h;
}setype;

void init(setype* s) {
	s->h = NULL;
}

void addlast(setype* s, int data) {
	setnode* node = (setnode*)malloc(sizeof(setnode));
	node->data = data;
	node->next = NULL;

	setnode* p = s->h;
	if (p == NULL)
		s->h=node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}

void traverse(setype* s) {
	setnode* p = s->h;

	if (p == NULL)
		printf(" 0");
	else {
		for (; p != NULL; p = p->next)
			printf(" %d", p->data);
	}
	printf("\n");
}

void unionset(setype* s1, setype* s2) {
	setype* s;
	init(&s);

	setnode* p = s1->h;
	setnode* q = s2->h;

	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			addlast(&s, p->data);
			p = p->next;
		}
		else if (p->data > q->data) {
			addlast(&s, q->data);
			q = q->next;
		}
		else {
			addlast(&s, p->data);
			p = p->next;
			q = q->next;
		}
	}

	while (p != NULL) {
		addlast(&s, p->data);
		p = p->next;
	}

	while (q != NULL) {
		addlast(&s, q->data);
		q = q->next;
	}

	traverse(&s);
}

void intersect(setype* s1, setype* s2) {
	setype* s;
	init(&s);

	setnode* p = s1->h;
	setnode* q = s2->h;

	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			p = p->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
		else {
			addlast(&s, p->data);
			p = p->next;
			q = q->next;
		}
	}

	while (p != NULL) {
		p = p->next;
	}

	while (q != NULL) {
		q = q->next;
	}

	traverse(&s);
}


int main()
{
	setype s1, s2;
	init(&s1); init(&s2);

	int n, data;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		addlast(&s1, data);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		addlast(&s2, data);
	}

	unionset(&s1, &s2);
	intersect(&s1, &s2);

	return 0;
}
