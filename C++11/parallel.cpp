// ��������
// ʹ��PPL���ж��߳̿��� parallel patterns library
#include"iostream"
#include"ppl.h"		// PPL����ͷ�ļ�
using namespace std;
using namespace Concurrency; // PPL���ڵ����ֿռ�

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
