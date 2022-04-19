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

int member(setype* s, int e) {
	if (s->h == NULL)
		return 0;
	else {
		setnode* p = s->h;
		while (1) {
			if (p->data < e) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else if (p->data > e)
				return 0;
			else
				return 1;
		}
	}
}

int subset(setype* s1, setype* s2) {
	if (s1->h == NULL)
		return 0;
	else {
		setnode* p = s1->h;
		while (1) {
			if (member(s2, p->data) == 1) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else
				return p->data;
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


	printf("%d", subset(&s1, &s2));
	

	return 0;
}
