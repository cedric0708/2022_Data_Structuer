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
	
	int n;
	
	treeNode*F4 = makenode(70, NULL, NULL);
	treeNode*F5 = makenode(90, NULL, NULL);
	treeNode*F2 = makenode(30, F4, F5);
	
	treeNode*F7 = makenode(130, NULL, NULL);
	treeNode*F8 = makenode(80, NULL, NULL);
	treeNode*F6 = makenode(120, F7, F8);
	treeNode*F3 = makenode(50, NULL, F6);

	treeNode*F1 = makenode(20, F2, F3);

	scanf("%d", &n);
	switch (n)
	{
	case 1:
		folderSize(F1);
		break;
	case 2:
		folderSize(F2);
		break;
	case 3:
		folderSize(F3);
		break;
	case 4:
		folderSize(F4);
		break;
	case 5:
		folderSize(F5);
		break;
	case 6:
		folderSize(F6);
		break;
	case 7:
		folderSize(F7);
		break;
	case 8:
		folderSize(F8);
		break;
	default:
		printf("-1");
		break;
	}

	
	return 0;
}
	
