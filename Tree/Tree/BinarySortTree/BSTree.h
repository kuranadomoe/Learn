/******************************************************************
***	File name:		BStree.c									***
***	Description:	Binary Sort Tree statement					***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#pragma once
#ifndef BSTREE_H
#define BSTREE_H


typedef unsigned int ElemType;
typedef struct BSTreeNode
{
	ElemType data;
	struct BSTreeNode *lchild, *rchild;
}*BSTree;


extern BSTree bstreeCreat(const ElemType data);
extern int bstreeEmpty(const BSTree ptree);
extern int bstreeNodeNum(const BSTree ptree);
extern int bstreeHeight(const BSTree ptree);
extern int bstreeAddItem(const BSTree ptree, const ElemType data);
extern int bstreeFind(const BSTree ptree, const ElemType data);
extern int bstDelItem(BSTree *const ptree, const ElemType target);
extern void bstreeMidOrder(BSTree ptree);
extern void bstDestroy(const BSTree ptree);


#endif
