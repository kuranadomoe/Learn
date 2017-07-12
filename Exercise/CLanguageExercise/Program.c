#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int div(int a, int b);


int main(int argc, char*argv[])
{
	int a = 0, b = 0;
	fscanf(stdin, "%d %d", &a, &b);
	fprintf(stdout, "%d + %d = %d\n", a, b, add(a, b));
	fprintf(stdout, "%d - %d = %d\n", a, b, sub(a, b));
	system("pause");
	return 0;
}


int add(int a, int b)
{
	int result = a, carry = b;
	for (int temp = result;carry;)
	{
		result ^= carry;
		carry = (temp&carry) << 1;
		temp = result;
	}
	return result;
}


int sub(int a, int b)
{
	int result = a, carry = b;
	for (;carry;)
	{
		result ^= carry;
		carry = (result&carry) << 1;
	}
	return result;
}


int mult(int a, int b)
{
	int result = 0;

	return result;
}


int div(int a, int b)
{
	int result = 0;
	for (;;)
	{
	}
	return result;
}
