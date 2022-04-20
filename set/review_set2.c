#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
	int elem;
	struct listnode* next;
}listnode;

typedef struct {
	listnode* h;
}listype;

void init(listype* l) {
	l->h = NULL;
}

void addlast(listype* l, int e) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->next = NULL;
	listnode* p = l->h;
	if (p == NULL)
		l->h = node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}

listnode *unionset(listype* s1, listype* s2) {
	listnode* p = s1->h;
	listnode* q = s2->h;
	if (p == NULL && q == NULL)
		return 0;
	else {
		listype* s;
		init(&s);
		listnode* ss = s->h;
		if (p == NULL) {
			ss->elem = q->elem;
			ss->next = unionset(&p, &(q->next));
		}
		else if (q == NULL) {
			ss->elem = p->elem;
			ss->next = unionset(&(p->next), &q);
		}
		else {
			if (p->elem < q->elem) {
				ss->elem = p->elem;
				ss->next = unionset(&(p->next), &q);
			}
			else if (p->elem > q->elem) {
				ss->elem = q->elem;
				ss->next = unionset(&p, &(q->next));
			}
			else {
				ss->elem = p->elem;
				ss->next = unionset(&(p->next), &(q->next));
			}
		}
		return ss;
	}
}

listnode* intersect(listype* s1, listype* s2) {
	listnode* p = s1->h;
	listnode* q = s2->h;
	listype* s;
	init(&s);
	listnode* ss = s->h;
	if (p == NULL && q == NULL)
		return 0;
	else {
		if (p->elem < q->elem)
			return intersect(&(p->next), &q);
		else if(p->elem>q->elem)
			return intersect(&p, &(q->next));
		else {
			ss->elem = p->elem;
			ss->next = intersect(&(p->next), &(q->next));
		}
		return ss;
	}
}

void traverse(listype* l) {
	listnode* p = l->h;

	for (; p != NULL; p = p->next)
		printf(" %d", p->elem);
}

int main()
{
	listype s1, s2;
	init(&s1);
	init(&s2);
	int a, b;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &a);
		addlast(&s1, a);
	}

	for (int i = 0; i < 3; i++) {
		scanf("%d", &b);
		addlast(&s2, b);
	}

	traverse(unionset(&s1, &s2));
	traverse(intersect(&s1, &s2));

	return 0;
}
