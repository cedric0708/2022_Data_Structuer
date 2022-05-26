#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

void print(element val) {
	if (val >= 42 && val <= 47)
		printf(" %c", val);
	else
		printf(" %d", val);
}

int isExternal(TreeNode* node) {
	return (node->left == NULL && node->right == NULL);
}

void preOrder(TreeNode* root) {
	if (root)
	{
		print(root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode* root)
{
	if (root)
	{
		inOrder(root->left);
		print(root->data);
		inOrder(root->right);
	}
}

void postOrder(TreeNode* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		print(root->data);
	}
}

element evalExpr(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (isExternal(root))
		return root->data;
	else {
		int x = evalExpr(root->left);
		int y = evalExpr(root->right);
		printf("%2d %c %d = ...\n", x, root->data, y);
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
	return 0;
}


int main() {

	TreeNode* n9 = makeNode(1, NULL, NULL);
	TreeNode* n8 = makeNode(7, NULL, NULL);
	TreeNode* n7 = makeNode(1, NULL, NULL);
	TreeNode* n6 = makeNode(3, NULL, NULL);
	TreeNode* n5 = makeNode('-', n8, n9);
	TreeNode* n4 = makeNode(2, NULL, NULL);
	TreeNode* n3 = makeNode('+', n6, n7);
	TreeNode* n2 = makeNode('*', n4, n5);
	TreeNode* n1 = makeNode('/', n2, n3);

	TreeNode* root = n1;
	
	printf("PreOrder Expr : "); preOrder(root); printf("\n");
	printf("InOrder Expr : "); inOrder(root); printf("\n");
	printf("PostOrder Expr : "); postOrder(root); printf("\n\n");

	printf("Evaluated : %d\n", evalExpr(root));
	
	return 0;
}
	
