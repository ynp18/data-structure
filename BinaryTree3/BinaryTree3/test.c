#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}BTNode;


//二叉树的销毁
void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}

//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d", front->data);
		QueuePop(&q);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}

	}
	QueueDestory(&q);
}

BTNode* BuyNode(int data)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	newnode->right = newnode->left = NULL;
	newnode->data = data;
	return newnode;
}

BTNode* CreateTree()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3); 
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	BTNode* n7 = BuyNode(7);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n5->left = n7;

	return n1;
}



//判断是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		
		//遇到第一个空，就可以开始判断，如果队列中还有非空，就不是完全二叉树
		if (front)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		//如果队列中还有非空，就不是完全二叉树
		if(front)
		{
			QueueDestory(&q);
			return false;
		}

		QueueDestory(&q);
		return true;
	}
}

int main()
{
	
	return 0;
}