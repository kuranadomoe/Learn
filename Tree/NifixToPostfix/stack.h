/******************************************************************
***	File name:		stack.c										***
***	Description:	Stack ADT Statement							***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#pragma once
#ifndef STACK_H
#define STACK_H


typedef char StackElement;
typedef struct StackStruct
{
	int Capacity;//capacity of stack
	int TopOfStack;//top of stack
	StackElement *Array;//stack array
}*Stack;


Stack stackCreate(void);//Create a stack
Stack stackInit(Stack stack);//Stack Initialize
int stackEmpty(Stack stack);//Stack empty
int stackFull(Stack stack);//Stack full
int stackLength(Stack stack);//Stack length
int stackGetTop(Stack stack);//...get top element
int stackPush(Stack stack, StackElement elem);//push~~栈满返回-1，否则入栈并返回elem
int stackPop(Stack stack);//...pop~~~栈空返回-1,不空弹出栈顶元素
int stackDestroy(Stack stack);//stack destroy


#endif
