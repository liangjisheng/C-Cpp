// 并行运算
// 使用PPL进行多线程开发 parallel patterns library
#include"iostream"
#include"ppl.h"		// PPL所在头文件
using namespace std;
using namespace Concurrency; // PPL所在的名字空间

int main()
{
	int i,j;
	parallel_invoke(
		[=]{for(i=0;i<100;i++) cout<<i<<endl; }		// Thread1
		[=]{for(j=0;j<10;j++) cout<<' '<<j<<endl; }	// Thread2
		);

	system("pause");
	return 0;
}
