#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* manacher(char* str);

int main(int argc, char **argv)
{
	fprintf(stdout, "%s%c",manacher("abcabcdeedcbabcde"),'\n');
	system("pause");
	return 0;
}

#ifdef MIN
#undef MIN
#endif
#define MIN(x,y) ((x)<(y)?(x):(y))
//	用manacher算法求出给定字符串中最长的回文子串
//	如果字符串中有多个最长的回文子串,只会返回第一个,如果要全部返回需要链表或者队列,懒得弄,所以就这样了
char* manacher(char* str)
{
	int oldStrLen = strlen(str);//源字符串长度
	int len = oldStrLen * 2 + 1;//用manacher算法处理字符串需要的长度
	char *s = (char*)malloc(len * sizeof(char));//存放源字符串处理后的字符串

	//	将源字符串每个字符两侧插入一个'#',如abc -> #a#b#c#
	for (int i = 0;i < oldStrLen;++i)
		s[2 * i] = '#', s[2 * i + 1] = str[i];
	s[len - 1] = '#';

	int *radiusLen = (int *)malloc(len * sizeof(int));//记录以当前位置为中心的回文字符串的半径长度,包括该字符
	int position = 0, maxRight = 0;//position和maxRight是回文子串中心和最右位置
	int maxRadiusLenPosition = 0;//记录radiusLen中最大值的下标
	for (int i = 0;i < len;++i)
	{
		if (i < maxRight)
			radiusLen[i] = MIN(radiusLen[2 * position - i], maxRight - i);
		else
			radiusLen[i] = 1;
		//	尝试扩展回文子串
		for (;(i - radiusLen[i] >= 0 && i + radiusLen[i] < len) && (s[i - radiusLen[i]] == s[i + radiusLen[i]]);)
			++radiusLen[i];
		//	更新position和maxRight
		if (radiusLen[i] + i - 1 > maxRight)
		{
			position = i;
			maxRight = i + radiusLen[i] - 1;
		}
		if (radiusLen[i] > radiusLen[maxRadiusLenPosition])
			maxRadiusLenPosition = i;
	}

	char *maxSubStr = (char*)malloc((radiusLen[maxRadiusLenPosition]) * sizeof(char));//存放最长回文子串
	strncpy_s(maxSubStr, (radiusLen[maxRadiusLenPosition]) * sizeof(char), str + (maxRadiusLenPosition- radiusLen[maxRadiusLenPosition] + 1) / 2, radiusLen[maxRadiusLenPosition] - 1);//截取子串
	return maxSubStr;
}
