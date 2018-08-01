#include"stdafx.h"
#include"iostream"
#include"omp.h"
using namespace std;

int main()
{
	// 用pragma指令指明这是一个可以并行的for循环
	// 编译器会根据这些指令自动创建进程
	// 对for循环进行相应的并行处理
	#pragma omp parallel for
	for(int i=0;i<10;i++)
		cout<<i<<endl;

	system("pause");
	return 0;
}
