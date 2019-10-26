#include "pch.h"
#include <stdio.h>
#define R 20
#define N(n) n*10
#define Add(e,f) e+f
int add(int a, int b)
{
	return a + b;
}

typedef int tni;

int main()
{
	tni a = R;
	printf("a=%d\n",a);
	printf("Hello World!\n");

	int b = N(a);
	printf("b=%d\n",b);
	int c=add(a,b);
	printf("c=%d\n", c);
	int s = Add(a, b);
	printf("s=%d", s);
	return 0;
}

