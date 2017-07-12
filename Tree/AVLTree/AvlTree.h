/******************************************************************
***	File name:		AVLTree.h									***
***	Description:	AVLTree statement							***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H


typedef int ElemType,Bool;
typedef struct AvlNode *AvlTree, AvlNode;
struct AvlNode
{
	ElemType data;
	AvlTree left, right;
	int height;
};


extern AvlTree avlTreeCreat(const ElemType data);
extern Bool avlTreeEmpty(const AvlTree ptree);
extern int avlTreeNodeNum(const AvlTree ptree);
extern int avlTreeHeight(AvlNode* const pnode);
extern AvlNode *avlTreeFind(const AvlTree ptree, const ElemType data);
extern AvlNode *avlTreeFindMax(const AvlTree ptree);
extern AvlNode *avlTreeFindMin(const AvlTree ptree);
extern ElemType avlTreeRetrieve(const AvlNode* position);
extern Bool avlTreeTraversal(const AvlTree ptree);
extern AvlTree avlTreeInsert(AvlTree ptree, const ElemType data);
extern AvlTree avlTreeDel(AvlTree ptree, const ElemType data);
extern AvlTree avlTreeDestroy(const AvlTree ptree);


#endif
