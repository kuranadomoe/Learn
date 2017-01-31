/******************************************************************
***	File name:		Program.c									***
***	Description:	用栈实现中缀表达式转后缀表达式并输出		***
***					假设输入只包含加减乘除,左右括号和数字		***
***					纯练习代码,加了个并没有什么卵用的队列		***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"


int expression(char input[]);//表达式合法性判断
void nifixTOpostfix(const char *input, char *output);//中缀转后缀，默认字符串长度小于1024


int main(int argc, char *argv[])
{
	for (char choice = 'y';choice == 'y';system("cls"))
	{
		char input[1024] = "", output[1024] = "";
		fprintf(stdout, "请输入中缀表达式:\n");
		fgets(input, 1024, stdin);
		if (expression(input))
		{
			nifixTOpostfix(input, output);
			int count = 0;
			Tree root, lchild, rchild, rootStack[1024];
			for (int i = 0, num = 0;output[i] != '\0';++i)
			{
				if (output[i] == ' ')
					continue;
				if ('0' <= output[i] && '9' >= output[i])
				{
					for (;'0' <= output[i] && '9' >= output[i];++i)
						num = num * 10 + output[i] - '0';
					root = treeInit(treeCreat(), NUMTYPE, &num);
					rootStack[count++] = root;
					num = 0;
				}
				if (output[i] == '+' || output[i] == '-' || output[i] == '*' || output[i] == '/')
				{
					num = output[i];
					root = treeInit(treeCreat(), SIGNTYPE, &num);
					rchild = rootStack[--count];
					lchild = rootStack[--count];
					rootStack[count++] = treeMerge(root, lchild, rchild);
					num = 0;
				}
			}
			fprintf(stdout, "前缀表达式:");
			treeFirstOrder(root);fputc('\n', stdout);
			fprintf(stdout, "后缀表达式:");
			treePostOrder(root);fputc('\n', stdout);
			treeDestroy(root);
		}
		else
		{
			fprintf(stderr, "表达式输入错误\n");
		}
		for (ungetc('\0', stdin);(choice = fgetc(stdin)) != 'y'&&choice != 'n';)
			fprintf(stdout, "输入y继续,输入n退出\n");
		for (int clearbuf;(clearbuf = fgetc(stdin)) != '\n'&&clearbuf != EOF;);
	}

	return 0;
}


//表达式合法性判断
int expression(char input[])
{
	char except = 'n';//表示是不是错误表达式,是则为y否则为n
	int lbracket = 0, rbracket = 0, sign = 0, before = 0;//左右括号数,符号数量,前一位的字符
	for (int i = 0;input[i] != '\n'&&except != 'y'&&i < 1024;before = input[i++])
	{
		if ('0' <= input[i] && '9' >= input[i])
			continue;
		switch (input[i])
		{
		case '(':++lbracket;break;
		case ')':++rbracket;break;
		case '*':
		case '/':
		case '+':
		case '-':
			++sign;
			if (before == '+' || before == '-' || before == '*' || before == '/')//前一个和现在的字符均为符号
			{
				if (input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '*' || input[i + 1] == '/')//连续三个符号
				{
					except = 'y';break;
				}
				if (input[i] == '*' || input[i] == '/' || input[i] == ')')//?*或?/的情况
				{
					except = 'y';break;
				}
				if (before == '-'&&input[i] == '-')
				{
					input[i - 1] = ' ';
					input[i] = '+';
					break;
				}
				if (before == '+'&&input[i] == '-')
					input[i - 1] = ' ';
				if (input[i] == '+')
					input[i] = ' ';
			}
			break;
		default:except = 'y';break;
		}
	}
	if (except != 'y' && (input[0] == '*' || input[0] == '/' || before == '+' || before == '-' || before == '*' || before == '/' || lbracket != rbracket || sign == 0))
	{
		except = 'y';
	}
	return except == 'n';
}


void nifixTOpostfix(const char *input, char *output)//中缀转后缀，默认字符串长度小于1024
{
	Stack symbol;//符号栈
	int i = 0, j = 0;//下标
	char before = '+';
	symbol = stackCreate();
	symbol = stackInit(symbol);
	for (i = 0, j = 0;input[i] != '\n';before = input[i++])
	{
		if ((before == '+' || before == '-' || before == '*' || before == '/' || before == '(') && input[i] == '-')
		{
			output[j++] = input[i];
			continue;
		}
		if (('0' <= before&&'9' >= before) && !('0' <= input[i] && '9' >= input[i]))
			output[j++] = ' ';
		switch (input[i])
		{
		default://数字,输出
			output[j++] = input[i];
			break;
		case ' ':break;

		case '('://左括号和乘除号,入栈
		case '*':
		case '/':
			stackPush(symbol, input[i]);
			break;

		case '+'://加减,判断栈顶有没有优先级更高的运算符,有则弹出再入栈,没有则直接入栈
		case '-':
			if (stackGetTop(symbol) == '*' || stackGetTop(symbol) == '/')
			{
				for (; !stackEmpty(symbol) && stackGetTop(symbol) != '(';)
					output[j++] = stackPop(symbol);
			}
			stackPush(symbol, input[i]);
			break;

		case ')'://若有右括号,则弹出直到遇见左括号
			for (;stackGetTop(symbol) != '(';)
				output[j++] = stackPop(symbol);
			stackPop(symbol);//丢弃左括号
			break;
		}
	}
	for (;!stackEmpty(symbol) && stackGetTop(symbol) != '(';)//将栈中剩下的运算符输出
		output[j++] = stackPop(symbol);
	output[++j] = '\0';
	stackDestroy(symbol);//销毁栈
}
