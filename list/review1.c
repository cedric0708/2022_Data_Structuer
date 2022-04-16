#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
	int elem;
	struct listnode *next;
}listnode;//단일 연결리스트

typedef struct listype {
	listnode* h;
}listype;//헤더

void init(listype* l) {
	l->h = NULL;
}//초기화

void insertfirst(listype* l, int n) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = n;
	node->next = l->h;
	l->h = node;
}//맨 앞에 삽입

void insertlast(listype* l, int n) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = n;
	node->next = NULL;

	listnode* p=l->h;
	if (p == NULL)
		l->h = node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}//맨 뒤에 삽입

void insert(listype* l, int pos, int n) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	listnode* p = l->h;
	
	if (pos == 0)
		insertfirst(l, n);
	else {
		for (int i = 0; i < pos-1; i++)
			p = p->next;
		node->elem = n;
		node->next = p->next;
		p->next = node;
	}
}//정해진 위치에 삽입

void deletefirst(listype *l) {
	listnode* p = l->h;

	int n = p->elem;
	l->h = p->next;
	free(p);
}//맨 앞 삭제

void deletelast(listype* l) {
	listnode* p = l->h;
	listnode* q = p;

	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	int n = p->elem;
	q->next = NULL;
	free(p);
}//맨 뒤 삭제

void delete(listype* l, int pos) {
	listnode* p = l->h;
	listnode* q = p;

	if (pos == 0)
		deletefirst(l);
	else {
		for (int i = 0; i < pos; i++) {
			q = p;
			p = p->next;
		}
		int n = p->elem;
		q->next = p->next;
		free(p);
	}
}//정해진 위치 삭제

void print(listype* l) {
	for (listnode* p = l->h; p != NULL; p = p->next) {
		if (p->next == NULL)
			printf("%d", p->elem);
		else
			printf("%d -> ", p->elem);
	}
	printf("\n");
}//출력

int main()
{
	listype l;
	init(&l);

	insertlast(&l, 78); print(&l);
	insertlast(&l, 36); print(&l);
	insertlast(&l, 59); print(&l);
	

	insertfirst(&l, 22); print(&l);
	insertfirst(&l, 71); print(&l);
	insertfirst(&l, 13); print(&l);


	insert(&l, 2, 9); print(&l);
	insert(&l, 4, 4); print(&l);
	insert(&l, 6, 21); print(&l);


	deletefirst(&l); print(&l);
	deletelast(&l); print(&l);
	delete(&l, 3); print(&l);


	return 0;
}
