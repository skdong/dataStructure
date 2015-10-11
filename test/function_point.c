#include<stdio.h>

#define NOERR 0
#define ERROR -1

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int (*func)(int,int);
	int a,b;
	func = max;
	a = 2;
	b = 3;
	printf("%d %d\n",(*func)(a,b),(*func)(b,a));
	return NOERR;
}
