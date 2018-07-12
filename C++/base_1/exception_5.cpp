// 540.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"tchar.h"

int _tmain(int argc, TCHAR* argv[],TCHAR* envp[])
{
	printf("Hello World!\n");

	try{
		throw 4.0;
		printf("正常执行\n");
	}
	catch(const char* s){
		printf("%s\n",s);
		printf("异常类型:const char*\n");
	}
	catch(int i){
		printf("i=%d\n",i);
		printf("异常类型:int\n");
	}
	catch(double x){
		printf("x=%lf\n",x);
		printf("异常类型:double\n");
	}
	return 0;
}

