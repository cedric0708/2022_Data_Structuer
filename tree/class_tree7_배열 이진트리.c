#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 16

typedef struct {
	int n;
	char T[N];
}Tree;

void init(Tree* t) {
	t->n = 0;
	for (int i = 0; i < N; i++)
		t->T[i] = 0;
}

void makeTree(Tree* t, int idx, char c) {
	t->n++;
	t->T[idx] = c;
}

char element(Tree* t, int idx) {
	return t->T[idx];
}

int isRoot(int idx) {
	return idx == 1;
}

int root() {
	return 1;
}

int parent(int idx) {
	return idx / 2;
}

int leftChild(int idx) {
	return 2 * idx;
}

int rightChild(int idx) {
	return 2 * idx + 1;
}

int isExternal(Tree* t, int idx) {
	return (2 * idx >= N) || (t->T[2 * idx] == 0 && t->T[2 * idx + 1] == 0);
}

void print(Tree* t) {
	for (int i = 1; i < N; i++) {
		printf("%c ", (t->T[i] == 0) ? '#' : t->T[i]);
	}
	printf("\n");
}

int main() {

	Tree t;
	init(&t);

	makeTree(&t, root(), 'A');
	makeTree(&t, leftChild(root()), 'B');
	makeTree(&t, rightChild(root()), 'C');
	makeTree(&t, leftChild(2), 'D');
	makeTree(&t, rightChild(2), 'E');
	makeTree(&t, leftChild(3), 'F');
	makeTree(&t, rightChild(3), 'G');
	makeTree(&t, leftChild(5), 'H');
	makeTree(&t, rightChild(5), 'I');
	makeTree(&t, rightChild(7), 'J');
	print(&t);


	return 0;
}
