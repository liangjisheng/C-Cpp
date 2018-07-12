// void (*f)() 函数指针
// void* f() 函数返回指针
// const int* //const指针
// int* const 指向const的指针
// const int* const 指向const的const的指针

#include"cstdio"
#include"iostream"

int max(int x,int y) { return x>y?x:y; }

int main()
{
	// int max(int,int);
	int (*p)(int,int)=&max;
	int a,b,c,d;
	printf("Please input three integer:");
	scanf("%d%d%d",&a,&b,&c);
	d=(*p)((*p)(a,b),c);
	printf("Among %d,%d,and %d,the maxmal integer is %d\n",
		a,b,c,d);

	system("pause");
	return 0;
}