#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int BTDataTree;

typedef struct  BinaryTreeNode
{
	BTDataTree data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	node->data = x;
	node->left = node->right = NULL;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//前序
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//中序
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	printf("%d", root->data);
	PrevOrder(root->right);
}

//后序
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%d", root->data);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//二叉树第k层的节点
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}


BTNode* BinaryTreeFind(BTNode* root, BTDataTree x)
{

}

int main()
{
	BTNode* root = CreatBinaryTree();
	PostOrder(root);
	printf("\n");

	printf("%d\n", TreeSize(root));
	printf("%d\n", TreeLeafSize(root));
	printf("%d\n", TreeHeight(root));
	printf("%d\n", TreeLevelKSize(root,3));
	return 0;
}