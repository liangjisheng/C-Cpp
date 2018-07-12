#include"iostream"
using namespace std;
int max(int a,int b)
{return a>b?a:b;}
int sum(int a,int b)
{return a+b;}
int mul(int a,int b)
{return a*b;}
int operate(int a,int b,int(*fun)(int m,int n))
{return fun(a,b);}
int main()
{
	int(*fun)(int m,int n);
	int a,b;
	cout<<"input a,b:";cin>>a>>b;
	fun=max;
	cout<<"max="<<operate(a,b,fun)<<endl;
	fun=sum;
	cout<<"sum="<<operate(a,b,fun)<<endl;
	fun=mul;
	cout<<"mul="<<operate(a,b,fun)<<endl;
	return 0;
}