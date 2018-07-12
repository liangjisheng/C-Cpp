#include"iostream"
#include"stdio.h"
using namespace std;

int main()
{
	static int a[2]={1,2};
	int* ptr[5];
	int p=5,p2=6,*page,*page2;
	int Test[2][3]={{1,2,3},{4,5,6}};
	int Test2[3]={1,2,3};
	page=&p;
	page2=&p2;

	ptr[0]=page;
	ptr[1]=page2;
	int (*A)[3],(*B)[3]; // 数组指针
	A=&Test[1];
	B=&Test2;
	cout<<*page<<endl;
	cout<<(*A)[0]<<' '<<(*A)[1]<<' '<<(*A)[2]<<endl;
	// Test和Test2分配内存的时候是连续分配的，所以下面0-8都可以
	for(int i=0;i<9;i++)
		cout<<(*B)[i]<<' ';
	cout<<endl;
	cout<<(*B)[9]<<endl; // 会输出不是想要的值

	system("pause");
	return 0;
}