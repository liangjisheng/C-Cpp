#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"math.h"

/*int main() {
	printf("Calling abort()\n");
	abort();
	// 从此行下面的代码永远不会被执行，
	// 因为abort函数终止了这个程序
	printf("is the program be held?\n");

	return 0;
}*/

/*void fun1(void)
{ printf("Exit function #1 called\n"); }
void fun2(void)
{ printf("Exit function #2 called\n"); }
int main() {
	// int atexit(void *func)
	// 注册终止函数。其中参数func为指向函数的指针。
	// 在程序正常终止时，系统会调用注册了的func函数
	atexit(fun1);
	atexit(fun2);

	return 0;
}*/

/*int CMP(int *a,int *b) {
	if(*a<*b) return -1;
	else if(*a>*b) return 1;
	else return 0;
}

int main() {
	// 二分查找 void bsearch(const void *key,const void *baser,
	//						size_t *nelem,size_t width,
	//						int(*fcmp)(const void*,const void*))
	// #include"stdlib.h"
	int search[]={1,3,6,7,10,11,13,19,28,56};
	int a=13,*p,i;
	p=(int*)bsearch(&a,search,10,sizeof(int),CMP);
	printf("The elems of the array are:\n");
	for(i=0;i<10;i++)
		printf("%d ",search[i]);
	if(p)
		printf("\nThe elem 13 is located at %d of array\n",p-search+1);
	else printf("\nSearch is failed\n");
	return 0;
}*/

/*int main() {
	int i,j,*p=NULL;
	printf("Please enter the size for allocation:\n");
	scanf("%d",&i);
	p=(int*)calloc(i,sizeof(int));
	if(p) {
		printf("Please enter %d datas:\n",i);
		for(j=0;j<i;j++)
			scanf("%d",&p[j]);
	}
	else { printf("Allocation is failed\n"); return 0; }
	printf("The datas are:\n");
	for(j=0;j<i;j++)
		printf("%d ",p[j]);
	printf("\n");
	free(p);
	return 0;
}*/

// exit() 正常终止一个程序

/*int main() {
	// char* getenv(char *envvar) 获取环境变量
	char *s;
	s=getenv("COMSPEC");
	printf("Command processor:%s\n",s);

	return 0;
}*/

int main() {
	// void* realloc(void* ptr,unsigned newsize)
	int *sqlist,i,len;
	len=10;
	sqlist=(int*)malloc(len*sizeof(int));
	for(i=0;i<20;i++) {
		if(i>=len) {
			len*=2;
			sqlist=(int*)realloc(sqlist,len*sizeof(int));
		}
		sqlist[i]=i;
	}
	for(i=0;i<20;i++)
		printf("%d ",sqlist[i]);
	printf("\n");
	return 0;
}