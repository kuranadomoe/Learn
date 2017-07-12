/******************************************************************
***	File name:		Program.c									***
***	Description:	¶þ²æÅÅÐòÊ÷Á·Ï°								***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSTree.h"


int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	BSTree tree = NULL;
	BSTree test = bstreeCreat(20);

	bstDelItem(&test, 20);
	fprintf(stdout, "test = 0x%p\n", test);
	bstDestroy(test);


	for (int count = 0;count < 1024;++count)
	{
		tree = bstreeCreat(rand() % 100);
		for (int i = 0;i < 256;++i)
			bstreeAddItem(tree, rand() % 256);
		fprintf(stdout, "\ntree node numeral is %d, height = %d\n", bstreeNodeNum(tree), bstreeHeight(tree));
		bstreeMidOrder(tree);
		fputc('\n', stdout);
		for (int i = 0, randNum = 0;i < 64;++i)
			if (bstreeFind(tree, randNum = (rand() % 128) + 64))
				bstDelItem(&tree, randNum);
		fprintf(stdout, "delete some node after tree node numeral is %d, height = %d\n", bstreeNodeNum(tree), bstreeHeight(tree));
		bstreeMidOrder(tree);
		fputc('\n', stdout);
		bstDestroy(tree);
	}


	system("pause");
	return 0;
}
