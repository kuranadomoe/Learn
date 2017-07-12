/******************************************************************
***	File name:		AVLTree.c									***
***	Description:	AVLTree realise								***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"


#define MAXCMP(x,y) ((x)>(y)?(x):(y))
static AvlNode *singleRotateWithLeft(AvlTree ptree);
static AvlNode *singleRotateWithRight(AvlTree ptree);
static AvlNode *doubleRotateWithLeft(AvlTree ptree);
static AvlNode *doubleRotateWithRight(AvlTree ptree);
static AvlTree newNode(const ElemType data);


///	<summary>
///	Creat a AvlTree
///	</summary>
///	<param name="data">tree init data</param>
///	<return>A AvlTree pointer</return>
extern AvlTree avlTreeCreat(const ElemType data)
{
	return newNode(data);
}


///	<summary>
///	AvlTree empty status
///	</summary>
///	<param name="ptree">AvlTree pointer</param>
///	<return>Tree empty return true,else return false</return>
extern Bool avlTreeEmpty(const AvlTree ptree)
{
	return ptree == NULL;
}


///	<summary>
///	Count tree node
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<return>return node numeral</return>
extern int avlTreeNodeNum(const AvlTree ptree)
{
	return avlTreeEmpty(ptree) ? 0 : avlTreeNodeNum(ptree->left) + avlTreeNodeNum(ptree->right) + 1;
}


///	<summary>
///	Get node height
///	</summary>
///	<param name="pnode">node pointer</param>
///	<return>node height</return>
extern int avlTreeHeight(AvlNode* const pnode)
{
	return avlTreeEmpty(pnode) ? -1 : pnode->height;
}


///	<summary>
///	Find a data in the AvlTree
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<param name="data">the find target</param>
///	<return>data in the tree position</return>
extern AvlNode *avlTreeFind(const AvlTree ptree, const ElemType data)
{
	if (avlTreeEmpty(ptree))
		return NULL;
	if (ptree->data == data)
		return ptree;
	else
		return data < ptree->data ? avlTreeFind(ptree->left, data) : avlTreeFind(ptree->right, data);
}


///	<summary>
///	Find a AvlTree max node
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<return>the tree max node position</return>
extern AvlNode *avlTreeFindMax(const AvlTree ptree)
{
	if (avlTreeEmpty(ptree))
		return NULL;
	return avlTreeEmpty(ptree->right) ? ptree : avlTreeFindMax(ptree->right);
}


///	<summary>
///	Find a AvlTree min node
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<return>the tree min node position</return>
extern AvlNode *avlTreeFindMin(const AvlTree ptree)
{
	if (avlTreeEmpty(ptree))
		return NULL;
	return avlTreeEmpty(ptree->left) ? ptree : avlTreeFindMin(ptree->left);
}


///	<summary>
///	Retrieve element
///	</summary>
///	<param name="position">position pointer</param>
///	<return>a element</return>
extern ElemType avlTreeRetrieve(const AvlNode* position)
{
	return position->data;
}


///	<summary>
///	Inorder traversal and output
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<return>bool value</return>
extern Bool avlTreeTraversal(const AvlTree ptree)
{
	if (avlTreeEmpty(ptree))
		return 0;
	avlTreeTraversal(ptree->left);
	fprintf(stdout, "%4d ", ptree->data);
	avlTreeTraversal(ptree->right);
	return 1;
}


///	<summary>
///	Insert node to tree
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<param name="data">insert data</param>
///	<return>update after pointer</return>
extern AvlTree avlTreeInsert(AvlTree ptree, const ElemType data)
{
	if (avlTreeEmpty(ptree))
		return newNode(data);
	if (data < ptree->data)
	{
		ptree->left = avlTreeInsert(ptree->left, data);
		if (avlTreeHeight(ptree->left) - avlTreeHeight(ptree->right) == 2)
		{
			if (data < ptree->left->data)
				ptree = singleRotateWithLeft(ptree);
			else
				ptree = doubleRotateWithLeft(ptree);
		}
	}
	else if (data > ptree->data)
	{
		ptree->right = avlTreeInsert(ptree->right, data);
		if (avlTreeHeight(ptree->right) - avlTreeHeight(ptree->left) == 2)
		{
			if (data > ptree->right->data)
				ptree = singleRotateWithRight(ptree);
			else
				ptree = doubleRotateWithRight(ptree);
		}
	}
	ptree->height = MAXCMP(avlTreeHeight(ptree->left), avlTreeHeight(ptree->right)) + 1;
	return ptree;
}


///	<summary>
///	Delete element
///	</summary>
///	<param name="ptree">tree pointer</param>
///	<param name="data">delete element</param>
///	<return>update after pointer</return>
extern AvlTree avlTreeDel(AvlTree ptree, const ElemType data)
{
	if (avlTreeEmpty(ptree))
		return ptree;
	if (data < ptree->data)
	{
		ptree->left = avlTreeDel(ptree->left, data);
		if (avlTreeHeight(ptree->right) - avlTreeHeight(ptree->left) == 2)
		{
			if (avlTreeHeight(ptree->right->left) > avlTreeHeight(ptree->right->right))//	>
				ptree = doubleRotateWithRight(ptree);//Equivalent to R-L insert
			else//	<=
				ptree = singleRotateWithRight(ptree);//Equivalent to R-R insert
		}
	}
	else if (data > ptree->data)
	{
		ptree->right = avlTreeDel(ptree->right, data);
		if (avlTreeHeight(ptree->left) - avlTreeHeight(ptree->right) == 2)
		{
			if (avlTreeHeight(ptree->left->right) > avlTreeHeight(ptree->left->left))
				ptree = doubleRotateWithLeft(ptree);//Equivalent to L-R insert
			else
				ptree = singleRotateWithLeft(ptree);//Equivalent to L-L insert
		}
	}
	else if (!avlTreeEmpty(ptree->left) && !avlTreeEmpty(ptree->right))
	{
		ptree->data = avlTreeFindMin(ptree->right)->data;
		ptree->right = avlTreeDel(ptree->right, ptree->data);
		if (avlTreeHeight(ptree->left) - avlTreeHeight(ptree->right) == 2)
		{
			if (avlTreeHeight(ptree->left->right) > avlTreeHeight(ptree->left->left))
				ptree = doubleRotateWithLeft(ptree);//Equivalent to L-R insert
			else
				ptree = singleRotateWithLeft(ptree);//Equivalent to L-L insert
		}
	}
	else
	{
		AvlNode* temp = ptree;
		if (ptree->left == NULL)
			ptree = ptree->right;
		else
			ptree = ptree->left;
		free(temp);
	}
	if (!avlTreeEmpty(ptree))
		ptree->height = MAXCMP(avlTreeHeight(ptree->left), avlTreeHeight(ptree->right)) + 1;
	return ptree;
}


///	<summary>
///	Destroy AvlTree
///	</summary>
///	<param name="ptree">AvlTree point</param>
///	<return>success return NULL</return>
extern AvlTree avlTreeDestroy(const AvlTree ptree)
{
	if (!avlTreeEmpty(ptree))
	{
		avlTreeDestroy(ptree->left);
		avlTreeDestroy(ptree->right);
		free(ptree);
	}
	return NULL;
}


///	<summary>
///	Make a new node
///	</summary>
///	<param name="data">new node data</param>
///	<return>return a new node,if failure,abort process</return>
static AvlTree newNode(const ElemType data)
{
	AvlTree newnode = (AvlTree)malloc(sizeof(AvlNode));
	if (!newnode)
	{
		fprintf(stderr, "Not enough Memory.");
		system("pause");
		exit(1);
	}
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	newnode->height = 0;
	return newnode;
}


///	<summary>
///	AvlTree single rotate with left
///	</summary>
///	<param name="ptree">AvlTree point</param>
///	<return>return rotate after pointer</return>
static AvlNode *singleRotateWithLeft(AvlTree ptree)
{
	AvlNode* temp = ptree->left;/*new root*/
	ptree->left = temp->right;
	temp->right = ptree;
	ptree->height = MAXCMP(avlTreeHeight(ptree->left), avlTreeHeight(ptree->right)) + 1;
	temp->height = MAXCMP(avlTreeHeight(temp->left), avlTreeHeight(temp->right)) + 1;
	return temp;
}


///	<summary>
///	AvlTree single rotate with right
///	</summary>
///	<param name="ptree">AvlTree point</param>
///	<return>return rotate after pointer</return>
static AvlNode *singleRotateWithRight(AvlTree ptree)
{
	AvlNode* temp = ptree->right;/*new root*/
	ptree->right = temp->left;
	temp->left = ptree;
	ptree->height = MAXCMP(avlTreeHeight(ptree->left), avlTreeHeight(ptree->right)) + 1;
	temp->height = MAXCMP(avlTreeHeight(temp->left), avlTreeHeight(temp->right)) + 1;
	return temp;
}


///	<summary>
///	AvlTree double rotate with left
///	</summary>
///	<param name="ptree">AvlTree point</param>
///	<return>return rotate after pointer</return>
static AvlNode *doubleRotateWithLeft(AvlTree ptree)
{
	ptree->left = singleRotateWithRight(ptree->left);
	return singleRotateWithLeft(ptree);
}


///	<summary>
///	AvlTree double rotate with right
///	</summary>
///	<param name="ptree">AvlTree point</param>
///	<return>return rotate after pointer</return>
static AvlNode *doubleRotateWithRight(AvlTree ptree)
{
	ptree->right = singleRotateWithLeft(ptree->right);
	return singleRotateWithRight(ptree);
}
