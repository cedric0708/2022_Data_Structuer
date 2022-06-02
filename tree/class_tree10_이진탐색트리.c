#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(int data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

TreeNode* makeTree(TreeNode *root, int data) {
	if (root == NULL)
		return makeNode(data);

	if (data < root->data) {
		root->left = makeTree(root->left, data);
	}
	else if (data > root->data) {
		root->right = makeTree(root->right, data);
	}

	return root;
}

int getNodeCount(TreeNode* root) {

}

int getLeafCount(TreeNode* root) {

}

void preOrder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {

	TreeNode* root = NULL;
	srand(time(NULL));
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int data = rand() % 100;
		printf("%d ", data);
		root = makeTree(root, data);
	}

	printf("\n");
	getchar();

	preOrder(root);
	getchar();
	printf("\n%d %d\n", getNodeCount(root), getLeafCount(root));



	return 0;
}
