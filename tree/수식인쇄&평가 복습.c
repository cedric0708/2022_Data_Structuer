#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode{
	int data;
	struct treenode* left, * right;
}treenode;

treenode* makenode(int data, treenode* left, treenode* right) {
	treenode* node=(treenode*)malloc(sizeof(treenode));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

int isexternal(treenode* node) {
	return (node->left == NULL) && (node->right == NULL);
}

void print(int data) {
	if (data >= 42 && data <= 47)
		printf(" %c", data);
	else
		printf(" %d", data);
}

void preorder(treenode* root) {
	if (root) {
		print(root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treenode* root) {
	if (root) {
		inorder(root->left);
		print(root->data);
		inorder(root->right);
	}
}

void postorder(treenode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		print(root->data);
	}
}

int evalexpr(treenode* root) {
	if (root == NULL)
		return 0;
	else if (isexternal(root))
		return root->data;
	else {
		int x = evalexpr(root->left);
		int y = evalexpr(root->right);
		switch (root->data) {
			case '+':
				return x + y;
			case '-':
				return x - y;
			case '*':
				return x * y;
			case '/':
				return x / y;
		}
	}
}

void printexpr(treenode* root) {
	if (!isexternal(root)) {
		printf("(");
		printexpr(root->left);
	}
	print(root->data);
	if (!isexternal(root)) {
		printexpr(root->right);
		printf(")");
	}
}

int main() {

	treenode* n9 = makenode(1, NULL, NULL);
	treenode* n8 = makenode(7, NULL, NULL);
	treenode* n7 = makenode(1, NULL, NULL);
	treenode* n6 = makenode(3, NULL, NULL);
	treenode* n5 = makenode('-', n8, n9);
	treenode* n4 = makenode(2, NULL, NULL);
	treenode* n3 = makenode('+', n6, n7);
	treenode* n2 = makenode('*', n4, n5);
	treenode* n1 = makenode('/', n2, n3);

	preorder(n1); // / * 2 - 7 1 + 3 1
	printf("\n");
	inorder(n1); // 2 * 7 - 1 / 3 + 1
	printf("\n");
	postorder(n1); // 2 7 1 - * 3 1 + /
	printf("\n");
	printexpr(n1); // (( 2 *( 7 - 1)) /( 3 + 1))
	printf("\n");
	printf("%d", evalexpr(n1)); // 3


	
	return 0;
}
