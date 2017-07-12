/******************************************************************
***	File name:		tree.c										***
***	Description:	Tree ADT implementation						***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


//Creat a tree note
Tree treeCreat(void)
{
	return (Tree)malloc(sizeof(struct StructTree));
}


//Tree initialize
Tree treeInit(Tree root,char elemType,const void* data)
{
	if (elemType != SIGNTYPE&&elemType != NUMTYPE)
	{
		fprintf(stderr,"数据类型错误!\n");
		return NULL;
	}
	if (elemType == SIGNTYPE)
		root->data.sign = (char)((*((int*)data)) & 0xff);
	else
		root->data.numeral = *((int*)data);
	root->elemType = elemType;
	root->lchild = root->rchild = NULL;
	return root;
}


//merge tree
Tree treeMerge(Tree parent, Tree lchild, Tree rchild)
{
	if (!parent)
		return NULL;
	parent->lchild = lchild;
	parent->rchild = rchild;
	return parent;
}


//First order output tree
void treeFirstOrder(Tree root)
{
	if (root == NULL)
		return;
	if (root->elemType == SIGNTYPE)
		fprintf(stdout, "%c  ", root->data.sign);
	else
		fprintf(stdout, "%d  ", root->data.numeral);
	treeFirstOrder(root->lchild);
	treeFirstOrder(root->rchild);
}


//Middle order output tree
void treeMiddleOrder(Tree root)
{
	if (root == NULL)
		return;
	treeMiddleOrder(root->lchild);
	if (root->elemType == SIGNTYPE)
		fprintf(stdout, "%c", root->data.sign);
	else
		fprintf(stdout, "%d", root->data.numeral);
	treeMiddleOrder(root->rchild);
}


//Post order output tree
void treePostOrder(Tree root)
{
	if (root == NULL)
		return;
	treePostOrder(root->lchild);
	treePostOrder(root->rchild);
	if (root->elemType == SIGNTYPE)
		fprintf(stdout, "%c  ", root->data.sign);
	else
		fprintf(stdout, "%d  ", root->data.numeral);
}


//destroy tree
int treeDestroy(Tree root)
{
	if (root == NULL)
		return -1;
	treeDestroy(root->lchild);
	treeDestroy(root->rchild);
	free(root);
	return 1;
}
