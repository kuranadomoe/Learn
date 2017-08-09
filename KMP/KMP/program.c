#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *target, char *pattern);
static void makeNext(char *pattern, int next[]);

int main(int argc, char **argv)
{
	char target[1000001] = "", pattern[1001] = "";
	fgets(target, 1000001, stdin);
	fgets(pattern, 1001, stdin);
	fprintf(stdout, "%d\n", KMP(target, pattern));
	system("pause");
	return 0;
}

///	<summary>
///	对于给定字符串target,在其中搜索模式串pattern,并返回pattern在target中的数量
///	</summary>
///	<param name="target">目标字符串</param>
///	<param name="pattern">要搜索的字符串</param>
int KMP(char *target, char *pattern)
{
	int tlen = strlen(target), plen = strlen(pattern);
	int *next = (int*)malloc(plen * sizeof(int));
	makeNext(pattern, next);

	int count = 0;
	//	i为target下标,match为已匹配字符的长度(同时也是下标)
	for (int i = 0, match = 0;i < tlen;++i)
	{
		for (;target[i] != pattern[match] && match != 0;)
		{
			match = next[match - 1];
		}
		if (target[i] == pattern[match])
		{
			match += 1;
		}
		if (match == plen)
		{
			match = 0;
			count += 1;
		}
	}

	free(next);
	return count;
}

///	<summary>
///	对于给定字符串pattern,求它每一位的最大公共长度,并存入next数组
///	例如"abaabcaba"得到的结果为001120123
///	</summary>
///	<param name="pattern">用于求最大公共长度的字符串</param>
///	<param name="next">存放最大公共长度的数组</param>
static void makeNext(char *pattern, int next[])
{
	next[0] = 0;//字符串pattern的第0位的最大公共长度必定为0

	//	i是字符串pattern的下标,i从1开始直到遍历完pattern
	//	k表示字符串pattern在第i-1位的最大公共长度,因此,[0,k-1]的字符串与[i-1-(k-1),i-1]即[i-k,i-1]的字符串相等
	for (int i = 1, k = 0;pattern[i] != '\0';++i)
	{
		//如果第i位与第k位不同,则往前寻找直到找到相同的或者确认完全不同(回退到next[0])为止
		for (;k > 0 && pattern[k] != pattern[i];)
			k = next[k - 1];

		//如果第i位与第k位相同,那么第i位的值为第k位的值加1
		//上面的for循环如果不是因为回退到next[0]而结束,那么到这里就会让k增加1
		if (pattern[k] == pattern[i])
			k += 1;

		//更新next[i]
		next[i] = k;
	}
}
