#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct setnode {
	int elem;
	struct setnode* prev, * next;
}setnode;

typedef struct {
	setnode* h;
}setype;

void init(setype* s) {
	s->h = NULL;
}

void addlast(setype* s, int e) {
	setnode* node = (setnode*)malloc(sizeof(setnode));
	node->elem = e;
	node->next = NULL;

	setnode* p = s->h;
	if (p == NULL)
		s->h = node;
	else {
		while (p != NULL)
			p = p->next;
		p->next=node;
		node->prev = p;
	}
}

void traverse(setype* s) {
	setnode* p = s->h;

	if (p == NULL)
		printf(" 0");
	else {
		for (; p != NULL; p = p->next)
			printf(" %d", p->elem);
	}	
	printf("\n");
}

void unionset(setype* s1, setype* s2) {
	setype* s;
	init(&s);

	setnode* p, * q;
	p = s1->h;
	q = s1->h;

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			addlast(&s, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem) {
			addlast(&s, q->elem);
			q = q->next;
		}
		else {
			addlast(&s, p->elem);
			p = p->next;
			q = q->next;
		}
	}

	while (p != NULL) {
		addlast(&s, p->elem);
		p = p->next;
	}
	while (q != NULL) {
		addlast(&s, q->elem);
		q = q->next;
	}

	traverse(&s);
}

void intersect(setype* s1, setype* s2) {
	setype* s;
	init(&s);
	setnode* p, * q;
	p = s1->h;
	q = s2->h;

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem)
			p = p->next;
		else if (p->elem > q->elem)
			q = q->next;
		else {
			addlast(&s, p->elem);
			p = p->next;
			q = q->next;
		}
	}

	traverse(&s);
}

void subtract(setype* s1, setype* s2) {
	setype* s;
	init(&s);
	setnode* p, * q;
	p = s1->h;
	q = s2->h;

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			addlast(&s, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem)
			q = q->next;
		else {
			p = p->next;
			q = q->next;
		}
	}

	while (p != NULL) {
		addlast(&s, p->elem);
		p = p->next;
	}

	traverse(&s);
}

int member(setype* s, int e) {
	if (s->h == NULL)
		return 0;
	else {
		setnode* p = s->h;
		while (1) {
			if (p->elem < e) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else if (p->elem > e)
				return 0;
			else
				return 1;
		}
	}
}

int subset(setype* s1, setype* s2) {
	if (s1->h == NULL)
		return 1;
	else {
		setnode* p = s1->h;
		while (1) {
			if (member(s2, p->elem) == 1) {
				if (p->next == NULL)
					return 1;
				else
					p = p->next;
			}
			else
				return 0;
		}
	}
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
	subtract(&s1, &s2);
	printf("%d", subset(&s1, &s2));


	return 0;
}
