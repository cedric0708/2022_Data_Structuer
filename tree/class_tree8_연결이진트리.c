#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k;

typedef struct TreeNode {
	char elem;
	struct TreeNode* parent, * left, * right;
}TreeNode;

TreeNode* makeNode(char elem, TreeNode* parent, TreeNode* left, TreeNode* right) {
	TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
	temp->elem = elem;
	temp->parent = parent;
	temp->left = left;
	temp->right->right;
	return temp;
}

int isExternal(TreeNode* v) {
	return (v->left == NULL && v->right == NULL);
}

char element(TreeNode* v) {
	return v->elem;
}

TreeNode* rootNode() {
	return root;
}

int isRoot(TreeNode* v) {
	return v == root;
}

TreeNode* parent(TreeNode* v) {
	if (!isRoot(v))
		return v->parent;
}

int main() {

	TreeNode* n9 = makeNode('I', NULL, NULL, NULL);
	TreeNode* n8 = makeNode('H', NULL, NULL, NULL);
	TreeNode* n7 = makeNode('G', NULL, NULL, NULL);
	TreeNode* n6 = makeNode('F', NULL, NULL, NULL);
	TreeNode* n5 = makeNode('E', NULL, n8, n9);
	TreeNode* n4 = makeNode('D', NULL, NULL, NULL);
	TreeNode* n3 = makeNode('C', NULL, n6, n7);
	TreeNode* n2 = makeNode('B', NULL, n4, n5);
	TreeNode* n1 = makeNode('A', NULL, n2, n3);

	TreeNode *root = n1;
	n8->parent = n9->parent = n5;
	n6->parent = n7->parent = n3;
	n4->parent = n5->parent = n2;
	n2->parent = n3->parent = root;

	printf("InOrder  : "); inOrder(root); printf("\n");
	printf("PreOrder  : "); preOrder(root); printf("\n");
	printf("PostOrder  : "); postOrder(root); printf("\n\n");

	printf("Element of n7 : %c\n", element(n7));
	printf("Element of root : %c\n", element(rootNode()));
	printf("n2 is root node? %s\n", isRoot(n2) ? "Yes" : "No");
	printf("Element of n7's parent : %c\n", element(parent(n7)))


	return 0;
}
