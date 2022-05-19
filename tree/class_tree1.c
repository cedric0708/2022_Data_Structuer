#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode {
	int data;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* makenode(int size, treenode* lchild, treenode* rchild) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->data = size;
	node->left = lchild;
	node->right = rchild;
	return node;
}

void foldersize(treenode* root) {
	printf("%d ", root->data);
	if (root->left)
		printf("%d ", root->left->data);
	if (root->right)
		printf("%d ", root->right->data);
}


int main() {

	treenode *f[9];
	f[4] = makenode(70, NULL, NULL);
	f[5] = makenode(90, NULL, NULL);
	f[7] = makenode(130, NULL, NULL);
	f[8] = makenode(80, NULL, NULL);
	f[6] = makenode(120, f[7], f[8]);
	f[2] = makenode(30, f[4], f[5]);
	f[3] = makenode(50, NULL, f[6]);
	f[1] = makenode(20, f[2], f[3]);

	int n;

	scanf("%d", &n);
	if (n <= 0 || n >= 9)
		printf("-1");
	else
		foldersize(f[n]);

	
	return 0;
}
	
