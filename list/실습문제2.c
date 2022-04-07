#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
	int coef;
	int exp;
	struct listnode* next;
}listnode;

typedef struct {
	listnode* h;
	listnode* t;
}listtype;

void init(listtype *l) {
	l->h = l->t = NULL;
}

void insertlast(listtype* l, int coef, int exp) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->coef = coef;
	node->exp = exp;
	node->next = NULL;

	if (l->t == NULL)
		l->h = l->t = node;
	else {
		l->t->next = node;
		l->t = node;
	}
}

void polyadd(listtype* l, listtype* l1, listtype* l2) {
	listnode* p = l1->h;
	listnode* q = l2->h;
	int sum;

	while (p && q) {
		if (p->exp == q->exp) {
			sum = p->coef + q->coef;
			if (sum)
				insertlast(l, sum, p->exp);
			p = p->next;
			q = q->next;
		}
		else if (p->exp > q->exp) {
			insertlast(l, p->coef, p->exp);
			p = p->next;
		}
		else {
			insertlast(l, q->coef, q->exp);
			q = q->next;
		}
	}
	for (; p != NULL;p=p->next)
		insertlast(l, p->coef, p->exp);
	for (; q != NULL; q = q->next)
		insertlast(l, q->coef, q->exp);
}

void print(listtype* l) {
	for (listnode* p = l->h; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
}

int main()
{
	listtype poly, poly1, poly2;

	init(&poly);
	init(&poly1);
	init(&poly2);

	int n1, n2, i, a, b, c, d;
	scanf("%d", &n1);

	for (i = 0; i < n1; i++) {
		scanf("%d %d", &a, &b);
		insertlast(&poly1, a, b);
	}
	
	scanf("%d", &n2);

	for (i = 0; i < n2; i++) {
		scanf("%d %d", &c, &d);
		insertlast(&poly2, c, d);
	}

	polyadd(&poly, &poly1, &poly2);

	print(&poly);


	return 0;
}
