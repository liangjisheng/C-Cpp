#include"iostream"
using namespace std;
int p1=2,p2=10;
int max(int a,int b)
{return a>b?a:b;}
int volume(int l=1,int w=p1+p2,int h=max(p1,p2))
{return l*w*h;}
int main()
{
	cout<<"v0="<<volume()<<endl;
	cout<<"v1="<<volume(5)<<endl;
	cout<<"v2="<<volume(5,10)<<endl;
	cout<<"v3="<<volume(5,10,15)<<endl;
	return 0;
}