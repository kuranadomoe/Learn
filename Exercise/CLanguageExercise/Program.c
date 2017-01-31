#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char*argv[])
{
	int gold = 1000;
	for (int flag = 0;!flag;++gold)
	{
		for (int i = 1,temp = gold;i <= 5;++i)
		{
			if (!(temp * 5 / 4 % 5))
				temp = temp * 5 / 4 - 1;
			else
				break;
			if (i == 5)
			{
				flag = 1;
				gold = temp - 1;
			}
		}
	}
	fprintf(stdout, "gold total:%d\n", gold);
	system("pause");
	return 0;
}
