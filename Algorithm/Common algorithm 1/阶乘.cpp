#include"iostream"
using namespace std;

int find(int n)
{
	if(n==1) return 1;
	else return find(n-1)*n;
}

int main()
{
	int n,mul=1;
	cout<<"求阶乘，请输入一个正整数:";
	cin>>n;
	cout<<"递归求"<<n<<"的阶乘为:"<<find(n)<<endl;

	for(int i=1;i<=n;i++)
		mul*=i;
	cout<<"循环求"<<n<<"的阶乘为:"<<mul<<endl;

	system("pause");
	return 0;
}