/******************************************************************
***	File name:		Program.c									***
***	Description:	带平衡条件的二叉排序树练习					***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVLTree.h"


int  main(int argc, char *arcv[])
{
	AvlTree tree = NULL;
	srand((unsigned int)time(NULL));

	for (;;)
	{
		for (int i = 0;i < 256;++i)
		{
			tree = avlTreeInsert(tree, rand() % 256);
			if (abs(avlTreeHeight(tree->left) - avlTreeHeight(tree->right)) > 1)
				fprintf(stdout, "\nNot balance.\n");
		}

		fprintf(stdout, "\nInsert after :\n");
		avlTreeTraversal(tree);
		fprintf(stdout, "\nNode number is : %d", avlTreeNodeNum(tree));
		fprintf(stdout, "\nRoot data is %d, max data is %d, min data is %d", avlTreeRetrieve(tree), avlTreeRetrieve(avlTreeFindMax(tree)), avlTreeRetrieve(avlTreeFindMin(tree)));
		fprintf(stdout, "\nThere %s in the tree.\n", avlTreeEmpty(avlTreeFind(tree, 128)) ? "is no 128" : "are 128 trees");

		for (int i = 0;i < 256;++i)
		{
			tree = avlTreeDel(tree, rand() % 256);
			if (abs(avlTreeHeight(tree->left) - avlTreeHeight(tree->right)) > 1)
				fprintf(stdout, "\nNot balance.\n");
		}

		fprintf(stdout, "\nDelete some node after :\n");
		avlTreeTraversal(tree);
		fprintf(stdout, "\nNode number is : %d", avlTreeNodeNum(tree));
		fprintf(stdout, "\nRoot data is %d, max data is %d, min data is %d", avlTreeRetrieve(tree), avlTreeRetrieve(avlTreeFindMax(tree)), avlTreeRetrieve(avlTreeFindMin(tree)));
		fprintf(stdout, "\nThere %s in the tree.\n", avlTreeEmpty(avlTreeFind(tree, 128)) ? "is no 128" : "are 128 trees");

		tree = avlTreeDestroy(tree);
		system("pause");
		system("cls");
	}


	return 0;
}
