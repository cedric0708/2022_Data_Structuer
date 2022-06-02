#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

TreeNode* findNode(TreeNode* root, int data) {
	TreeNode* temp = root;

	if (root == NULL)
		return NULL;

	if (root->data == data)
		return root;

	temp = findNode(root->left, data);
	if (temp)
		return temp;

	return findNode(root->right, data);
}

void connectNode(TreeNode* root, int d, int l, int r) {
	TreeNode* p = findNode(root, d);

	if (l != 0)
		p->left = makeNode(l);
	if (r != 0)
		p->right = makeNode(r);
}

TreeNode* makeTree() {
	int n, d, l, r;
	TreeNode* root;
	scanf("%d", &n);

	scanf("%d %d %d", &d, &l, &r);

	root=makeNode(d);
	root->left=makeNode(l);
	root->right=makeNode(r);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &d, &l, &r);
		connectNode(root, d, l, r);
	}

	return root;
}

void preOrder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void traversal(TreeNode* root, char* str) {
	printf(" %d", root->data);
	if (*str) {
		if (*str == 'R') {
			traversal(root->right, str + 1);
		}
		else if(*str=='L')
			traversal(root->left, str + 1);
	}
}

int main() {

	TreeNode* root = makeTree();

	int n;
	char str[10];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		traversal(root, str);
		printf("\n");
	}


	return 0;
}
