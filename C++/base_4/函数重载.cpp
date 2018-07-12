#include"iostream"

using namespace std;

int max(int a,int b) {return a>b?a:b;}

double max(double a,double b) {return a>b?a:b;}

long max(long a,long b) {return a>b?a:b;}

int main()
{
	int i=12,j=-12,k;
	k=max(i,j);
	cout<<"int max="<<k<<endl;
	double x=123.4,y=65.43,z;
	z=max(x,y);
	cout<<"double max="<<z<<endl;
	long a=7654321,b=1234567,c;
	c=max(a,b);
	cout<<"long max="<<c<<endl;
	return 0;
}

#include"iostream"
using namespace std;
int max(int a,int b)
{return a>b?a:b;}
int max(int a,int b,int c)
{
	a=a>b?a:b;
	a=a>c?a:c;
	return a;
}
int main()
{
	int a,b,i=10,j=8,k=12;
	a=max(i,j);
	cout<<"max(i,j)="<<a<<endl;
	b=max(i,j,k);
	cout<<"max(i,j,k)="<<b<<endl;
	return 0;
}