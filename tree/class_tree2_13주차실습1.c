#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode {
	int data;
	int id;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* makenode(int id, int size, treenode* lchild, treenode* rchild) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->id = id;
	node->data = size;
	node->left = lchild;
	node->right = rchild;
	return node;
}

void preorder(treenode* root) {
	if (root) {
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(treenode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d", root->data);
	}
}

void inorder(treenode* root) {
	if (root) {
		inorder(root->left);
		printf(" %d", root->data);
		inorder(root->right);
	}
}

treenode* findnodeid(treenode* root, int id) {
	treenode* p;

	if (root) {
		if (root->id == id) {
			return root;
		}
		p = findnodeid(root->left, id);
		if (p != NULL)
			return p;
		p = findnodeid(root->right, id);
		if (p != NULL)
			return p;
	}
	return NULL;
}

void print(treenode* root, int order) {
	if (order == 1)
		preorder(root);
	else if (order == 2)
		inorder(root);
	else
		postorder(root);
}

int main() {

	treenode* f4 = makenode(4, 70, NULL, NULL);
	treenode* f5 = makenode(5, 90, NULL, NULL);
	treenode* f7 = makenode(7, 130, NULL, NULL);
	treenode* f8 = makenode(8, 80, NULL, NULL);
	treenode* f6 = makenode(6, 120, f7, f8);
	treenode* f2 = makenode(2, 30, f4, f5);
	treenode* f3 = makenode(3, 50, NULL, f6);
	treenode* root = makenode(1, 20, f2, f3);

	int id, order;
	scanf("%d %d", &order, &id);

	treenode* p = findnodeid(root, id);

	if (p == NULL)
		printf("-1");
	else
		print(p, order);
	
	return 0;
}
