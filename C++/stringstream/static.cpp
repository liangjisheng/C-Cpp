#include"iostream"
using namespace std;

int sum(int a)
{
	auto int c=0;
	static int b=3;
	c+=1;
	b+=2;
	return (a+b+c);
}

int main()
{
	int i,a=2;
	for(i=0;i<5;i++)
		cout<<sum(a)<<' ';
	cout<<endl;

	int arr[3];
	arr[0]=0; arr[1]=1; arr[2]=2;
	int *p,*q;
	p=arr;
	q=&arr[2];
	cout<<arr[q-p]<<endl;

	int **pa[3][4];		// 数组预分配内存空间
	cout<<sizeof(pa)<<endl;
	
	system("pause");
	return 0;
}