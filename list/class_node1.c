#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 100

typedef struct {
	int data[n];
	int size;
}Listtype;//리스트

void init(Listtype* l) {
	l->size = 0;
}//초기화

int isempty(Listtype* l) {
	return l->size == 0;
}//비어있는지 여부

int isfull(Listtype* l) {
	return l->size == n;
}//가득차 있는지 여부

void insertlast(Listtype* l, int elem) {
	if (isfull(l)) {
		printf("Overflow!!\n");
		return;
	}
	l->data[l->size] = elem;
	l->size++;
}//마지막에 삽입

void insert(Listtype* l, int pos, int elem) {
	if (isfull(l)) {
		printf("Overflow!!\n");
		return;
	}
	if (pos < 0 || pos >= l->size) {
		printf("Wrong Position!!\n");
		return;
	}

	for (int i = l->size - 1; i >= pos; i--) {
		l->data[i + 1] = l->data[i];
	}
	l->data[pos] = elem;
	l->size++;
}//중간에 삽입

void print(Listtype* l) {
	for (int i = 0; i < l->size; i++)
		printf("%d -> ", l->data[i]);
	printf("\b\b\b  \n");
}//순회 후 출력

int deletelast(Listtype* l) {
	if (isempty(l)) {
		printf("Empty!!\n");
		return -1;
	}
	int elem = l->data[l->size - 1];
	l->size--;
	return elem;
}//마지막 값 삭제

int delete(Listtype* l, int pos) {
	if (isempty(l)) {
		printf("Empty!!\n");
		return -1;
	}
	if (pos < 0 || pos >= l->size) {
		printf("Wrong Position!!\n");
		return -1;
	}
	int elem = l->data[pos];
	for (int i = pos; i < l->size - 1; i++)
		l->data[i] = l->data[i + 1];
	l->size--;
	return elem;
}//중간 값 삭제

int main()
{
	Listtype l;
	init(&l);

	insertlast(&l, 10); print(&l);
	insertlast(&l, 20); print(&l);
	insertlast(&l, 30); print(&l);
	getchar();

	insert(&l, 1, 40); print(&l);
	insert(&l, 0, 50); print(&l);
	insert(&l, 3, 60); print(&l);

	return 0;
}
