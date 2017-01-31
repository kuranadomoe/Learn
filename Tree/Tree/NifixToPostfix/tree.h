/******************************************************************
***	File name:		tree.h										***
***	Description:	Tree ADT Statement							***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#pragma once
#ifndef TREE_H
#define TREE_H


#define SIGNTYPE 's'
#define NUMTYPE 'n'


typedef union
{
	char sign;
	int numeral;
}TreeElement;
typedef struct StructTree
{
	TreeElement data;//存放数据
	signed char elemType;//数据是char还是int
	struct StructTree *lchild, *rchild;
}*Tree;


Tree treeCreat(void);//Creat a tree note
Tree treeInit(Tree root, char elemType, const void* data);//Tree initialize
Tree treeMerge(Tree parent, Tree lchild, Tree rchild);//merge tree
void treeFirstOrder(Tree root);//First order output tree
void treeMiddleOrder(Tree root);//Middle order output tree
void treePostOrder(Tree root);//Post order output tree
int treeDestroy(Tree root);//destroy tree



#endif
