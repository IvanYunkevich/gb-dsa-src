#include <stdio.h>
#include <stdlib.h>
#define true 1==1
#define false 1!=1
typedef int boolean;
typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
}TreeNode;

TreeNode* treeInsert(TreeNode* t, int data)
{
	TreeNode* newNode;
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	TreeNode* current = t;
	TreeNode* parent = t;
	if (t == NULL)
	{
		t = newNode;
	}
	else
	{
      while(current->key != data)
      {
			parent = current;
			if (current->key > data)
			{
				current = current->left;
				if (current == NULL)
				{
					parent->left = newNode;
				}
			}
			else
			{
				current = current->right;
				if (current == NULL)
				{
					parent->right = newNode;
				}
			}
      }
	}
	return t;
}
void printTree(TreeNode *root)
{
    if (root)
    {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
            {
                printTree(root->left);
            }
            else
            {
                                printf("NULL");
            }
            printf(",");
            if (root->right)
            {
                printTree(root->right);
            }
            else
            {
                printf("NULL");
            }
            printf(")");
        }
    }
}
///////task1///////////////////////////////////////////////////////////////////////////////////////
int DepthOfTree(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int DepthLeft = 0;
    int DepthRight = 0;

    if (node->left != NULL)
    {
        DepthLeft = DepthOfTree(node->left);
    }
    if (node->right != NULL)
    {
        DepthRight = DepthOfTree(node->right);
    }
    return 1 + ((DepthLeft > DepthRight) ? DepthLeft : DepthRight);
}
boolean checkBalance(TreeNode *root)
{
    return abs(DepthOfTree(root->left) - DepthOfTree(root->right)) <= 1;
}
//////task 1.1///////////////////////////////////////////////////////////////////////////
void Trees(const int SIZE, TreeNode *root)
{
    for (int i = 0; i < SIZE; ++i)
    {
        treeInsert(root, rand() % 1000);
    }
}
////task2//////////////////////////////////////////////////////////////////////////
TreeNode* binSearch(TreeNode *root, int dat)
{
    if (root == NULL || root->key == dat)
    {
        return root;
    }
    if (dat < root->key)
    {
        return binSearch(root->left, dat);
    }
    else
    {
        return binSearch(root->right, dat);
    }
}
int les12()
{
    const int TREES = 50;
    const int SIZE = 10000;
    int balance = 0;
    for (int i = 0; i < TREES; ++i)
    {
       TreeNode *node = NULL;
       TreeNode *root = treeInsert(node, rand() % 1000);
       Trees(SIZE, root);
       balance += checkBalance(root) ? 1 : 0;
    }
   printf("%d%% \n", balance * 100 / TREES);
}
int main()
{
    les12();
    return 0;
}
