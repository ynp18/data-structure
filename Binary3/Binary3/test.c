#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include  <stdbool.h>
//力扣算法题第144题二叉树的前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
  //递归得到树的大小
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//前序遍历
void preOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    a[(*pi)++] = root->val;
    preOrder(root->left, a, pi);
    preOrder(root->right, a, pi);
}

//输出型参数
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    preOrder(root, a, &i);

    return a;
}

//力扣算法题第101题，对称二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isSymmetric(struct TreeNode* q, struct TreeNode* p)
{
    if (q == NULL && p == NULL)
    {
        return true;
    }
    if (q == NULL || p == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }
    return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);

}

bool isSymmetric(struct TreeNode* root)
{
    return _isSymmetric(root->left, root->right);
}

//力扣算法题第572题 另外一棵树的子树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //判断两个树是否相同
bool isSampleTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //其中一个为空，另一个不为空
    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }
    return isSampleTree(p->left, q->left) && isSampleTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == subRoot->val && isSampleTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

//牛客网 二叉树的遍历
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode
{
    char val;
    struct BinTreeNode* left;
    struct BinTreeNode* right;
}BTNode;

BTNode* CreateTree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->val = a[(*pi)++];
    root->left = CreateTree(a, pi);
    root->right = CreateTree(a, pi);
    return root;
}

//中序遍历
void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char a[100];
    scanf("%s", a);
    int i = 0;
    BTNode* root = CreateTree(a, &i);
    InOrder(root);
    return 0;
}