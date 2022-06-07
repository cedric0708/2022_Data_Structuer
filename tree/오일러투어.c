#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int k;
typedef char element;

// 트리
typedef struct TreeNode
{
	element data;
	int kLeft,size;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	node->kLeft = node->size = 0;

	return node;
}

int isExternal(TreeNode* node)
{
	return (node->left == NULL && node->right == NULL);
}

void visitLeft(TreeNode* root)
{
	k++;
	root->kLeft = k;
}

void visitRight(TreeNode* root)
{
	root->size = k - root-> kLeft + 1;
}

void eulerTour(TreeNode* root)
{
	printf("%c ", root->data);
	if (!isExternal(root))
	{
		eulerTour(root->left);

	}
	printf("%c ", root->data);


	if (!isExternal(root))
	{
		eulerTour(root->right);
	}
	printf("%c ", root->data);

}



int main()
{
	TreeNode* n9 = makeNode('I', NULL, NULL);
	TreeNode* n8 = makeNode('H', NULL, NULL);
	TreeNode* n7 = makeNode('G', NULL, NULL);
	TreeNode* n6 = makeNode('F', NULL, NULL);
	TreeNode* n5 = makeNode('E', n8, n9);
	TreeNode* n4 = makeNode('D', NULL, NULL);
	TreeNode* n3 = makeNode('C', n6, n7);
	TreeNode* n2 = makeNode('B', n4, n5);
	TreeNode* n1 = makeNode('A', n2, n3);

	TreeNode* root = n1;

	

	eulerTour(root); 
	return 0;
}
