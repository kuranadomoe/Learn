/******************************************************************
***	File name:		Program.c									***
***	Description:	Binary Sort Tree realise					***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"


static BSTree newNode(const ElemType data);
static BSTree findMax(const BSTree ptree);


/// <summary>
/// Initialize a Binary Sort Tree.
///	<para/>
/// <returns>return NULL</returns>
/// </summary>
extern BSTree bstreeCreat(const ElemType data)
{
	return newNode(data);
}


/// <summary>
/// Judge the BSTree is empty.
///	<para/>
/// <returns>empty return true,else return false</returns>
/// </summary>
/// <param name="ptree">tree pointer</param>
extern int bstreeEmpty(const BSTree ptree)
{
	return ptree == NULL;
}


/// <summary>
/// Count bstree node number
///	<para/>
/// <returns>return bstree node number</returns>
/// </summary>
/// <param name="ptree">tree pointer</param>
extern int bstreeNodeNum(const BSTree ptree)
{
	return bstreeEmpty(ptree) ? 0 : bstreeNodeNum(ptree->lchild) + bstreeNodeNum(ptree->rchild) + 1;
}


/// <summary>
/// Count binary sort tree height.
///	<para/>
/// <returns>tree height</returns>
/// </summary>
/// <param name="ptree">tree pointer</param>
extern int bstreeHeight(const BSTree ptree)
{
	if (!ptree)
		return -1;
	int lheight = bstreeHeight(ptree->lchild) + 1, rheight = bstreeHeight(ptree->rchild) + 1;
	return lheight > rheight ? lheight : rheight;
}


/// <summary>
/// Add a item to BSTree
///	<para/>
/// <returns>success return true,else return false</returns>
/// </summary>
/// <param name="ptree">tree pointer</param>
/// <param name="data">the add data</param>
extern int bstreeAddItem(const BSTree ptree, const ElemType data)
{
	if (bstreeEmpty(ptree) || ptree->data == data)
		return 0;
	if (data < ptree->data)
	{
		if (ptree->lchild == NULL)
		{
			BSTree newnode = newNode(data);
			newnode->lchild = ptree->lchild;
			ptree->lchild = newnode;
			return 1;
		}
		else
			return bstreeAddItem(ptree->lchild, data);
	}
	else
	{
		if (ptree->rchild == NULL)
		{
			BSTree newnode = newNode(data);
			newnode->rchild = ptree->rchild;
			ptree->rchild = newnode;
			return 1;
		}
		else
			return bstreeAddItem(ptree->rchild, data);
	}
}


/// <summary>
/// Find a element in the binary sort tree
///	<para/>
/// <returns>success return ture,else return false</returns>
/// </summary>
/// <param name="ptree">tree pointer</param>
/// <param name="data">find traget</param>
extern int bstreeFind(const BSTree ptree, const ElemType data)
{
	if (ptree == NULL)
		return 0;
	else
		return ptree->data == data ? 1 : data < ptree->data ? bstreeFind(ptree->lchild, data) : bstreeFind(ptree->rchild, data);
}


///	<summary>
///	Delete a node
///	<para/>
/// <returns>success return ture,else return false</returns>
///	</summary>
/// <param name="ptree">tree pointer</param>
/// <param name="target">delete target</param>
extern int bstDelItem(BSTree *const ptree, const ElemType target)
{
	BSTree parent = NULL, delItem = NULL, temp = NULL;
	for (delItem = *ptree;delItem != NULL;)
	{
		if (delItem->data == target)
			break;
		if (target < delItem->data)
		{
			parent = delItem;
			delItem = delItem->lchild;
		}
		else
		{
			parent = delItem;
			delItem = delItem->rchild;
		}
	}
	if (!delItem)
		return 0;
	if (delItem->lchild)//left node not null
	{
		findMax(delItem->lchild)->rchild = delItem->rchild;
		temp = delItem->lchild;
		*delItem = *temp;
		free(temp);
	}
	else if(delItem->rchild)//right node not null
	{
		temp = delItem->rchild;
		*delItem = *temp;
		free(temp);
	}
	else if(delItem == *ptree)
	{
		temp = *ptree;
		*ptree = NULL;
		free(temp);
	}
	else
	{
		if (parent->lchild == delItem)
			parent->lchild = NULL;
		else
			parent->rchild = NULL;
		free(delItem);
	}
	return 1;
}


///	<summary>
///	Middle order output binary sort tree
///	</summary>
/// <param name="ptree">tree pointer</param>
extern void bstreeMidOrder(BSTree ptree)
{
	if (!bstreeEmpty(ptree))
	{
		bstreeMidOrder(ptree->lchild);
		fprintf(stdout, "%-3d ", ptree->data);
		bstreeMidOrder(ptree->rchild);
	}
}


///	<summary>
///	Destroy Binary sort tree
///	</summary>
/// <param name="ptree">destroy tree pointer</param>
extern void bstDestroy(const BSTree ptree)
{
	if (!ptree)
		return;
	bstDestroy(ptree->lchild);
	bstDestroy(ptree->rchild);
	free(ptree);
}


/// <summary>
/// Create a binary sort tree node.
///	<para/>
/// <returns>return a binary sort tree node pointer,if fail,exit</returns>
/// </summary>
///	<param name="data">initialize element data</param>
static BSTree newNode(const ElemType data)
{
	BSTree newnode = (BSTree)malloc(sizeof(struct BSTreeNode));
	if (!newnode)
	{
		fprintf(stderr, "Not enough Memory.");
		system("pause");
		exit(1);
	}
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;
	return newnode;
}


///	<summary>
///	Find Max node
///	<para/>
/// <returns>max node pointer</returns>
///	</summary>
/// <param name="ptree">tree pointer</param>
static BSTree findMax(const BSTree ptree)
{
	if (ptree->rchild)
		return findMax(ptree->rchild);
	if (ptree->lchild)
		return findMax(ptree->lchild);
	return ptree;
}
