#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;

typedef struct treenode {
	char data;
	int kleft, size;
	struct treenode* left, * right;
}treenode;

treenode* makenode(char c, treenode* left, treenode* right) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->data = c;
	node->left = left;
	node->right = right;
	node->kleft = node->size = 0;
	return node;
}

int isexternal(treenode* node) {
	return (node->left == NULL) && (node->right == NULL);
}

void visitleft(treenode* root) {
	k++;
	root->kleft = k;
}

void visitright(treenode* root) {
	root->size = k - root->kleft + 1;
}

void eulertour(treenode* root) {
	visitleft(root);

	if (!isexternal(root)) {
		eulertour(root->left);
	}

	if (!isexternal(root)) {
		eulertour(root->right);
	}
	
	visitright(root);
	printf("%d ", root->size);
}

int main() {

	treenode* n9 = makenode('I', NULL, NULL);
	treenode* n8 = makenode('H', NULL, NULL);
	treenode* n7 = makenode('G', NULL, NULL);
	treenode* n6 = makenode('F', NULL, NULL);
	treenode* n5 = makenode('E', n8, n9);
	treenode* n4 = makenode('D', NULL, NULL);
	treenode* n3 = makenode('C', n6, n7);
	treenode* n2 = makenode('B', n4, n5);
	treenode* n1 = makenode('A', n2, n3);

	eulertour(n1);

	return 0;
}
