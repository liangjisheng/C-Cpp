#include"iostream"
using namespace std;

int f(int n) 
{
	if(n==1 || n==2) return 1;
	else return f(n-1)+f(n-2);
}

int main()
{
	int n;
	cout<<"求斐波那契数列，输入一个正整数:";
	cin>>n;
	cout<<"第"<<n<<"个斐波那契数为:"<<f(n)<<endl;

	system("pause");
	return 0;
}