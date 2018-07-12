#include"iostream"
using namespace std;
int main()
{
	int a,b,c,d,e,t;
	cout<<"input the a、b、c、d、e:";
	cin>>a>>b>>c>>d>>e;
	if(a>b)t=a,a=b,b=t;
	if(a>c)t=a,a=c,c=t;
	if(a>d)t=a,a=d,d=t;
	if(a>e)t=a,a=e,e=t;
	if(b>c)t=b,b=c,c=t;
	if(b>d)t=b,b=d,d=t;
	if(b>e)t=b,b=e,e=t;
	if(c>d)t=c,c=d,d=t;
	if(c>e)t=c,c=e,e=t;
	if(d>e)t=d,d=e,e=t;
	cout<<a<<","<<b<<","<<c<<","<<d<<","<<e<<endl;
	return 0;
}