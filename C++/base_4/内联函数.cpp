内联函数是直接将被调函数的代码嵌入到主调函数中，虽然节省大量运行时间，但这增加了空间开销，是以空间换时间。
#include"iostream"
using namespace std;
inline int fun(int a,int b)
{
	return a*a+b*b;
}
int main()
{
	int m,n;
	cout<<"input m,n:";
	cin>>m>>n;
	cout<<"m*m+n*n="<<fun(m,n)<<endl;
	return 0;
}