#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct listnode {
	int elem;
	char group;
	struct listnode* prev, * next;
}listnode;//이중연결리스트

void init(listnode* h, listnode* t) {
	h->next = t;
	t->prev = h;
}//헤더, 트레일러 생성 및 초기화

void addnode(listnode* p, int e, char g) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->group = g;
	node->prev = p->prev;
	node->next = p;
	p->prev->next = node;
	p->prev = node;
}

void add(listnode* h, int pos, int e, char g) {
	listnode* p = h;

	for (int i = 1; i <= pos; i++)
		p = p->next;

	addnode(p, e, g);
}//노드 삽입

void removenode(listnode* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	
}

void removegroup(listnode* h, listnode* t, char g) {
	listnode* p = h->next;
	for (; p != t; p = p->next) {
		if (p->group == g)
			removenode(p);
	}
}//그룹 삭제

void traverse(listnode* h, listnode* t) {
	listnode* p = h->next;
	for (; p != t; p = p->next) {
		printf(" %d %c\n", p->elem, p->group);
	}
	printf("\n");
}//출력



int main()
{
	listnode* h = (listnode*)malloc(sizeof(listnode));
	listnode* t = (listnode*)malloc(sizeof(listnode));

	init(h, t);
	srand(time(NULL));
	char g[5] = { 'A', 'B', 'C', 'D', 'E' };
	for (int i = 1; i <= 10; i++) {
		int e = rand() % 100;
		char c = g[rand() % 5];
		add(h, i, e, c);
	}


	traverse(h, t);

	char d;
	scanf("%c", &d);
	removegroup(h, t, d);
	traverse(h, t);

	return 0;
}
