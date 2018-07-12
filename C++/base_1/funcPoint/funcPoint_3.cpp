
#include <stdio.h>

static void func1(int nNum);
static void func2(int nNum);
static void func3(int nNum);
typedef void (*FuncType)(int);
static void CallFunc(FuncType fp, int nNum);

void test3()
{
	int nNum = 10;
	CallFunc(func1, nNum);
	CallFunc(func2, nNum);
	CallFunc(func3, nNum);

	printf("\n");
}

static void CallFunc(FuncType fp, int nNum) { fp(nNum); }

static void func1(int nNum) { printf("%d\n", nNum + 1); }

static void func2(int nNum) { printf("%d\n", nNum + 2); }

static void func3(int nNum) { printf("%d\n", nNum + 3); }
